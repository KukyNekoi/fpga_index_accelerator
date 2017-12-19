//
// Created by Erik Andrés Regla Torres on 3/28/16.
//

#ifndef METRICHASHING_SCREEN_H
#define METRICHASHING_SCREEN_H

#include <SDL2/SDL.h>
#include <iostream>
#include "../etc/Macros.h"

class Screen{
protected:
public:
    Screen(int w=640, int h=480);
    void draw_dot(double x, double y, int size = 1, char r=0x00, char g=0x00, char b=0x00);
    void clear();
    void update();
    ~Screen();
private:
    int screen_width;
    int screen_height;
    SDL_Window* gWindow = NULL;
    SDL_Renderer* gRenderer = NULL;

};


#endif //METRICHASHING_SCREEN_H
