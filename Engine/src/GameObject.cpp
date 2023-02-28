#include "GameObject.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"

namespace DontLaugh
{
	GameObject::GameObject(const char* texturePath, int x, int y)
	{
		this->m_Texture = TextureManager::LoadTexture(texturePath);
		this->m_XPos = x;
		this->m_YPos = y;
	}

	GameObject::~GameObject()
	{
		TextureManager::DestroyTexture(m_Texture);
	}

	void GameObject::Update()
	{
		m_XPos++;
		m_YPos++;

		m_Src.x = 0;
		m_Src.y = 0;
		m_Src.w = Map::unit;
		m_Src.h = Map::unit;

		m_Dest.x = m_XPos;
		m_Dest.y = m_YPos;
		m_Dest.w = m_Src.w * 2;
		m_Dest.h = m_Src.h * 2;
	}

	void GameObject::Render()
	{
		TextureManager::DrawTexture(m_Texture, m_Src, m_Dest);
	}
}
