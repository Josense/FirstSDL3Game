#pragma once
#include "Button.h"
#include "GreenRectangle.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_surface.h"


class UI {
public:
    void Render(SDL_Surface* Surface) const {
        A.Render(Surface);
        B.Render(Surface);
        C.Render(Surface);
    }

    void HandleEvent(const SDL_Event& Event) {
        A.HandleEvent(Event);
        B.HandleEvent(Event);
        C.HandleEvent(Event);
    }

    void SetRectangleColors(const SDL_Color& Color) {
        A.SetColor(Color);
        B.SetColor(Color);
    }


private:
    Rectangle A{SDL_Rect{50, 50, 50, 50}};
    Rectangle B{SDL_Rect{150, 50, 50, 50}};
    Button C{*this, SDL_Rect{250, 50, 50, 50}};
};
