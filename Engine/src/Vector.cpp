#include "Vector.hpp"

namespace DontLaugh
{
	Vector2::Vector2() : x(0), y(0) { }

	Vector2::Vector2(float x, float y) : x(x), y(y) { }

	Vector2& Vector2::Add(const Vector2& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		return *this;
	}

	Vector2& Vector2::Subtract(const Vector2& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		return *this;
	}

	Vector2& Vector2::Multiply(const Vector2& vec)
	{
		this->x *= vec.x;
		this->y *= vec.y;
		return *this;
	}

	Vector2& Vector2::Divide(const Vector2& vec)
	{
		this->x /= vec.x;
		this->y /= vec.y;
		return *this;
	}

	Vector2& operator +(Vector2& lhs, const Vector2& rhs)
	{
		return lhs.Add(rhs);
	}

	Vector2& operator -(Vector2& lhs, const Vector2& rhs)
	{
		return lhs.Subtract(rhs);
	}

	Vector2& operator *(Vector2& lhs, const Vector2& rhs)
	{
		return lhs.Multiply(rhs);
	}

	Vector2& operator /(Vector2& lhs, const Vector2& rhs)
	{
		return lhs.Divide(rhs);
	}

	Vector2& Vector2::operator +(const float& f)
	{
		this->x += f;
		this->y += f;
		return *this;
	}

	Vector2& Vector2::operator -(const float& f)
	{
		this->x -= f;
		this->y -= f;
		return *this;
	}

	Vector2& Vector2::operator *(const float& f)
	{
		this->x *= f;
		this->y *= f;
		return *this;
	}

	Vector2& Vector2::operator /(const float& f)
	{
		this->x /= f;
		this->y /= f;
		return *this;
	}

	Vector2& Vector2::operator +=(const Vector2& other)
	{
		return this->Add(other);
	}

	Vector2& Vector2::operator -=(const Vector2& other)
	{
		return this->Subtract(other);
	}

	Vector2& Vector2::operator *=(const Vector2& other)
	{
		return this->Multiply(other);
	}

	Vector2& Vector2::operator /=(const Vector2& other)
	{
		return this->Divide(other);
	}

	std::ostream& operator <<(std::ostream& stream, const Vector2& vec)
	{
		stream.precision(1);
		stream << "(" << vec.x << ", " << vec.y << ")";
		return stream;
	}
}
