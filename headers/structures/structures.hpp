#pragma once

#include "../headers.hpp"

using namespace std;

struct Point
{
    int x, y;
    double z;
    Uint32 color;
};

struct Line
{
    Point a, b;
    Uint32 color;
};

struct Rect
{
    int x_min, y_min, x_max, y_max;
};

struct Triangle
{
    Point a, b, c;
};


class vector3
{
public:
    double x, y, z;
    vector3();
    vector3(double, double, double);
    vector3 operator+(vector3);
    vector3 operator-(vector3);
    vector3 operator^(vector3);
    double operator*(vector3);
};

class vector3d
{
public:
    double x, y, z, w;
    vector3d();
    vector3d(double, double, double);
    vector3d(double, double, double, double);
    vector3 to_vector3();
};

class matrix
{
public:
    vector<vector<double>> matrix_body;
    int width, height;
    matrix();
    matrix(int, int);
    matrix(vector<vector<double>>);
    matrix(vector3d);
    vector3d to_vector3d();
    vector<double>& operator[](unsigned int);
    matrix operator*(matrix);
    vector3d operator*(vector3d);
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
    object transform(matrix);
    void show();
};

class camera
{
    vector3 position;
    vector3 target;
    vector3 direction;
    vector3 right;
    vector3 up;
public:
    double angle_x, angle_y, angle_z, scale;
    double angle_step, scale_step;
    camera();
    camera(vector3, vector3);
    vector3 get_position();
    vector3 get_target();
    vector3 get_direction();
    vector3 get_right();
    vector3 get_up();
    void rotate_x_up();
    void rotate_x_down();
    void rotate_y_left();
    void rotate_y_right();
    void rotate_z_clock();
    void rotate_z_counterclock();
    void scale_up();
    void scale_down();
};

class transformation_matrices
{
public:
    matrix proj_orto(double, double, double, double, double, double);
    matrix x_rotation(double);
    matrix y_rotation(double);
    matrix z_rotation(double);
    matrix viewport(double, double, double, double, double);
    matrix scale(double, double, double);
    matrix look_at(camera camera);
};

struct view_space
{
    double min_x, min_y, min_z, max_x, max_y, max_z;
};
