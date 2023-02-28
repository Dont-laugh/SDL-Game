#pragma once

#include "ECS.hpp"

namespace DontLaugh
{
	class PositionComponent : public Component
	{
	public:
		inline int GetX() const { return m_xPos; }

		inline int GetY() const { return m_yPos; }

		void SetPos(int x, int y)
		{
			m_xPos = x;
			m_yPos = y;
		}

		void Init() override
		{
			m_xPos = 0;
			m_yPos = 0;
		}

		void Update() override
		{
			m_xPos++;
			m_yPos++;
		}

	private:
		int m_xPos = 0;
		int m_yPos = 0;
	};
}
