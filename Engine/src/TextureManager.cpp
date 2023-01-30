#include "TextureManager.h"

namespace DontLaugh
{
	SDL_Texture* TextureManager::LoadTexture(const char* filePath, SDL_Renderer* renderer)
	{
		SDL_Surface* tmpSurface = IMG_Load(filePath);
		SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);
		return tex;
	}
}