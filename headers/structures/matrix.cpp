#include "../headers.hpp"

matrix::matrix()
{
    (*this) = matrix(0,0);
}

matrix::matrix(int height, int width)
{
    this->width = width;
    this->height = height;
    matrix_body = vector<vector<double>>(height, vector<double>(width));
}

matrix::matrix(vector<vector<double>> m)
{
    matrix_body = m;
    height = matrix_body.size();
    width = matrix_body[0].size();
}

matrix::matrix(vector3d v3d)
{
    matrix_body = {{v3d.x},{v3d.y},{v3d.z},{v3d.w}};
    height = matrix_body.size();
    width = matrix_body[0].size();
}

vector<double>& matrix::operator[](unsigned int index)
{
    return matrix_body[index];
}

vector3d matrix::to_vector3d()
{
    return vector3d(matrix_body[0][0], matrix_body[1][0], matrix_body[2][0], matrix_body[3][0]);
}

matrix matrix::operator*(matrix m)
{
    matrix result = matrix(this->height, m.width);
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < m.width; j++)
        {
            for (int k = 0; k < this->width; k++)
            {
                result[i][j] += matrix_body[i][k] * m[k][j];
            }
        }
    }

    return result;
}

vector3d matrix::operator*(vector3d v)
{
    return ((*this) * matrix(v)).to_vector3d();  
}