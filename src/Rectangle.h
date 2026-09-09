#pragma once
#include <iostream>

#include "SDL3/SDL_surface.h"


class Rectangle {
public:
    Rectangle(const SDL_Rect& Rect, const SDL_PixelFormatDetails* Fmt) :
    Rect {Rect},
    mColor {SDL_MapRGB(Fmt, nullptr, 255, 0, 0) } {}

    void Render(SDL_Surface* Surface) const {
        const auto* Fmt = SDL_GetPixelFormatDetails(Surface->format);
        SDL_FillSurfaceRect(Surface, &Rect, isPointerHovering ? mHoverColor : mColor);
    }

    void HandleEvent(const SDL_Event& Event) {
        if (Event.type == SDL_EVENT_MOUSE_MOTION) {
            isPointerHovering = isWithinRect(static_cast<int>(Event.motion.x), static_cast<int>(Event.motion.y));
        } else if (Event.type == SDL_EVENT_WINDOW_MOUSE_LEAVE) {
            isPointerHovering = false;
        } else if (Event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            if (isPointerHovering && Event.button.button == SDL_BUTTON_LEFT) {
                std::cout << "A left-click happened on me!" << std::endl;
            }
        }
    }

    void SetColor(const Uint32 color) {
        mColor = color;
    }

    [[nodiscard]] Uint32 GetColor() const { return mColor; }

    void SetHoverColor(const Uint32 color) { mHoverColor = color; }

    [[nodiscard]] Uint32 GetHoverColor() const { return mHoverColor; }

private:
    SDL_Rect Rect;
    Uint32 mColor;
    Uint32 mHoverColor;
    bool isPointerHovering { false };

    [[nodiscard]] bool isWithinRect(int x, int y) const {
      return x >= Rect.x && x < Rect.x + Rect.w && y >= Rect.y && y < Rect.y + Rect.h;
    };
};
