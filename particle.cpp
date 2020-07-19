#include "particle.h"
#include "game.h"


// Write a frame of the particle into the board
void Particle::write(Board &board, const Vector2 &pos) {
	Sprite &frame = m_frames[0];
	frame.write(board, {
			m_center ? (pos.x - m_size.x / 2) : pos.x,
			m_center ? (pos.y - m_size.y / 2) : pos.y
		});
	m_frames.erase(m_frames.begin());
}


// Render the first frame and
// initialize the particle so it's ready for rendering next frames
void Particle::play(Game* const game, const Vector2 &pos, bool center) {
	m_pos = pos;
	m_center = center;
	game->m_particles.push_back(this);
	write(game->m_board, pos);
}


// Go to the next frame of the particle and render it
void Particle::update(Game* const game) {
	if(m_frames.size() > 0) {
		if(game->m_frame % m_speed == 0)
			write(game->m_board, m_pos);
	}
	else {
		particle_cont &particles = game->m_particles;
		particles.erase(particles.begin());
	}
}