#include "../headers.hpp"

camera::camera(vector3 position, vector3 target)
{
    this->position = position;
    this->target = target;
    angle = 0;
    angle_step = 0.1;

    vector3 direction = target - position;
    vector3 right = up_dir ^ direction;
    vector3 up = direction ^ right;
}

camera::camera()
{
    *this = camera(vector3(0, 0, 0), vector3(0, 0, 0));
}

vector3 camera::get_position() {return position;}
vector3 camera::get_target() {return target;}
vector3 camera::get_direction() {return direction;}
vector3 camera::get_right() {return right;}
vector3 camera::get_up() {return up;}

void camera::rotate_left() {angle -= angle_step;}
void camera::rotate_right() {angle += angle_step;}