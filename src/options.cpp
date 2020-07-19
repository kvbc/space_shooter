#include "options.h"
#include "menu.h"
#include "math.h"

#define pressed(c) GetAsyncKeyState(c)


COption Cvalue(const std::pair<int, std::vector<unsigned int>> &option) {
	return option.second[option.first];
}

Option& value(const std::pair<int, std::vector<unsigned int>> &option) {
	return option.second[option.first];
}

UOption& Uvalue(const std::pair<int, std::vector<unsigned int>> &option) {
	return option.second[option.first];
}


static void nextOption(std::pair<int, std::vector<unsigned int>> &option, int next) {
	auto &first = option.first;
	first = clamp(first + next, 0, option.second.size() - 1);
}


static void writeOption(const char* const name, const Vector2 &npos, const std::pair<int, std::vector<unsigned int>> &option, const Vector2 &vpos, Board &board) {
	board.write(name, npos);
	board.write(option.second[option.first], vpos, true);
}


void Menu::options() {
	m_option = 0;

	COption BSIZE_X = value(m_op[OP_BSIZE_X]);
	COption BSIZE_Y = value(m_op[OP_BSIZE_Y]);

	Option OPTION_NAME_POS_X = 3;
	Option OPTION_VALUE_POS_X = BSIZE_X - 8;

	Option OP_BACK_POS_X = BSIZE_X / 2;
	Option OP_BACK_POS_Y = BSIZE_Y - 1;

	Option FPS = value(m_op[OP_FPS]);

	while(true) {
		writeOption("FPS",			   {OPTION_NAME_POS_X, 1},  m_op[0], {OPTION_VALUE_POS_X, 1},  m_board);
		writeOption("Board Width",	   {OPTION_NAME_POS_X, 3},  m_op[1], {OPTION_VALUE_POS_X, 3},  m_board);
		writeOption("Board Height",	   {OPTION_NAME_POS_X, 5},  m_op[2], {OPTION_VALUE_POS_X, 5},  m_board);
		writeOption("Player's Health", {OPTION_NAME_POS_X, 7},  m_op[3], {OPTION_VALUE_POS_X, 7},  m_board);
		writeOption("Player's Damage", {OPTION_NAME_POS_X, 9},  m_op[4], {OPTION_VALUE_POS_X, 9},  m_board);
		writeOption("Player's Speed",  {OPTION_NAME_POS_X, 11}, m_op[5], {OPTION_VALUE_POS_X, 11}, m_board);
		writeOption("Enemies",		   {OPTION_NAME_POS_X, 13}, m_op[6], {OPTION_VALUE_POS_X, 13}, m_board);
		writeOption("Enemy's Health",  {OPTION_NAME_POS_X, 15}, m_op[7], {OPTION_VALUE_POS_X, 15}, m_board);
		writeOption("Enemy's Damage",  {OPTION_NAME_POS_X, 17}, m_op[8], {OPTION_VALUE_POS_X, 17}, m_board);
		m_board.write("BACK", {OP_BACK_POS_X, OP_BACK_POS_Y}, true);

		if(m_option == OP_BACK)
			m_board.write('>', {OP_BACK_POS_X - 4, OP_BACK_POS_Y});
		else if(m_option >= 0)
			m_board.write('>', {1, 1 + m_option * 2});

		if (
			pressed(VK_DOWN) ||
			pressed('s')	 ||
			pressed('S')
		)
			m_option = clamp(m_option + 1, 0, OPTIONS - 1);
		else if (
			pressed(VK_UP) ||
			pressed('w')   ||
			pressed('W')
		)
			m_option = clamp(m_option - 1, 0, OPTIONS - 1);
		else if (
			NOT_BACK m_option &&
			(pressed(VK_LEFT) ||
			 pressed('a')     ||
			 pressed('A'))
		)
			nextOption(m_op[m_option], -1);
		else if (
			NOT_BACK m_option  &&
			(pressed(VK_RIGHT) ||
			 pressed('d')	   ||
			 pressed('D'))
		)
			nextOption(m_op[m_option], 1);
		else if (
			IS_BACK m_option  &&
			pressed(VK_SPACE) ||
			pressed(VK_RETURN)
		) {
			m_option = 0;
			m_open = true;
			break;
		}

		m_board.display();
		m_board.clear(true);

		Sleep(1);
		cmd::clear();
	}

	BSIZE_X = value(m_op[OP_BSIZE_X]);
	BSIZE_Y = value(m_op[OP_BSIZE_Y]);

	m_board = { m_op };
	
	cmd::setWindowSize (
		(BSIZE_X + 1) * 11.3666666667f,
		BSIZE_Y * 26.52f
	);
	cmd::hideCursor();
}