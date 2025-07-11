#include "../headers.hpp"

vector3d::vector3d()
{
    (*this) = vector3d(0,0,0);
}

vector3d::vector3d(double x, double y, double z, double w = 1)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}
vector3d::vector3d(matrix column_matrix)
{
    x = column_matrix[0][0];
    y = column_matrix[1][0];
    z = column_matrix[2][0];
    w = column_matrix[3][0];
}
matrix vector3d::to_matrix()
{
    return matrix({{x},{y},{z},{w}});
}