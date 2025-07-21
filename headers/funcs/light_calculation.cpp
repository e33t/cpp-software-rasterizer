#include "../headers.hpp"

Uint32 light_calculation(vector3 normal, Uint32 color)
{
    Uint8 r = GET_RED(color), g = GET_GREEN(color), b = GET_BLUE(color);
    double scalar = normal * light;
    double intensity = scalar < 0.0 ? 0.0 : (scalar > 1 ? 1 : scalar);
    return COMPOSE_COLOR((int)(r * intensity), (int)(g * intensity), (int)(b * intensity));
}