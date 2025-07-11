#include "../headers.hpp"

object::object(Uint32 color)
{
    this->color = color;
}
void object::show()
{
    cout << "-----------------------------------" << endl;
    for (flat f : flats)
    {
        for(int i = 0; i < 3; i++) cout << "v" << i+1 << ": " << f.v[i].points.x << " " << f.v[i].points.x << " " << f.v[i].points.x << endl;
        for(int i = 0; i < 3; i++) cout << "vn" << i+1 << ": " << f.v[i].normals.x << " " << f.v[i].normals.y << " " << f.v[i].normals.z << endl;
    }
    cout << "-----------------------------------" << endl;
}