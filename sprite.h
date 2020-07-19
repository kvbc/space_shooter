#pragma once
#include "core.h"
#include "options.h"

class Board;


class Sprite {
public:
	Sprite(const sprite_cont &data, const Options &options = *DEFAULT_OPTIONS)
		: m_data(data),
		  m_size(data.size()),
		  m_op(options) {}

	int size() const;
	void write(Board &board, const Vector2 &pos) const;

private:
	int m_size;
	sprite_cont m_data;

	Options m_op;
};