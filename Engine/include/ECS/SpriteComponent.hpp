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
			m_Transform = EnsureOwnerComponent<TransformComponent>();
			m_Src.x = m_Src.y = 0;
			m_Src.w = m_Transform->width;
			m_Src.h = m_Transform->height;
		}

		void Update() override
		{
			m_Dest.x = static_cast<int>(m_Transform->position.x);
			m_Dest.y = static_cast<int>(m_Transform->position.y);
			m_Dest.w = static_cast<int>(m_Transform->width * m_Transform->scale);
			m_Dest.h = static_cast<int>(m_Transform->height * m_Transform->scale);
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
