#include "../headers.hpp"

object rotate_obj(object obj)
{
    matrix total_rotation = transforms.x_rotation(cam.angle_x) * transforms.y_rotation(cam.angle_y) * transforms.z_rotation(cam.angle_z);
    matrix final_transform = main_matrix * total_rotation;
    return obj.transform(final_transform);
}