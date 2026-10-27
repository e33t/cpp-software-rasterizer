#include "../headers.hpp"

camera::camera(vector3 position, vector3 target)
{
    this->position = position;
    this->target = target;
    angle_x = 0;
    angle_y = 0;
    angle_z = 0;
    scale = 0.4;
    angle_step = 0.1;
    scale_step = 0.1;

    this->direction = target - position;
    this->right = vector3(0, 1, 0) ^ this->direction;
    this->up = this->direction ^ this->right;
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

void camera::rotate_x_up() {angle_x -= angle_step;}
void camera::rotate_x_down() {angle_x += angle_step;}

void camera::rotate_y_left() {angle_y -= angle_step;}
void camera::rotate_y_right() {angle_y += angle_step;}

void camera::rotate_z_clock() {angle_z -= angle_step;}
void camera::rotate_z_counterclock() {angle_z += angle_step;}

void camera::scale_up() {scale += scale_step;}
void camera::scale_down() {scale -= scale_step;}