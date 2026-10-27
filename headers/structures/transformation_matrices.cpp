#include "../headers.hpp"

matrix transformation_matrices::proj_orto(double left, double right, double bottom, double top, double near, double far)
{
    matrix m(4,4);
    m[0][0] = 2 / (right - left);
    m[1][1] = 2 / (top - bottom);
    m[2][2] = -2 / (far - near);
    m[3][3] = 1;
    m[0][3] = -(right + left) / (right - left);
    m[1][3] = -(top + bottom) / (top - bottom);
    m[2][3] = -(far + near) / (far - near);
    return m;
}

matrix transformation_matrices::x_rotation(double angle)
{
    double cos_val = cos(angle);
    double sin_val = sin(angle);
    matrix m(4,4);
    m[0][0] = 1;
    m[1][1] = cos_val;
    m[1][2] = -sin_val;
    m[2][1] = sin_val;
    m[2][2] = cos_val;
    m[3][3] = 1;
    return m;
}

matrix transformation_matrices::y_rotation(double angle)
{
    double cos_val = cos(angle);
    double sin_val = sin(angle);
    matrix m(4,4);
    m[0][0] = cos_val;
    m[0][2] = -sin_val;
    m[2][0] = sin_val;
    m[2][2] = cos_val;
    m[1][1] = 1;
    m[3][3] = 1;
    return m;
}

matrix transformation_matrices::z_rotation(double angle)
{
    double cos_val = cos(angle);
    double sin_val = sin(angle);
    matrix m(4,4);
    m[0][0] = cos_val;
    m[0][1] = -sin_val;
    m[1][0] = sin_val;
    m[1][1] = cos_val;
    m[2][2] = 1;
    m[3][3] = 1;
    return m;
}

matrix transformation_matrices::viewport(double x, double y, double width, double height, double depth)
{
    matrix m(4,4);
    m[0][0] = width / 2;
    m[1][1] = height / -2;
    m[2][2] = depth / 2;
    m[3][3] = 1;
    m[0][3] = x + width / 2;
    m[1][3] = y + height / 2;
    m[2][3] = depth / 2;
    return m; 
}

matrix transformation_matrices::look_at(camera camera)
{
    matrix m(4,4);
    m[0][0] = camera.get_right().x;
    m[0][1] = camera.get_right().y;
    m[0][2] = camera.get_right().z;
    m[1][0] = camera.get_up().x;
    m[1][1] = camera.get_up().y;
    m[1][2] = camera.get_up().z;
    m[2][0] = camera.get_direction().x;
    m[2][1] = camera.get_direction().y;
    m[2][2] = camera.get_direction().z;
    m[0][3] = -camera.get_position().x;
    m[1][3] = -camera.get_position().y;
    m[2][3] = -camera.get_position().z;
    m[3][3] = 1;
    return m;
}

matrix transformation_matrices::scale(double kx, double ky, double kz)
{
    matrix m(4, 4);
    m[0][0] = kx;
    m[1][1] = ky;
    m[2][2] = kz;
    m[3][3] = 1;
    return m;
}