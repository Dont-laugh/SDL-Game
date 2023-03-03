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
		float scale { 1 };
		int height { Map::unit };
		int width { Map::unit };

		TransformComponent() : position() { }

		TransformComponent(int x, int y) : position(x, y) { }

		TransformComponent(int x, int y, int w, int h) : position(x, y), width(w), height(h) { }

		TransformComponent(int x, int y, int w, int h, float s) : position(x, y), width(w), height(h), scale(s) { }

		void Init() override
		{
			velocity.x = 0;
			velocity.y = 0;
		}

		void Update() override
		{
			position += velocity * speed;
		}
	};
}
