#pragma once

#include "Game.hpp"

namespace DontLaugh
{
	class TextureManager
	{
	public:
		static SDL_Texture *LoadTexture(const char *filePath, SDL_Renderer *renderer);
	};
}
