#include "TextureManager.hpp"
#include "Game.hpp"

namespace DontLaugh
{
	SDL_Texture* TextureManager::LoadTexture(const char* filePath)
	{
		SDL_Surface* tmpSurface = IMG_Load(filePath);
		SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::GetRenderer(), tmpSurface);
		SDL_FreeSurface(tmpSurface);
		return tex;
	}

	void TextureManager::DrawTexture(SDL_Texture* texture, SDL_Rect& src, SDL_Rect& dest)
	{
		SDL_RenderCopy(Game::GetRenderer(), texture, &src, &dest);
	}

	void TextureManager::DestroyTexture(SDL_Texture* texture)
	{
		if (texture)
		{
			SDL_DestroyTexture(texture);
		}
	}
}