#pragma once

#include "ECS.hpp"
#include "SDL.h"
#include "Components.h"

namespace DontLaugh
{
	class ColliderComponent : public Component
	{
	public:
		ColliderComponent(const char* tag) : m_Tag(tag) { }

		void Init() override
		{
			m_Transform = EnsureOwnerComponent<TransformComponent>();
		}

		void Update() override
		{
			m_CollideZone.x = static_cast<int>(m_Transform->position.x);
			m_CollideZone.y = static_cast<int>(m_Transform->position.y);
			m_CollideZone.w = static_cast<int>(m_Transform->width * m_Transform->scale);
			m_CollideZone.h = static_cast<int>(m_Transform->height * m_Transform->scale);
		}

	private:
		TransformComponent* m_Transform;
		SDL_Rect m_CollideZone;
		std::string m_Tag;
	};
}
