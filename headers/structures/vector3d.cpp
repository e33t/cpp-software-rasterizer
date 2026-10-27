#include "../headers.hpp"

vector3d::vector3d()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 1;
}

vector3d::vector3d(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = 1;
}

vector3d::vector3d(double x, double y, double z, double w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

vector3 vector3d::to_vector3()
{
    return vector3(x/w, y/w, z/w);
}