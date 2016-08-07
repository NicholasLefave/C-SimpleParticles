#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"
namespace SDLSkeleton{
	class Swarm {
	private:
		Particle *m_pParticles;
		int lastTimeTick;
	public:
		const static int NPARTICLES = 5000;
		Swarm();
		const Particle * getParticles(){return m_pParticles;}
		void update(int elapsed);
		virtual ~Swarm();
	};

}
#endif /*SWARM_H*/ 