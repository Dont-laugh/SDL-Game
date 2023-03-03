#pragma once

#include "ECS.hpp"
#include "SDL.h"
#include "Game.hpp"

namespace DontLaugh
{
	class KeyboardComponent : public Component
	{
	public:
		KeyboardComponent(SDL_Event* evt) : m_Event(evt) { }

		void Init() override
		{
			m_Transform = EnsureOwnerComponent<TransformComponent>();
		}

		void Update() override
		{
			const bool keyDown = m_Event->type == SDL_KEYDOWN;

			switch (m_Event->key.keysym.sym)
			{
				case SDLK_w:
				case SDLK_UP:
					m_Transform->velocity.y = keyDown ? -1 : 0;
					break;
				case SDLK_a:
				case SDLK_LEFT:
					m_Transform->velocity.x = keyDown ? -1 : 0;
					break;
				case SDLK_s:
				case SDLK_DOWN:
					m_Transform->velocity.y = keyDown ? 1 : 0;
					break;
				case SDLK_d:
				case SDLK_RIGHT:
					m_Transform->velocity.x = keyDown ? 1 : 0;
					break;
			}
		}

	private:
		TransformComponent* m_Transform;
		SDL_Event* m_Event;
	};
}
