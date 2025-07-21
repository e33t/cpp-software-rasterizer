#include "../headers.hpp"

void draw_frame(Uint32 *pixels)
{
    for (int x = 0; x < WINDOW_WIDTH; x++) for (int y = 0; y < WINDOW_HEIGHT; y++) draw_pixel(x, y, COLOR_WHITE, pixels);
    for (object obj : objects_pool) 
    {  
        // obj.show();
        // cout << "||||||" << endl;
        object new_object = rotate_obj(obj);
        // new_object.show();
        draw_object(new_object, pixels);
    };
}