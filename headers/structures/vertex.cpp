#include "../headers.hpp"

vertex::vertex()
{
    this->points = vector3d();
    this->normals = vector3d();
}

vertex::vertex(vector3d points, vector3d normals)
{
    this->points = points;
    this->normals = normals;
}
vertex vertex::transform(matrix m)
{
    return vertex(m * this->points, normals);
}