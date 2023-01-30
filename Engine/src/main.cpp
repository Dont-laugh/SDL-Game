#include "Game.hpp"

DontLaugh::Game* g_Game = nullptr;

int main(int arg, char* argv[])
{
	constexpr int Fps = 60;  // 目标帧率
	constexpr Uint32 FrameDelay = 1000u / Fps;

	Uint32 frameStart, frameTime;

	g_Game = new DontLaugh::Game();
	g_Game->Init("2D Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 720, false);

	while (g_Game->IsRunning())
	{
		frameStart = SDL_GetTicks();

		g_Game->HandleEvents();
		g_Game->Update();
		g_Game->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (FrameDelay > frameTime)
		{
			SDL_Delay(FrameDelay - frameTime);
		}
	}

	g_Game->Clean();
	delete g_Game;

	return 0;
}