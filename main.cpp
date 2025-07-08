#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_mouse.h>
#include <cmath>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#define COLOR_WHITE 0xFFFFFFFF
#define COLOR_GREY 0x666666FF
#define COLOR_RED 0xFF0000FF
#define COLOR_GREEN 0x00FF00FF
#define COLOR_BLUE 0x0000FFFF
#define COLOR_BLACK 0x000000FF

#define WINDOW_WIDTH 1440
#define WINDOW_HEIGHT 900

struct point
{
    double x, y, z;
};

struct flat
{
    point v[3];
    point vn[3];
};

class object
{
public:
    Uint32 color;
    std::vector<flat> flats;
    object(Uint32 color)
    {
        this->color = color;
    }
    void show()
    {
        std::cout << "-----------------------------------" << std::endl;
        for (flat f : flats)
        {
            for(int i = 0; i < 3; i++) std::cout << "v" << i+1 << ": " << f.v[i].x << " " << f.v[i].y << " " << f.v[i].z << std::endl;
            for(int i = 0; i < 3; i++) std::cout << "vn" << i+1 << ": " << f.vn[i].x << " " << f.vn[i].y << " " << f.vn[i].z << std::endl;
        }
        std::cout << "-----------------------------------" << std::endl;
    }
};

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;
std::vector<object> objects_pool;

static std::pair<int, int> parse(std::string positions)
{
    std::string vi, vni;
    std::stringstream ss(positions);
    getline(ss, vi, '/');
    getline(ss, vni, '/');
    getline(ss, vni, '/');
    return {std::stoi(vi)-1, std::stoi(vni)-1};
}

static void load_scene(std::string file_name = "8.obj")
{
    std::string line, mark;
    std::ifstream in(file_name);
    std::vector<point> vertexes, normals;
    point p;
    flat f;

    if(in.is_open())
    {
        while(std::getline(in, line))
        {
            std::stringstream ss(line);
            ss >> mark;
            
            if(mark == "o") objects_pool.push_back(object(COLOR_GREY));
            else if(mark == "v")
            {
                ss >> p.x >> p.y >> p.z;
                vertexes.push_back(p);
            }
            else if(mark == "vn")
            {
                ss >> p.x >> p.y >> p.z;
                normals.push_back(p);
            }
            else if(mark == "f")
            {
                std::pair<int, int> ids;
                std::string s;
                for(int i = 0; i < 3; i++)
                {
                    ss >> s;
                    ids = parse(s);
                    f.v[i] = vertexes[ids.first];
                    f.vn[i] = normals[ids.second];
                }
                objects_pool.back().flats.push_back(f);
            }
        }
    }
    in.close();
}

static void draw_pixel(int x, int y, Uint32 color, Uint32* pixels)
{
    pixels[y * WINDOW_WIDTH + x] = color;
}

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("lab1", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!texture) {
        SDL_Log("Couldn't create streaming texture: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    
    load_scene("8.obj");
    for(object obj : objects_pool) obj.show();

    return SDL_APP_CONTINUE;  
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    switch (event->type)
    {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
        break;
    }
    return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppIterate(void *appstate)
{

    // Uint32* pixels = nullptr;
    // int pitch = 0;
    // if (SDL_LockTexture(texture, NULL, (void**)&pixels, &pitch)) 
    // {	
        
    //     SDL_UnlockTexture(texture);
    // }
    // SDL_RenderTexture(renderer, texture, NULL, NULL);
    // SDL_RenderPresent(renderer); 

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    SDL_DestroyTexture(texture);
}