#pragma once

#include <sstream>

#include "SDL.h"
#include "SDL_image.h"

#include "GameObject.h"

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

		inline bool IsRunning() { return m_IsRunning; }

	private:
		#pragma region Gameplay

		bool m_IsRunning{ false };
		bool m_IsCleaned{ false };
		GameObject* m_Player{ nullptr };
		GameObject* m_Enemy{ nullptr };

		#pragma endregion Gameplay

		#pragma region FPS

		static const Uint64 s_FpsInterval{ 500 };
		Uint32 m_FrameCount{ 0 };
		Uint32 m_LastCount{ 0 };
		Uint64 m_LastTime{ 0 };
		std::stringstream m_TitleStream;

		#pragma endregion

		#pragma region SDL

		SDL_Window* m_Window{ nullptr };
		SDL_Renderer* m_Renderer{ nullptr };
		SDL_Texture* m_PlayerTex{ nullptr };

		#pragma endregion
	};
}
