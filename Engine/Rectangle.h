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
#include "Colors.h"
#include "Graphics.h"
#include "Vector2D.h"
namespace am
{
	class Rectangle
	{
	public:
		Rectangle(float top = 0.0f, float left = 0.0f, float bottom = 0.0f, float right = 0.0f, Color color = Colors::Black);
		Rectangle(const am::Vector2D& top_left, float width, float height, Color color);
		Rectangle(const am::Vector2D& top_left, const am::Vector2D& bottom_right, Color color);
		Rectangle(float half_width, const am::Vector2D& center, float half_height, Color color);
		void draw(Graphics& gfx);
	private:
		float m_top, m_left, m_bottom, m_right, m_width, m_height, m_half_width, m_half_height;
		Color m_color;
	};
}