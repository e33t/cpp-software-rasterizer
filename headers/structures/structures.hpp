#pragma once

#include "../headers.hpp"

using namespace std;

class matrix
{
public:
    vector<vector<double>> matrix_body;
    int width, height;
    matrix();
    matrix(int, int);
    matrix(vector<vector<double>>);
    vector<double> operator [](unsigned int);
    matrix operator *(matrix);
    vector3d operator *(vector3d);
};

class vector3d
{
public:
    double x, y, z, w;
    vector3d();
    vector3d(double, double, double, double w = 1);
    vector3d(matrix);
    matrix to_matrix();
};

class vertex
{
public:
    vector3d points, normals;
    vertex();
    vertex(vector3d, vector3d);
    vertex transform(matrix);
};

struct flat
{
    vertex v[3]; 
};

class object
{
public:
    Uint32 color;
    vector<flat> flats;
    object(Uint32);
    void show();
};
