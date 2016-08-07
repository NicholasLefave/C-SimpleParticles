#include "SDL.h" 
#include "Screen.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"
using namespace std;
using namespace SDLSkeleton;
const int middleWidth = Screen::SCREEN_WIDTH/2;
const int middleHeight = Screen::SCREEN_HEIGHT/2;
int main(int argc, char *argv[])
{ 
	srand(time(NULL));
	Screen screen;
	Swarm swarm;


	if(screen.init()==false)
		cout<<"Error initalising SDL"<<endl;
	while(true){
		
		int elapsedTime= SDL_GetTicks();
		//update particles
		swarm.update(elapsedTime);
		screen.boxBlur();
		const Particle * const pParticles = swarm.getParticles();
		for (int i =0;i<Swarm::NPARTICLES;i++){
			Particle particle = pParticles[i];
			
			int x = (particle.m_x+1)*middleWidth;
			int y = (particle.m_y*middleWidth+middleHeight);
			Uint8 green =(1+ sin(elapsedTime*.0001))*128;
			Uint8 red =(1+ sin(elapsedTime*.0002))*128;
			Uint8 blue =(1+ sin(elapsedTime*.0003))*128;
			
			screen.setPixel(x,y,red,green,blue);
		
		}
		screen.update();
		if(!screen.processEvents())
			break;
	}
		
	screen.close();

	return 0;   
}