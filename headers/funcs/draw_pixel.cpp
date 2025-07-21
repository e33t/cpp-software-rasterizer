#include "../headers.hpp"

void draw_pixel(int x, int y, Uint32 color, Uint32* pixels)
{
    pixels[y * WINDOW_WIDTH + x] = color;
}