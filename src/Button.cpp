#include "Button.h"
#include "UI.h"

void Button::OnLeftClick() {
    UIManager.SetRectangleColors(SDL_Color{0, 255, 0, 255});
}
