#pragma once

#include "SDL.h"

namespace DontLaugh
{
	class Map
	{
	public:
		Map();
		~Map();

		void Load(int arr[20][25]);
		void Render();

	public:
		constexpr static int unit = 32;

	private:
		SDL_Rect m_Src;
		SDL_Rect m_Dest;
		SDL_Texture* m_Dirt;
		SDL_Texture* m_Grass;
		SDL_Texture* m_Water;
		int m_Map[20][25];
	};
}
