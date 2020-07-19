#include "sprite.h"
#include "board.h"


int Sprite::size() const {
	return m_size;
}


// Write a sprite into the board
void Sprite::write(Board &board, const Vector2 &pos) const {
	if(!board.inside(pos))
		return;

	Option BSIZE_Y = value(m_op[OP_BSIZE_Y]);

	int x = pos.x;
	int y = pos.y;

	for (
		int iy = 0;
		iy < m_size && iy < BSIZE_Y && y < BSIZE_Y;
		iy++, y++
	)
		board.write(m_data[iy].c_str(), {x, y});
}