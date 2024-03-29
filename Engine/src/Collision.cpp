#include "Collision.hpp"

namespace DontLaugh
{
	bool Collision::AABB(const SDL_Rect& a, const SDL_Rect& b)
	{
		return a.x + a.w >= b.x && b.x + b.w >= a.x && a.y + a.h >= b.y && b.y + b.h >= a.y;
	}
}
