#pragma once

#include "ECS.hpp"
#include "SDL.h"
#include "Components.h"

namespace DontLaugh
{
	class ColliderComponent : public Component
	{
	public:
		SDL_Rect collideZone;

	public:
		ColliderComponent(const char* tag) : m_Tag(tag) { }

		void Init() override
		{
			m_Transform = EnsureOwnerComponent<TransformComponent>();
		}

		void Update() override
		{
			collideZone.x = static_cast<int>(m_Transform->position.x);
			collideZone.y = static_cast<int>(m_Transform->position.y);
			collideZone.w = static_cast<int>(m_Transform->width * m_Transform->scale);
			collideZone.h = static_cast<int>(m_Transform->height * m_Transform->scale);
		}

	private:
		TransformComponent* m_Transform;
		std::string m_Tag;
	};
}
