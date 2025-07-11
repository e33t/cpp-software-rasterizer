#include "../headers.hpp"

matrix::matrix()
{
    (*this) = matrix(0,0);
}

matrix::matrix(int width, int height)
{
    this->width = width;
    this->height = height;
    matrix_body = vector<vector<double>>(height, vector<double>(width));
}

matrix::matrix(vector<vector<double>> m)
{
    matrix_body = m;
}

vector<double> matrix::operator [](unsigned int index)
{
    return matrix_body[index];
}

matrix matrix::operator*(matrix m)
{
    matrix result = matrix(this->height, m.width);

    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < m.width; j++)
            for (int k = 0; k < this->width; k++)
                result[i][j] += (*this)[i][k] * m[k][j];

    return result;
}

vector3d matrix::operator*(vector3d v)
{
    return vector3d((*this) * v.to_matrix());  
}