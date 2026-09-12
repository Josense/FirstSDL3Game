#pragma once
#include <MacTypes.h>

#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_rect.h"


class GreenRectangle: public Rectangle {
public:
    GreenRectangle(const SDL_Rect& rectangle): Rectangle {rectangle} {
        SetColor(SDL_Color {0, 255, 0, 255});
        SetHoverColor(SDL_Color {255, 0, 0, 255});
    };
};
