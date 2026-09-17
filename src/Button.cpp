#include "Button.h"
#include "UI.h"

void Button::OnLeftClick() {
    UIManager.SetRectangleColors(SDL_Color{0, 255, 0, 255});

    using namespace UserEvents;
    SDL_Event Event { .type = isSettingsOpen ? CLOSE_SETTINGS : OPEN_SETTINGS };
    if (Event.type == OPEN_SETTINGS) {
        Event.user.data1 = this;
    }
    SDL_PushEvent(&Event);
}
