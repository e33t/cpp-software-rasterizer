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

static void load_scene(string file_name = "scenes/8.obj")
{
    string line, mark;
    ifstream in(file_name);
    vector<vector3d> points, normals;
    vector3d p;
    flat f;

    if(in.is_open())
    {
        while(getline(in, line))
        {
            stringstream ss(line);
            ss >> mark;
            
            if(mark == "o") objects_pool.push_back(object(COLOR_GREY));
            else if(mark == "v")
            {
                ss >> p.x >> p.y >> p.z;
                points.push_back(p);
            }
            else if(mark == "vn")
            {
                ss >> p.x >> p.y >> p.z;
                normals.push_back(p);
            }
            else if(mark == "f")
            {
                pair<int, int> ids;
                string s;
                for(int i = 0; i < 3; i++)
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