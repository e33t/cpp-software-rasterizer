#include "../headers.hpp"

void draw_object(object obj, Uint32 *pixels)
{
    Point p[3];
    for (flat f : obj.flats)
    {
        for(int i = 0; i < size(p); i++)
        {
            vector3 v = f.v[i].points.to_vector3();
            p[i].x = (int)v.x;
            p[i].y = (int)v.y;
            p[i].z = v.z;
            p[i].color = light_calculation(f.v->normals.to_vector3(), obj.color);
        }
        fill_triangle({p[0], p[1], p[2]}, pixels);
    }
}