#pragma once
#include <iostream>
#include <ostream>
#include <string>

#include "Rectangle.h"
#include "UserEvents.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_rect.h"

class UI;

class Button : public Rectangle {
public:
    Button(UI& UIManager, const SDL_Rect& Rect):UIManager {UIManager}, Rectangle { Rect } {
        SetColor({255, 165, 0, 255});
    }

    void HandleEvent(const SDL_Event& Event) override {
        Rectangle::HandleEvent(Event);
        using namespace UserEvents;
        if (Event.type == CLOSE_SETTINGS) {
            isSettingsOpen = false;
        } else if (Event.type == OPEN_SETTINGS) {
            isSettingsOpen = true;
        }
    }

    void OnLeftClick() override;

    UserEvents::SettingsConfig GetConfig() { return Config; }

    // Where is this button located?
    static std::string GetLocation() {
        return "The Main Menu";
    }

private:
    UI& UIManager;
    bool isSettingsOpen { false };
    UserEvents::SettingsConfig Config { UserEvents::SettingsPage::GAMEPLAY,50, 100 };
};
