#pragma once
#include "Rectangle.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_surface.h"

class UI;

class Button : public Rectangle {
public:
    Button(UI& UIManager, const SDL_Rect& Rect):UIManager {UIManager}, Rectangle { Rect } {
        SetColor({255, 165, 0, 255});
    }

    void OnLeftClick() override;


private:
    UI& UIManager;
};
