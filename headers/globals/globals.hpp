#pragma once

#include "../headers.hpp"

#define COLOR_WHITE 0xFFFFFFFF
#define COLOR_GREY 0x666666FF
#define COLOR_RED 0xFF0000FF
#define COLOR_GREEN 0x00FF00FF
#define COLOR_BLUE 0x0000FFFF
#define COLOR_BLACK 0x000000FF

#define WINDOW_WIDTH 1440
#define WINDOW_HEIGHT 900

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *texture = NULL;
std::vector<object> objects_pool;
