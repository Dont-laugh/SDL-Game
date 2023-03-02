#pragma once

#include "ECS.hpp"
#include "Map.hpp"
#include "SDL_render.h"
#include "TextureManager.hpp"

namespace DontLaugh
{
	class SpriteComponent : public Component
	{
	public:
		SpriteComponent() = default;

		SpriteComponent(const char* path)
		{
			SetTexture(path);
		}

		inline void SetTexture(const char* path)
		{
			m_Texture = TextureManager::LoadTexture(path);
		}

		~SpriteComponent() override
		{
			TextureManager::DestroyTexture(m_Texture);
		}

		void Init() override
		{
			m_Transform = GetOwnerComponent<TransformComponent>();
			m_Src.x = m_Src.y = 0;
			m_Src.w = m_Src.h = Map::unit;
			m_Dest.w = m_Dest.h = 2 * Map::unit;
		}

		void Update() override
		{
			m_Dest.x = static_cast<int>(m_Transform->position.x);
			m_Dest.y = static_cast<int>(m_Transform->position.y);
		}

		void Render() override
		{
			TextureManager::DrawTexture(m_Texture, m_Src, m_Dest);
		}

	private:
		TransformComponent* m_Transform { nullptr };
		SDL_Texture* m_Texture { nullptr };
		SDL_Rect m_Src, m_Dest;
	};
}
