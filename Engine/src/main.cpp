#include "Game.hpp"

DontLaugh::Game* g_Game = nullptr;

int main(int arg, char* argv[])
{
	g_Game = new DontLaugh::Game();
	g_Game->Init("2D Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	while (g_Game->Running())
	{
		g_Game->HandleEvents();
		g_Game->Update();
		g_Game->Render();
	}

	g_Game->Clean();
	delete g_Game;

	return 0;
}