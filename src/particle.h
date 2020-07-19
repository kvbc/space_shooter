#pragma once
#include "core.h"

class Game;
class Board;
class Sprite;

typedef std::vector<Sprite> frame_cont;


class Particle {
public:
	Particle(const frame_cont &frames, const Vector2 &size, unsigned int speed)
		: m_frames(frames),
		  m_size(size),
		  m_speed(speed) {}

	void write(Board &board, const Vector2 &pos);
	void play(Game* const game, const Vector2 &pos, bool center = false);
	void update(Game* const game);

private:
	Vector2 m_pos;
	Vector2 m_size;
	unsigned int m_speed;

	bool m_center;
	frame_cont m_frames;
};