#include <iostream>
#include "ent_cont.h"
#include "entity.h"


iterator entity_cont::begin() {
	return m_data.begin();
}


iterator entity_cont::end() {
	return m_data.end();
}


int entity_cont::size() const {
	return m_data.size();
}


// Get the entity from an entity container
// by the position on the board
Entity* const entity_cont::get(const Vector2 &pos) {
	int x = pos.x;
	int y = pos.y;
	for(int i = 0; i < m_data.size(); i++) {
		Entity &entity = m_data[i];
		if(entity.inside({x, y}))
			return &entity;
	}
	return NULL;
}