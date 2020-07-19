#pragma once
#include "board.h"
#include "entity.h"
#include "ent_cont.h"
#include "particle.h"
#include "options.h"

typedef std::vector<Particle*> particle_cont;


class Game {
	friend class Board;
	friend class Entity;
	friend class Particle;

public:
	Game(const Entity &plr, const Options &options)
		: m_plr(plr),
		  m_frame(1),
		  m_running(true),
		  m_board(options),
		  m_op(options) {
			UOption ENEMIES = Uvalue(m_op[OP_ENEMIES]);

			m_enemies = {ENEMIES, {
				{{ SPRITE_ENEMY }, options},
				{ENEMY_SIZE_X, ENEMY_SIZE_Y},
				value(m_op[OP_EHEALTH]),
				value(m_op[OP_EDAMAGE]),
				options
			}};

			int offset = value(m_op[OP_BSIZE_X]) / ENEMIES;
			for(int i = 0; i < ENEMIES; i++) {
				Entity &enemy = m_enemies[i];
				enemy.setpos({
					offset * i + offset / 2 - ENEMY_SIZE_X / 2 - 1,
					ENEMY_POS_Y
				});
			}
		}
	
	void update();

private:
	Entity m_plr;
	entity_cont m_enemies;
	particle_cont m_particles;

	Board m_board;
	Options m_op;

	bool m_running;
	unsigned int m_frame;
};