#pragma once

#include "SDL.h"

namespace DontLaugh
{
	class Game
	{
	public:
		Game();
		~Game();

		void Init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
		void Update();
		void Render();
		void Clean();

		inline bool Running() { return m_IsRunning; }

	private:
		bool m_IsRunning;
		SDL_Window* m_Window;
		SDL_Renderer* m_Renderer;
	};
}
