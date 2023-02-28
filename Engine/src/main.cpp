#include "Game.hpp"

int main(int arg, char* argv[])
{
	constexpr int Fps = 60;  // 目标帧率
	constexpr Uint32 FrameDelay = 1000u / Fps;

	Uint32 frameStart, frameTime;

	auto game = new DontLaugh::Game(
		"2D Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 720, false
	);

	while (game->IsRunning())
	{
		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (FrameDelay > frameTime)
		{
			SDL_Delay(FrameDelay - frameTime);
		}
	}

	game->Clean();
	delete game;

	return 0;
}