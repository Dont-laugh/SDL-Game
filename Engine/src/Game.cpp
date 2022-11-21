#include <iostream>

#include "Game.hpp"

namespace DontLaugh
{
	const char* windowTitle;

	Game::Game()
	{
	}

	Game::Game(const char* title, int xPos, int yPos, int width, int height, bool fullScreen)
	{
		Init(title, xPos, yPos, width, height, fullScreen);
	}

	Game::~Game()
	{
		Clean();
	}

	void Game::Init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen)
	{
		if (m_IsRunning)
			return;

		int flags = fullScreen ? SDL_WINDOW_FULLSCREEN : 0;

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			m_IsRunning = false;
			SDL_LogDebug(SDL_LOG_CATEGORY_ERROR, "SDL initialize failed!");
			std::cerr << "SDL initialize failed!" << std::endl;
			return;
		}

		windowTitle = title;

		m_Window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (m_Window)
		{
			SDL_LogDebug(SDL_LOG_CATEGORY_SYSTEM, "SDL window created.");
			std::cout << "SDL window created." << std::endl;
		}

		m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
		if (m_Renderer)
		{
			SDL_SetRenderDrawColor(m_Renderer, 151, 255, 255, 200);
			SDL_LogDebug(SDL_LOG_CATEGORY_SYSTEM, "SDL renderer created.");
			std::cout << "SDL renderer created." << std::endl;
		}

		m_LastTime = SDL_GetTicks();
		m_IsRunning = true;

		m_TitleStream.setf(std::ios::fixed);
		m_TitleStream.precision(1);
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
		Uint64 currTime = SDL_GetTicks();

		if (currTime - m_LastTime > s_FpsInterval)
		{
			float fps = (m_FrameCount - m_LastCount) * 1000.0f / (currTime - m_LastTime);

			m_TitleStream.str("");
			m_TitleStream << windowTitle << " FPS: " << fps;
			SDL_SetWindowTitle(m_Window, m_TitleStream.str().c_str());

			m_LastCount = m_FrameCount;
			m_LastTime = currTime;
		}
	}

	void Game::Render()
	{
		SDL_RenderClear(m_Renderer);
		// Add stuff to render
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

		SDL_LogDebug(SDL_LOG_CATEGORY_SYSTEM, "Game cleaned.");
		std::cout << "Game cleaned." << std::endl;
	}
}
