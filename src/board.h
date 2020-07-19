#pragma once
#include <iostream>
#include "core.h"
#include "options.h"

class Game;
class Sprite;
class Entity;


class Board {
public:
	Board(const Options &options)
		: m_op(options),
		  m_data (
			  value(options[OP_BSIZE_Y]),
			  std::string(value(options[OP_BSIZE_X]), EMPTY)
		  ) {}

	Board(const sprite_cont &data, const Options &options)
		: m_data(data),
		  m_op(options) {}


	std::string& operator[] (int idx) {
		return m_data[idx];
	}


	int size() const;
	bool inside(const Vector2 &pos) const;

	void write(char c, const Vector2 &pos);
	void write(int num, int len, const Vector2 &pos, bool center = false);
	void write(int num, const Vector2 &pos, bool center = false);
	void write(const char* const str, const Vector2 &pos, bool center = false);
	Entity* const getEnemy(Game* const game, const Vector2 &pos);
	
	void display() const;
	void display(Game* const game);
	void clear(bool clearBullets = false);

private:
	sprite_cont m_data;
	Options m_op;
};