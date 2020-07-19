#pragma once
#include "core.h"

class Entity;

typedef std::vector<Entity>::iterator iterator;


class entity_cont {
	friend class Game;

public:
	Entity& operator[] (int idx) {
		return m_data[idx];
	}

	void operator= (const std::vector<Entity> &data) {
		m_data = data;
	}

	iterator begin();
	iterator end();
	int size() const;
	Entity* const get(const Vector2 &pos);

private:
	std::vector<Entity> m_data;
};