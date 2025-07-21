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

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Texture *texture;
extern std::vector<object> objects_pool;
extern Uint32 colors_pool[3];
extern camera cam;
extern matrix main_matrix;
extern view_space view_sp;
extern transformation_matrices transforms;
extern vector3 light;
