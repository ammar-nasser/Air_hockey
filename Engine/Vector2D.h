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
#pragma once
namespace am
{
	class Vector2D
	{
	public:
		Vector2D(float x = 0.0f, float y = 0.0f);
		bool operator==(const am::Vector2D& another);
		am::Vector2D operator-(const am::Vector2D& another) const;
		am::Vector2D operator+(const am::Vector2D& another) const;
		am::Vector2D operator*(float scaler);
		am::Vector2D operator/(float scaler);
		am::Vector2D& operator*=(float scaler);
		am::Vector2D& operator/=(float scaler);
		float length_sq()const;
		float length() const;
		bool is_zero() const;
		am::Vector2D& normalize();
		am::Vector2D get_normalize() const;
		float dot(const am::Vector2D& another) const;
		float m_x, m_y;
	};
}
