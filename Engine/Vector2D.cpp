/**Author:
  /$$$$$$                                                  /$$   /$$
 /$$__  $$                                                | $$$ | $$
| $$  \ $$ /$$$$$$/$$$$  /$$$$$$/$$$$   /$$$$$$   /$$$$$$ | $$$$| $$  /$$$$$$   /$$$$$$$ /$$$$$$$  /$$$$$$   /$$$$$$
| $$$$$$$$| $$_  $$_  $$| $$_  $$_  $$ |____  $$ /$$__  $$| $$ $$ $$ |____  $$ /$$_____//$$_____/ /$$__  $$ /$$__  $$
| $$__  $$| $$ \ $$ \ $$| $$ \ $$ \ $$  /$$$$$$$| $$  \__/| $$  $$$$  /$$$$$$$|  $$$$$$|  $$$$$$ | $$$$$$$$| $$  \__/
| $$  | $$| $$ | $$ | $$| $$ | $$ | $$ /$$__  $$| $$      | $$\  $$$ /$$__  $$ \____  $$\____  $$| $$_____/| $$
| $$  | $$| $$ | $$ | $$| $$ | $$ | $$|  $$$$$$$| $$      | $$ \  $$|  $$$$$$$ /$$$$$$$//$$$$$$$/|  $$$$$$$| $$
|__/  |__/|__/ |__/ |__/|__/ |__/ |__/ \_______/|__/      |__/  \__/ \_______/|_______/|_______/  \_______/|__/
**/
#include "Vector2D.h"
#include <assert.h>
#include <cmath>

am::Vector2D::Vector2D(float x, float y)
	:
	m_x(x),
	m_y(y)
{
}

bool am::Vector2D::operator==(const am::Vector2D& another)
{
	return m_x == another.m_x && m_y == another.m_y;
}

am::Vector2D am::Vector2D::operator-(const am::Vector2D& another)
{
	return am::Vector2D(m_x - another.m_x, m_y - another.m_y);
}

am::Vector2D am::Vector2D::operator+(const am::Vector2D& another)
{
	return am::Vector2D(m_x + another.m_x, m_y + another.m_y);
}

am::Vector2D am::Vector2D::operator*(float scaler)
{
	return am::Vector2D(m_x * scaler, m_y * scaler);
}

am::Vector2D am::Vector2D::operator/(float scaler)
{
	assert(scaler != 0.0f);
	return am::Vector2D(m_x/scaler, m_y/scaler);
}

am::Vector2D& am::Vector2D::operator*=(float scaler)
{
	m_x *= scaler;
	m_y *= scaler;
	return *this;
}

am::Vector2D& am::Vector2D::operator/=(float scaler)
{
	assert(scaler != 0.0f);
	m_x /= scaler;
	m_y /= scaler;
	return *this;
}

float am::Vector2D::length_sq() const
{
	return (m_x * m_x) + (m_y * m_y);
}

float am::Vector2D::length() const
{
	return std::sqrtf(length_sq());
}

bool am::Vector2D::is_zero() const
{
	return length_sq() == 0.0f;
}

am::Vector2D& am::Vector2D::normalize()
{
	if (is_zero())
	{
		m_x = m_y = 0.0f;
		return *this;
	}
	float recip = 1.0f / length_sq();
	m_x *= recip;
	m_y *= recip;
	return *this;
}

am::Vector2D am::Vector2D::get_normalize() const
{
	if (is_zero())
	{
		return *this;
	}
	float recip = 1.0f / length_sq();
	return am::Vector2D(m_x * recip, m_y * recip);
}

float am::Vector2D::dot(const am::Vector2D& another) const
{
	return (m_x * another.m_x) + (m_y * another.m_y);
}
