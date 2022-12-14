#include <iostream>

#include "Game.hpp"

namespace DontLaugh
{
	const char *windowTitle;
	SDL_Rect srcR, dstR;

	static void CalculateFPS(Uint64 &lastTime, Uint32 &frameCount, Uint32 &lastCount, Uint64 fpsInterval,
							 std::stringstream &stream, SDL_Window *window);

	Game::Game()
	{
	}

	Game::Game(const char *title, int xPos, int yPos, int width, int height, bool fullScreen)
	{
		Init(title, xPos, yPos, width, height, fullScreen);
	}

	Game::~Game()
	{
		Clean();
	}

	void Game::Init(const char *title, int xPos, int yPos, int width, int height, bool fullScreen)
	{
		if (m_IsRunning)
			return;

		int flags = fullScreen ? SDL_WINDOW_FULLSCREEN : 0;

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			m_IsRunning = false;
			SDL_LogError(SDL_LOG_CATEGORY_SYSTEM, "SDL initialize failed!");
			return;
		}

		windowTitle = title;

		m_Window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (m_Window)
		{
			SDL_Log("SDL window created.");
		}

		m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
		if (m_Renderer)
		{
			SDL_SetRenderDrawColor(m_Renderer, 151, 255, 255, 200);
			SDL_Log("SDL renderer created.");
		}

		SDL_Surface *tmpSurface = IMG_Load("assets/player.png");
		m_PlayerTex = SDL_CreateTextureFromSurface(m_Renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);

		m_LastTime = SDL_GetTicks();
		m_IsRunning = true;

		m_TitleStream.setf(std::ios::fixed);
		m_TitleStream.precision(1);

		dstR.h = 64;
		dstR.w = 64;
	}

	void Game::HandleEvents()
	{
		SDL_Event evt;
		SDL_PollEvent(&evt);

		switch (evt.type)
		{
		case SDL_QUIT:
			m_IsRunning = false;
			break;
		default:
			break;
		}
	}

	void Game::Update()
	{
		++m_FrameCount;
		dstR.x = m_FrameCount / 50;

		CalculateFPS(m_LastTime, m_FrameCount, m_LastCount, s_FpsInterval, m_TitleStream, m_Window);
	}

	static void CalculateFPS(Uint64 &lastTime, Uint32 &frameCount, Uint32 &lastCount, Uint64 fpsInterval,
							 std::stringstream &stream, SDL_Window *window)
	{
		Uint64 currTime = SDL_GetTicks();

		if (currTime - lastTime > fpsInterval)
		{
			float fps = (frameCount - lastCount) * 1000.0f / (currTime - lastTime);

			stream.str("");
			stream << windowTitle << " (FPS: " << fps << ")";
			SDL_SetWindowTitle(window, stream.str().c_str());

			lastCount = frameCount;
			lastTime = currTime;
		}
	}

	void Game::Render()
	{
		SDL_RenderClear(m_Renderer);
		// Add stuff to render
		SDL_RenderCopy(m_Renderer, m_PlayerTex, nullptr, &dstR);
		SDL_RenderPresent(m_Renderer);
	}

	void Game::Clean()
	{
		if (m_IsCleaned)
			return;

		SDL_DestroyRenderer(m_Renderer);
		SDL_DestroyWindow(m_Window);
		SDL_Quit();

		m_IsCleaned = true;

		SDL_Log("Game cleaned.");
	}
} // namespace DontLaugh
