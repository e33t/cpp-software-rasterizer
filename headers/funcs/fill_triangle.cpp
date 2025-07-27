#include "../headers.hpp"

double interpolate_point(double begin, double end, double t)
{
    return begin + (end - begin) * t;
}

Uint32 line_color(Point a, Point b, int x, int y)
{
    if(a.x == x && a.y == y) return a.color;
    if(b.x == x && b.y == y) return b.color;

    if(a.x < b.x) std::swap(a, b);
    else if((a.x == b.x) && (a.y < b.y)) std::swap(a, b);

    float alpfa = (a.x == x) | (b.x == x) ? (float)(a.y-y)/(float)(a.y-b.y) : (float)(a.x-x)/(float)(a.x-b.x);
    Uint8 red = alpfa*GET_RED(b.color) + (1-alpfa)*GET_RED(a.color);
    Uint8 green = alpfa*GET_GREEN(b.color) + (1-alpfa)*GET_GREEN(a.color);
    Uint8 blue = alpfa*GET_BLUE(b.color) + (1-alpfa)*GET_BLUE(a.color);
    return COMPOSE_COLOR(red, green, blue);
}

void fill_triangle(Triangle tr, Uint32* pixels) //a -> tr.a, b -> tr.b, c -> tr.c
{
    Point t0 = tr.a, t1 = tr.b, t2 = tr.c;
    if (t0.y==t1.y && t0.y==t2.y) return;

    if (t0.y>t1.y) std::swap(t0, t1);
    if (t0.y>t2.y) std::swap(t0, t2);
    if (t1.y>t2.y) std::swap(t1, t2);

    int total_height = t2.y-t0.y;
    for (int i=t0.y; i<=t2.y; i++) 
    {
        bool is_second_half = i>t1.y || t1.y==t0.y;
        int segment_height = is_second_half ? t2.y-t1.y : t1.y-t0.y;
        float alpha = (float)(i-t0.y)/total_height;
        float beta  = (float)(i-(is_second_half ? t1.y : t0.y))/segment_height; 

        // Point a = {(int)(t0.x + (t2.x-t0.x)*alpha), i, 0};
        // a.color = line_color(t2, t0, a.x, a.y);
        // Point b = {(int)(is_second_half ? t1.x + (t2.x-t1.x)*beta : t0.x + (t1.x-t0.x)*beta), i, 0};
        // b.color = is_second_half ? line_color(t2, t1, b.x, b.y) : line_color(t1, t0, b.x, b.y);
        Point a, b;

        a.x = (int)interpolate_point(t0.x, t2.x, alpha);
        a.y = i;
        a.z = interpolate_point(t0.z, t2.z, alpha);
        a.color = line_color(t2, t0, a.x, a.y);

        b.x = (int)(is_second_half ? interpolate_point(t1.x, t2.x, beta) : interpolate_point(t0.x, t1.x, beta));
        b.y = i;
        b.z = (is_second_half ? interpolate_point(t1.z, t2.z, beta) : interpolate_point(t0.z, t1.z, beta));
        b.color = is_second_half ? line_color(t2, t1, b.x, b.y) : line_color(t1, t0, b.x, b.y);

        if (a.x>b.x) std::swap(a, b);
        for (int j=a.x; j<=b.x; j++) 
        {
            Uint32 color = line_color(b, a, j, i);
            Point p = {j, i, 0, color};
            double tz = (a.x != b.x) ? (double)(j - a.x) / (b.x - a.x) : 1;
            p.z = interpolate_point(a.z, b.z, tz);
            if(((p.x >= 0) && (p.x < WINDOW_WIDTH) && (p.y >= 0) && (p.y < WINDOW_HEIGHT)) && (p.z > z_buffer[p.x][p.y]))
            {
                z_buffer[p.x][p.y] = p.z;
                draw_pixel(p, pixels);
            } 
        }
    }
}