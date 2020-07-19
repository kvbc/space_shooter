#include "entity.h"
#include "board.h"
#include "game.h"
#include "math.h"


int Entity::health() const {
	return m_health;
}


Vector2 Entity::pos() const {
	return m_pos;
}


Vector2 Entity::size() const {
	return m_size;
}


void Entity::setpos(const Vector2 &pos) {
	m_pos = pos;
}


// Move the entity by x and y
// If the clamp is true - the entity cannot 'escape' the cmd,
// otherwise its free to go out of the screen
void Entity::move(const Vector2 &pos, bool clamp) {
	Option BSIZE_X = value(m_op[OP_BSIZE_X]);
	Option BSIZE_Y = value(m_op[OP_BSIZE_Y]);

	int new_x = m_pos.x + pos.x;
	int new_y = m_pos.y - pos.y;
	
	if (
		!clamp ||
		(new_x >= 0 &&
		 new_x < BSIZE_X - m_size.x)
	) m_pos.x = new_x;

	if (
		!clamp ||
		(new_y >= 0 &&
		 new_y < BSIZE_Y - m_size.y)
	) m_pos.y = new_y;
}


// Check if the given position is inside the entity
bool Entity::inside(const Vector2 &pos) const {
	int px = m_pos.x;
	int py = m_pos.y;
	int sx = m_size.x;
	int sy = m_size.y;

	int x = pos.x;
	int y = pos.y;

	return
		x >= px		 &&
		x <= px + sx     &&
		y >= py		 &&
		y <= py + sy;
}


// Attack the other entity by subtracting it's damage
// from the other entity's health
void Entity::attack(Entity &entity) const {
	entity.m_health -= m_damage;
}


// Fire a bullet going at the y_dir direction
void Entity::fire(Board &board, int y_dir) const {
	// if(!board.inside(m_pos)) return;

	Option BSIZE_X = value(m_op[OP_BSIZE_X]);
	Option BSIZE_Y = value(m_op[OP_BSIZE_Y]);

	int px = m_pos.x;
	int py = m_pos.y;
	int sx = m_size.x;
	int sy = m_size.y;

	switch(y_dir) {
		case UBULLET: board[py - 1][px + sx / 2]  = UBULLET_CHAR; return;
		case DBULLET: board[py + sy][px + sx / 2] = DBULLET_CHAR; return;
	}
}


// Display the entity by writing
// it's sprite into the board
void Entity::display(Board &board) const {
	m_sprite.write(board, m_pos);
}


// Display entity's health in the following way:
// health (sep = "/") max_health
void Entity::display_health(Board &board, const Vector2 &pos, const char* const sep) const {
	if(m_health <= 0) return;

	int y = pos.y;
	int x = pos.x;

	int hlen = numlen(m_health);
	int mhlen = numlen(m_max_health);

	board.write(m_health, hlen, {x, y});
	board.write(sep, {x + hlen + 1, y});
	board.write(m_max_health, mhlen, {x + hlen + 3, y});
}


// Display entity's healthbar
void Entity::display_healthbar(Board &board, const Vector2 &pos, int bars) const {
	if(m_health <= 0) return;

	int x = pos.x;
	int y = pos.y;

	for (int i = 0; i < bars; i++)
		if(m_health >= (m_max_health / bars) * (i + 1))
			board[y][x + i] = HBAR_CHAR;
}
