#pragma once
#include "sprite.h"

class Game;


class Entity {
	friend class Board;

public:
	Entity(const Sprite &sprite, const Vector2 &size, int health, int damage, const Options &options)
		: m_sprite(sprite),
		  m_size(size),
		  m_health(health),
		  m_max_health(health),
		  m_damage(damage),
		  m_op(options) {}

	int health() const;
	Vector2 pos() const;
	Vector2 size() const;

	void setpos(const Vector2 &pos);
	void move(const Vector2 &pos, bool clamp = true);
	bool inside(const Vector2 &pos) const;
	void attack(Entity &entity) const;
	void fire(Board &board, int y_dir) const;
	void display(Board &board) const;
	void display_health(Board &board, const Vector2 &pos, const char* const sep = " / ") const;
	void display_healthbar(Board &board, const Vector2 &pos, int bars) const;

private:
	Vector2 m_size;
	Vector2 m_pos;
	Sprite m_sprite;

	int m_health;
	int m_max_health;
	int m_damage;

	Options m_op;
};