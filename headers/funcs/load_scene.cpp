#include "../headers.hpp"

pair<int, int> parse(string positions)
{
    string vi, vni;
    stringstream ss(positions);
    getline(ss, vi, '/');
    getline(ss, vni, '/');
    getline(ss, vni, '/');
    return {stoi(vi)-1, stoi(vni)-1};
}

void load_scene(string file_name = "scenes/8.obj")
{
    int color_count = 0;
    string line, mark;
    ifstream in(file_name);
    vector<vector3d> points, normals;
    flat f;
    double x, y, z;

    if(in.is_open())
    {
        while(getline(in, line))
        {
            stringstream ss(line);
            ss >> mark;
            
            if(mark == "o") 
            {
                objects_pool.push_back(object(colors_pool[color_count % size(colors_pool)]));
                color_count++;
            }
            else if(mark == "v")
            {
                ss >> x >> y >> z;
                view_sp.max_x = max(x, view_sp.max_x);
                view_sp.max_y = max(y, view_sp.max_y);
                view_sp.max_z = max(z, view_sp.max_z);
                view_sp.min_x = min(x, view_sp.min_x);
                view_sp.min_y = min(y, view_sp.min_y);
                view_sp.min_z = min(z, view_sp.min_z);
                points.push_back(vector3d(x, y, z));
            }
            else if(mark == "vn")
            {
                ss >> x >> y >> z;
                normals.push_back(vector3d(x, y, z));
            }
            else if(mark == "f")
            {
                pair<int, int> ids;
                string s;
                for(int i = 0; i < size(f.v); i++)
                {
                    ss >> s;
                    ids = parse(s);
                    f.v[i].points = points[ids.first];
                    f.v[i].normals = normals[ids.second];
                }
                objects_pool.back().flats.push_back(f);
            }
        }
    }
    in.close();
}