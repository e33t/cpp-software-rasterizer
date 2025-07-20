#include "../headers.hpp"

vector3::vector3()
{
    x = 0;
    y = 0;
    z = 0;
}

vector3::vector3(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

vector3 vector3::operator+(vector3 v)
{
    return vector3(this->x+v.x, this->x+v.y, this->x+v.z);
}

vector3 vector3::operator-(vector3 v)
{
    return vector3(this->x-v.x, this->x-v.y, this->x-v.z);
}

vector3 vector3::operator^(vector3 v)
{
    return vector3(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z, this->x * v.y - this->y * v.x);
}

double vector3::operator*(vector3 v)
{
    return this->x * v.x + this->y * v.y + this->z * v.z;
}