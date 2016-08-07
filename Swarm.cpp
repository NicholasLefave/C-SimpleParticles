#include "Swarm.h"

namespace SDLSkeleton {
	Swarm::Swarm() :lastTimeTick(0){
		m_pParticles = new Particle[NPARTICLES];
	}
	Swarm::~Swarm() {
		delete [] m_pParticles;
	}
	void Swarm::update(int elapsed) {
		int interval = elapsed - lastTimeTick;
		for(int i =0; i <NPARTICLES;i++){
			m_pParticles[i].update(interval);
		}
		lastTimeTick=elapsed;
	}
}