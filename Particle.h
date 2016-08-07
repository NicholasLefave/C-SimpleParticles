#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace SDLSkeleton{
	struct Particle {
		double m_x;
		double m_y;
		/*double m_xSpeed;
		double m_ySpeed;*/
	private:
		double m_speed;
		double m_direction;

	private:
		void init();
	public:
		Particle();
		virtual ~Particle();
		void update(int interval);
	};

}
#endif /*PARTICLE_H*/