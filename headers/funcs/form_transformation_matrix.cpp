#include "../headers.hpp"

void form_transformation_matrix()
{ 
    matrix orto_proj = transforms.proj_orto(
        view_sp.min_x, 
        view_sp.max_x,
        view_sp.min_y, 
        view_sp.max_y, 
        view_sp.min_z, 
        view_sp.max_z
    );
    
    matrix look_at = transforms.look_at(cam);
    double depth = view_sp.max_z - view_sp.min_z;
    matrix view_port = transforms.viewport(100, -200, WINDOW_WIDTH, WINDOW_HEIGHT, depth);
    main_matrix = view_port * orto_proj * look_at;
}