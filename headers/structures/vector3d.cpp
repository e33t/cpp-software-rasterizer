#include "../headers.hpp"

vector3d::vector3d()
{
    (*this) = vector3d(0,0,0);
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
