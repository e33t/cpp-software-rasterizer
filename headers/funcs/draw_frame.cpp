#include "../headers.hpp"

void clear_buffer()
{
    for (int i = 0; i < WINDOW_WIDTH; i++) for (int j = 0; j < WINDOW_HEIGHT; j++) z_buffer[i][j] = -DBL_MAX;
}

void draw_frame(Uint32 *pixels)
{
    clear_buffer();
    for (int x = 0; x < WINDOW_WIDTH; x++) for (int y = 0; y < WINDOW_HEIGHT; y++) draw_pixel({x, y, 0, COLOR_WHITE}, pixels);
    for (object obj : objects_pool) 
    {  
        object new_object = rotate_obj(obj);
        draw_object(new_object, pixels);
    };
}