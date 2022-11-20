#pragma once

#include "SDL.h"

namespace DontLaugh
{
	class Game
	{
	public:
		Game();
		Game(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
		~Game();

		void Init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
		void HandleEvents();
		void Update();
		void Render();
		void Clean();

		inline bool Running() { return m_IsRunning; }

	private:
		bool m_IsRunning{ false };
		bool m_IsCleaned{ false };
		Uint32 m_FrameCount{ 0 };
		SDL_Window* m_Window{ nullptr };
		SDL_Renderer* m_Renderer{ nullptr };
	};
}
