#include <windows.h>
#include "menu.h"
#include "game.h"
#include "math.h"

#define pressed(c) GetAsyncKeyState(c)


bool Menu::open() const {
	return m_open;
}


void Menu::update() {
 	Option BSIZE_X = value(m_op[OP_BSIZE_X]);
	Option BSIZE_Y = value(m_op[OP_BSIZE_Y]);


	m_title.write(m_board, { (BSIZE_X - SPACESHOOTER_SIZE_X) / 2, (BSIZE_Y - SPACESHOOTER_SIZE_Y) / 2 - 3});

	int cx = BSIZE_X / 2;
	int cy = BSIZE_Y / 2;

	m_board.write("Play",	 {cx, cy + 1}, true);
	m_board.write("Options", {cx, cy + 3}, true);
	m_board.write("Exit",	 {cx, cy + 5}, true);
	m_board.write('>', {cx - 6, cy + 1 + m_option * 2 });

	if (
		pressed(VK_DOWN) ||
		pressed('s')	 ||
		pressed('S')
	)
		m_option = clamp(m_option + 1, 0, 2);
	else if (
		pressed(VK_UP) ||
		pressed('w')   ||
		pressed('W')
	)
		m_option = clamp(m_option - 1, 0, 2);
	else if (
		pressed(VK_SPACE) ||
		pressed(VK_RETURN)
	) {
		m_open = false;
		throw m_option;
	}

	m_board.display();
	m_board.clear(true);
}


void Menu::start_game() {
	Option BSIZE_X = value(m_op[OP_BSIZE_X]);
	Option BSIZE_Y = value(m_op[OP_BSIZE_Y]);
	Option PHEALTH = value(m_op[OP_PHEALTH]);
	Option PDAMAGE = value(m_op[OP_PDAMAGE]);
	Option FPS = value(m_op[OP_FPS]);


	Entity plr = {
		{{ SPRITE_PLAYER }, m_op},
		{PLAYER_SIZE_X, PLAYER_SIZE_Y},
		PHEALTH,
		PDAMAGE,
		m_op
	};

	plr.setpos({
		(BSIZE_X - PLAYER_SIZE_X) / 2,
		BSIZE_Y - PLAYER_SIZE_Y
	});

	Game game(plr, m_op);
	while(true) {
		try {
			game.update();
		}
		catch(int option) { switch(option) {
			// Lose / Won
			case 0:
				Sleep(3000);
				cmd::clear();
				m_open = true;
				return;
		}}

		Sleep(1000 / FPS);
		cmd::clear();
	}
}