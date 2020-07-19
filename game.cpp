#include <windows.h>
#include <thread>
#include "game.h"
#include "particles.h"
#include "math.h"

#define pressed(c) GetAsyncKeyState(c)


void Game::update() {
	Option BSIZE_X = value(m_op[OP_BSIZE_X]);
	Option BSIZE_Y = value(m_op[OP_BSIZE_Y]);
	Option PSPEED = value(m_op[OP_PSPEED]);


	if(m_plr.health() > 0) {
		m_plr.display_healthbar(m_board, {1, BSIZE_Y - 1}, PLAYER_HBARS);
		m_plr.display_health(m_board, {1 + PLAYER_HBARS, BSIZE_Y - 1});

		if(m_enemies.size() > 0)
			for(int i = 0; i < m_enemies.size(); i++) {
				Entity &enemy = m_enemies[i];
				if(enemy.health() > 0) {
					int _rand = rand();
					std::thread([&]() {
						enemy.display(m_board);

						if(m_frame % 20 == 0)
							enemy.move({1, 0});
						else if(m_frame % 10 == 0)
							enemy.move({-1, 0});

						if(m_frame % (_rand % ENEMY_FIRERATE + 1) == 0)
							enemy.fire(m_board, DBULLET);
					}).detach();
				}
				else
					m_enemies.m_data.erase(m_enemies.begin() + i);
			}
		else {
			m_board.clear(true);
			Sprite YouWon = {{{ SPRITE_YOUWON }}, m_op};
			YouWon.write(m_board, { (BSIZE_X - YOUWON_SIZE_X) / 2, (BSIZE_Y - YOUWON_SIZE_Y) / 2});
			m_board.display();
			throw 0;
		}
	}
	else {
		m_board.clear(true);
		Sprite GameOver = {{{ SPRITE_GAMEOVER }}, m_op};
		GameOver.write(m_board, { (BSIZE_X - GAMEOVER_SIZE_X) / 2, (BSIZE_Y - GAMEOVER_SIZE_Y) / 2});
		m_board.display();
		throw 0;
	}

	m_plr.display(m_board);

	for(Particle *particle : m_particles)
		particle->update(this);

	m_board.display(this);

	if (
		pressed(VK_LEFT) ||
		pressed('a')	 ||
		pressed('A')
	)
		m_plr.move({-PSPEED, 0});
	else if (
		pressed(VK_RIGHT) ||
		pressed('d')	  ||
		pressed('D')
	)
		m_plr.move({PSPEED, 0});

	if (
		(pressed(VK_UP) ||
		 pressed('w')   ||	
		 pressed('W')   ||
		 pressed(' '))  &&
		m_frame % PLAYER_FIRERATE == 0
	)
		m_plr.fire(m_board, UBULLET);

	m_board.clear();
	m_frame++;
}