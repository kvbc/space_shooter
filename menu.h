#pragma once
#include "board.h"
#include "sprite.h"
#include "options.h"


class Menu {
public:
	Menu()
		: m_open(true),
		  m_option(0),
		  m_op(*DEFAULT_OPTIONS),
		  m_title({{{ SPRITE_SPACESHOOTER }}, m_op}),
		  m_board(m_op) {}

	bool open() const;
	void update();
	void options();
	void start_game();

private:
	bool m_open;
	int m_option;
	Options m_op;

	Board m_board;
	Sprite m_title;
};