#pragma once

#include "SDL.h"

namespace DontLaugh
{
	class TextureManager
	{
	public:
		static SDL_Texture *LoadTexture(const char *filePath);
		static void DrawTexture(SDL_Texture* texture, SDL_Rect& src, SDL_Rect& dest);
		static void DestroyTexture(SDL_Texture* texture);
	};
}
