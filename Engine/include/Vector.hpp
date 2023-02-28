#pragma once

#include <iostream>

namespace DontLaugh
{
	struct Vector2
	{
		float x;
		float y;

		Vector2();

		Vector2(float x, float y);

		Vector2 &Add(const Vector2 &vec);
		Vector2 &Subtract(const Vector2 &vec);
		Vector2 &Multiply(const Vector2 &vec);
		Vector2 &Divide(const Vector2 &vec);

		friend Vector2 &operator+(Vector2 &lhs, const Vector2 &rhs);
		friend Vector2 &operator-(Vector2 &lhs, const Vector2 &rhs);
		friend Vector2 &operator*(Vector2 &lhs, const Vector2 &rhs);
		friend Vector2 &operator/(Vector2 &lhs, const Vector2 &rhs);

		Vector2 &operator+=(const Vector2 &other);
		Vector2 &operator-=(const Vector2 &other);
		Vector2 &operator*=(const Vector2 &other);
		Vector2 &operator/=(const Vector2 &other);

		friend std::ostream &operator<<(std::ostream &stream, const Vector2 &vec);
	};
}
