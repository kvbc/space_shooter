#include "board.h"
#include "game.h"
#include "particles.h"
#include "math.h"


int Board::size() const {
	return m_data.size();
}


// Checks if the given position
// is inside the board
bool Board::inside(const Vector2 &pos) const {
	Option BSIZE_X = value(m_op[OP_BSIZE_X]);
	Option BSIZE_Y = value(m_op[OP_BSIZE_Y]);

	int x = pos.x;
	int y = pos.y;

	return
		x >= 0		&&
		x < BSIZE_X &&
		y >= 0		&&
		y < BSIZE_X;
}


// Write a character into the board
void Board::write(char c, const Vector2 &pos) {
	if(inside(pos))
	m_data[pos.y][pos.x] = c;
}


// Write a number into the board
// with len being the length of a number
void Board::write(int num, int len, const Vector2 &pos, bool center) {
	Option BSIZE_X = value(m_op[OP_BSIZE_X]);

	int x = pos.x;
	int y = pos.y;

	if (
		!inside(pos) ||
		x - (len -= center * len / 2) < 0
	) return;

	while(num > 0) {
		m_data[y][x + len--] = (num % 10) + '0';
		num /= 10;
	}
}


// Write a number into the board
// and calculate the length of it
void Board::write(int num, const Vector2 &pos, bool center) {
	write(num, numlen(num), pos, center);
}


// Write a string into the board
void Board::write(const char* const str, const Vector2 &pos, bool center) {
	Option BSIZE_X = value(m_op[OP_BSIZE_X]);
	Option BSIZE_Y = value(m_op[OP_BSIZE_Y]);

	int x = pos.x;
	int y = pos.y;
	int len = strlen(str);

	if (
		!inside(pos) ||
		(x -= center * len / 2) < 0
	)
		return;

	for (
		int ix = 0;
		ix < len;
		x++, ix++
	) {
		char &cell = m_data[y][x];
		char n_cell = str[ix];
		if (
			cell == EMPTY &&
			n_cell != EMPTY
		)
			cell = n_cell;
	}
}


// Get the enemy from the bullet that it has just fired
Entity* const Board::getEnemy(Game* const game, const Vector2 &pos) {
	int x = pos.x;
	int y = pos.y;
	while(y > 0) {
		char cell = m_data[y][x];
		if (
			cell != UBULLET_CHAR &&
			cell != DBULLET_CHAR &&
			cell != EMPTY
		) {
			Entity *enemy = game->m_enemies.get({x, y});
			if(enemy != NULL)
				return enemy;
		}
		y--;
	}
	return NULL;
}


// Display the board
void Board::display() const {
	int sy = m_data.size();
	for(int y = 0; y < sy; y++) {
		int sx = m_data[y].size();
		for(int x = 0; x < sx; x++)
			std::cout << m_data[y][x];
		std::cout << '\n';
	}
}


// Display the board + update the bullets
void Board::display(Game* const game) {
	Option EDAMAGE = value(m_op[OP_EDAMAGE]);

	int sy = m_data.size();
	for(int y = 0; y < sy; y++) {
		int sx = m_data[y].size();

		for(int x = 0; x < sx; x++) {
			char &cell = m_data[y][x];
			std::cout << cell;
			
			// Update upward bullets
			if(cell == UBULLET_CHAR) {
				cell = EMPTY;
				if(y > UBULLET_OFFSET) {
					char &n_cell = m_data[y - 1][x];

					if(n_cell == DBULLET_CHAR)
						n_cell = EMPTY;
					else if (
						n_cell == EMPTY ||
						n_cell == 'X'
					)
						n_cell = UBULLET_CHAR;
					else {
						// Attack the enemy
						Entity* const enemy = game->m_enemies.get({x, y});
						if(enemy != NULL) {
							game->m_plr.attack(*enemy);

							const Particle *explosion = &particle::explosion;
							if(enemy->health() <= 0)
								explosion = &particle::big_explosion;

							Particle* const particle = new Particle(*explosion);
							particle->play(game, {x, y}, true);
						}
					}
				}
			}
		}

		for(int x = sx - 1; x >= 0; x--) {
			int by = sy - y - 1;
			char &cell = m_data[by][x];

			// Update downward bullets
			if(cell == DBULLET_CHAR) {
				cell = EMPTY;
				if(by + 1 < sy - DBULLET_OFFSET) {
					char &n_cell = m_data[by + 1][x];

					if(n_cell == UBULLET_CHAR)
						n_cell = EMPTY;
					else if (
						n_cell == EMPTY ||
						n_cell == 'X'
					)
						n_cell = DBULLET_CHAR;
					else if(game->m_plr.inside({x, by + 1})) {
						// Attack the player
						game->m_plr.m_health -= EDAMAGE;

						const Particle *explosion = &particle::explosion;
						if(game->m_plr.m_health <= 0)
							explosion = &particle::big_explosion;

						Particle* const particle = new Particle(*explosion);
						particle->play(game, {x, by + 1}, true);
					}
				}
			}
		}

		std::cout << '\n';
	}
}


// Clear the board
void Board::clear(bool clearBullets) {
	int sy = m_data.size();
	for(int y = 0; y < sy; y++) {
		int sx = m_data[y].size();
		for(int x = 0; x < sx; x++) {
			char &cell = m_data[y][x];
			if (
				clearBullets ||
				(cell != UBULLET_CHAR &&
				 cell != DBULLET_CHAR)
			)
				cell = EMPTY;
		}
	}
}