#pragma once

#include "ECS.hpp"
#include "../Vector.hpp"

namespace DontLaugh
{
	class TransformComponent : public Component
	{
	public:
		Vector2 position;
		Vector2 velocity;
		int speed { 3 };

		TransformComponent() : position() { }

		TransformComponent(int x, int y) : position(x, y) { }

		void Init() override
		{
			position.x = 0;
			position.y = 0;
			velocity.x = 0;
			velocity.y = 0;
		}

		void Update() override
		{
			position.x += velocity.x * speed;
			position.y += velocity.y * speed;
		}
	};
}
