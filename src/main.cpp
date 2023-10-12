#include <SDL2/SDL.h>
#include <GL/glew.h>
// #include <iostream>

bool success = false;

int main(int argv, char* args[]) {
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

    SDL_Window* win = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init failed: %s", SDL_GetError());
        return 1;
    }

    win = SDL_CreateWindow("open gl moment", 
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
    640, 360, 
    SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);

    SDL_Delay(1000);
    
    return 0;
}