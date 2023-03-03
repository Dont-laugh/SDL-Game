#pragma once

#include <sstream>

#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.hpp"
#include "Map.hpp"
#include "ECS/Components.h"
#include "Collision.hpp"

namespace DontLaugh
{
	class Game
	{
	public:
		Game(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
		~Game();

		void HandleEvents();
		void Update();
		void Render();
		void Clean();

		static inline SDL_Renderer* GetRenderer() { return m_Renderer; }

		inline bool IsRunning() { return m_IsRunning; }

	private:
		#pragma region Gameplay

		bool m_IsRunning { false };
		bool m_IsCleaned { false };
		Map* m_LevelMap { nullptr };
		EcsManager* m_Manager { nullptr };
		Entity* m_Player { nullptr };
		Entity* m_Enemy { nullptr };

		#pragma endregion Gameplay

		#pragma region FPS

	public:
		constexpr static Uint64 FPS_INTERVAL { 500 };

	private:
		Uint32 m_FrameCount { 0 };
		Uint32 m_LastCount { 0 };
		Uint64 m_LastTime { 0 };
		std::stringstream m_TitleStream;

		#pragma endregion

		#pragma region SDL

		static SDL_Renderer* m_Renderer;
		SDL_Event* m_Event { nullptr };
		SDL_Window* m_Window { nullptr };

		#pragma endregion
	};
}
