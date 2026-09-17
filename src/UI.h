#pragma once
#include "Button.h"
#include "GreenRectangle.h"
#include "SettingsMenu.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_surface.h"


class UI {
public:
    void Render(SDL_Surface* Surface) const {
        SettingsButton.Render(Surface);
        Settings.Render(Surface);
    }

    void HandleEvent(SDL_Event& Event) {
        SettingsButton.HandleEvent(Event);
        Settings.HandleEvent(Event);
    }

    void SetRectangleColors(const SDL_Color& Color) {

    }


private:

    Button SettingsButton {*this, SDL_Rect{250, 50, 50, 50}};
    SettingsMenu Settings;
};
