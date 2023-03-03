#pragma once

#include "SDL.h"

namespace DontLaugh
{
	class Collision
	{
	public:
		static bool AABB(const SDL_Rect& a, const SDL_Rect& b);
	};
}
