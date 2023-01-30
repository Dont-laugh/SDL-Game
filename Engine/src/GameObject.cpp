#include "GameObject.h"
#include "TextureManager.h"

namespace DontLaugh
{
	GameObject::GameObject(const char* texturePath, SDL_Renderer* renderer, int x, int y)
	{
		this->renderer = renderer;
		this->texture = TextureManager::LoadTexture(texturePath, renderer);
		this->xPos = x;
		this->yPos = y;
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		xPos++;
		yPos++;

		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = 64;
		srcRect.h = 64;

		dstRect.x = xPos;
		dstRect.y = yPos;
		dstRect.w = srcRect.w * 2;
		dstRect.h = srcRect.h * 2;
	}

	void GameObject::Render()
	{
		SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
	}
}
