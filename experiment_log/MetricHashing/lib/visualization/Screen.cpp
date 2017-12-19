//
// Created by Erik Andrés Regla Torres on 3/28/16.
//

#include "Screen.h"
Screen::Screen(int w, int h){
    this->screen_width = w;
    this->screen_height = h;

    V_DEBUG(
            VARDUMP(this->screen_width);
            VARDUMP(this->screen_height);
    )
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    else{
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
            printf( "Warning: Linear texture filtering not enabled!" );
        this->gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->screen_width, this->screen_height, SDL_WINDOW_SHOWN );
        if( this->gWindow == NULL )
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        else{
            gRenderer = SDL_CreateRenderer( this->gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        }
    }
}

void Screen::draw_dot(double x, double y, int size, char r, char g, char b){
    SDL_SetRenderDrawColor( this->gRenderer, r,g,b, 0xFF );
    int start_x = x*this->screen_width;
    int start_y = y*this->screen_height;
    V_DEBUG(
            std::cout << "Drawing at " << start_x << "," << start_y << std::endl;
    )
    SDL_Rect pixel = {start_x - (size/2), start_y - (size/2), size, size};
    SDL_RenderFillRect( this->gRenderer, &pixel );
}

void Screen::clear(){
    SDL_SetRenderDrawColor( this->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( this->gRenderer );
}

void Screen::update(){
    SDL_RenderPresent( gRenderer );
}

Screen::~Screen(){}
