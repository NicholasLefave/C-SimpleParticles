#include "Particle.h"
#include <stdlib.h>
#include <math.h>
namespace SDLSkeleton {
	Particle::Particle():m_x(0),m_y(0) {
	/*	m_x = ((2.0 * rand())/RAND_MAX) - 1;
		m_y = ((2.0 * rand())/RAND_MAX) - 1;*/

		/*m_xSpeed = 0.001*(((2.0*rand())/RAND_MAX)-1);
		m_ySpeed = 0.001*(((2.0*rand())/RAND_MAX)-1);*/
		init();
	}
	Particle::~Particle() {

	}
	void Particle::init()  {
		m_direction = (2* M_PI *rand())/RAND_MAX;
		m_speed = (0.04*rand())/RAND_MAX;

		m_speed *= m_speed;
	}
	void Particle::update(int interval) {
	/*	const double speed = 0.01;
		
		
		m_x += m_xSpeed;
		m_y += m_ySpeed;
		if(m_x < -1.0 ||m_x >= 1.0)	
			m_xSpeed=-m_xSpeed;
		if(m_y < -1.0 ||m_y >= 1.0)	
			m_ySpeed=-m_ySpeed;
	}*/
		double xSpeed = m_speed * cos(m_direction);
		double ySpeed = m_speed * sin(m_direction);
		m_direction += interval*0.0003;
		m_x += xSpeed*interval;
		m_y += ySpeed*interval;

		if(m_x < -1 || m_x > 1 ||m_y <-1 || m_y >1) {
			init();
		}
		if(rand() < RAND_MAX/100) {
			init();
		}
	}
	
}