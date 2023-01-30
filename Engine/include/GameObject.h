#pragma once

#include "SDL.h"

namespace DontLaugh
{
	class GameObject
	{
	public:
		GameObject(const char* texturePath, SDL_Renderer* renderer, int x, int y);
		~GameObject();

		void Update();
		void Render();

	private:
		int xPos, yPos;
		SDL_Texture* texture;
		SDL_Renderer* renderer;
		SDL_Rect srcRect, dstRect;
	};
}
