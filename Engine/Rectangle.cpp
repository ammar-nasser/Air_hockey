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
#include "Rectangle.h"
#include <assert.h>

am::Rectangle::Rectangle(float top, float left, float bottom, float right, Color color)
	:
	m_top(top),
	m_left(left),
	m_bottom(bottom),
	m_right(right),
	m_width(m_right - m_left),
	m_height(m_bottom - m_top),
	m_half_width(m_width/2.0f),
	m_half_height(m_height/2.0f),
	m_color(color)
{
}

am::Rectangle::Rectangle(const am::Vector2D& top_left, float width, float height, Color color)
	:
	Rectangle(top_left.m_y, top_left.m_x, top_left.m_y + height, top_left.m_x + width, color)
{
}

am::Rectangle::Rectangle(const am::Vector2D& top_left, const am::Vector2D& bottom_right, Color color)
	:
	Rectangle(top_left, (bottom_right.m_x - top_left.m_x), (bottom_right.m_y - top_left.m_y), color)
{
}

am::Rectangle::Rectangle(float half_width, const am::Vector2D& center, float half_height, Color color)
	:
	Rectangle( am::Vector2D(center - am::Vector2D(half_width, half_height)),
		am::Vector2D(center + am::Vector2D(half_width, half_height)), color)
{
}

void am::Rectangle::draw(Graphics& gfx)
{
	assert(m_top <= m_bottom);
	assert(m_left <= m_right);
	for (int y = int(m_top); y <= int(m_bottom); y++)
		for (int x = int(m_left); x <= int(m_right); x++)
			gfx.PutPixel(x, y, m_color);
}
