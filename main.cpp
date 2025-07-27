#define SDL_MAIN_USE_CALLBACKS 1

#include "headers/headers.hpp"
#include <SDL3/SDL_main.h>

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("3D", WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!texture) {
        SDL_Log("Couldn't create streaming texture: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    load_scene("scenes/8.obj");
    form_transformation_matrix();

    return SDL_APP_CONTINUE;  
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    switch (event->type)
    {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
        break;
    case SDL_EVENT_KEY_DOWN:
        SDL_Keycode sym = event->key.key;
        switch (sym)
        {
        case SDLK_W:
            cam.rotate_x_up();
            break;
        case SDLK_A:
            cam.rotate_y_left();
            break;
        case SDLK_S:
            cam.rotate_x_down();
            break;
        case SDLK_D:
            cam.rotate_y_right();
            break;
        case SDLK_Q:
            cam.rotate_z_clock();
            break;
        case SDLK_E:
            cam.rotate_z_counterclock();
            break;
        case SDLK_R:
            cam.angle_x = 0;
            cam.angle_y = 0;
            cam.angle_z = 0;
            break;
        }
        break;
    }
    return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppIterate(void *appstate)
{

    Uint32* pixels = nullptr;
    int pitch = 0;
    if (SDL_LockTexture(texture, NULL, (void**)&pixels, &pitch)) 
    {	
        draw_frame(pixels);
        SDL_UnlockTexture(texture);
    }
    SDL_RenderTexture(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    // return SDL_APP_SUCCESS;
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    SDL_DestroyTexture(texture);
}