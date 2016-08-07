#ifndef SCREEN_H_
#define SCREEN_H_
#include <SDL.h>
namespace SDLSkeleton {
	class Screen {
	public:
		const static int SCREEN_WIDTH = 1920;
		const static int SCREEN_HEIGHT = 1080;

	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;

		Uint32* m_buffer1;
		Uint32* m_buffer2;
	public:
		Screen();
		void setPixel(int x, int y,Uint8 red,Uint8 green,Uint8 blue);
		void update();
		bool init();
		bool processEvents();
		void boxBlur();
		void clear();
		void close();
	};
}
#endif