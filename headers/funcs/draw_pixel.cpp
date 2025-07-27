#include "../headers.hpp"

void draw_pixel(Point p, Uint32* pixels)
{
    pixels[p.y * WINDOW_WIDTH + p.x] = p.color;
}