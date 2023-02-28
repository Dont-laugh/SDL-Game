#pragma once

#include "ECS.hpp"
#include "../Vector.hpp"

namespace DontLaugh
{
	struct TransformComponent : public Component
	{
		Vector2 position;

		TransformComponent() : position() { }

		TransformComponent(int x, int y) : position(x, y) { }

		void SetPos(int x, int y)
		{
			position.x = x;
			position.y = y;
		}

		void Init() override
		{
			position.x = 0;
			position.y = 0;
		}
	};
}
