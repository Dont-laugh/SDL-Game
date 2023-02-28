#pragma once

#include "SDL.h"

namespace DontLaugh
{
	class GameObject
	{
	public:
		GameObject(const char* texturePath, int x, int y);
		~GameObject();

		void Update();
		void Render();

	private:
		int m_XPos, m_YPos;
		SDL_Texture* m_Texture;
		SDL_Rect m_Src, m_Dest;
	};
}
