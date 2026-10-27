#pragma once

#include "../headers.hpp"

using namespace std;

#define GET_RED(color) ((color & 0xFF000000) >> 24)
#define GET_GREEN(color) ((color & 0x00FF0000) >> 16)
#define GET_BLUE(color) ((color & 0x0000FF00) >> 8)
#define COMPOSE_COLOR(r, g, b) ((r << 24) | (g << 16) | (b << 8) | 0xFF)

void draw_pixel(Point, Uint32*);

void load_scene(string);

void form_transformation_matrix();

object rotate_obj(object);

Uint32 light_calculation(vector3, Uint32);

void fill_triangle(Triangle, Uint32*);

void draw_object(object, Uint32*);

void draw_frame(Uint32*);