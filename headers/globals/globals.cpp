#include "../headers.hpp"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *texture = NULL;
std::vector<object> objects_pool;
Uint32 colors_pool[3] = {COLOR_RED, COLOR_GREEN, COLOR_BLUE};
camera cam = camera(vector3(0.4, 0.4, 1), vector3(0, 0, 0));
matrix main_matrix;
view_space view_sp = {DBL_MAX, DBL_MAX, DBL_MAX, -DBL_MAX, -DBL_MAX, -DBL_MAX};
transformation_matrices transforms;
vector3 light = {0.2, 0.7, 1};