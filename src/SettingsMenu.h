#pragma once
#include <iostream>

#include "UserEvents.h"
#include "SDL3/SDL_events.h"

class SettingsMenu {
public:
    void HandleEvent(SDL_Event& Event) {
        using namespace UserEvents;
        if (Event.type == OPEN_SETTINGS || Event.type == CLOSE_SETTINGS) {
            HandleUserEvent(Event.user);
        }
    }


    void Render(SDL_Surface* Surface) const {
        if (!isOpen) return;
        const auto* Fmt = SDL_GetPixelFormatDetails(Surface->format);
        SDL_FillSurfaceRect(Surface, &Rect, SDL_MapRGB(Fmt, nullptr, Color.r, Color.g, Color.b));
    }

private:
    void HandleUserEvent(SDL_UserEvent& Event) {
        using namespace UserEvents;
        if (Event.type == OPEN_SETTINGS) {
            isOpen = true;

            auto* Instigator{
                static_cast<Button*>(Event.data1)
              };

            std::cout << "I was opened from a button in "
               << Instigator->GetLocation() << "\n";

            Rect.x = Instigator->GetConfig().x;
            Rect.y = Instigator->GetConfig().y;
            if (
              Instigator->GetConfig().Page ==
                SettingsPage::GAMEPLAY
            ) {
                std::cout << "Page: Gameplay Settings\n";
            }
        } else if (Event.type == CLOSE_SETTINGS) {
            isOpen = false;
        }
    }

    bool isOpen { false };
    SDL_Rect Rect{100, 50, 200, 200};
    SDL_Color Color{150, 150, 150, 255};
};
