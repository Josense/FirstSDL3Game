#pragma once
#include "SDL3/SDL_surface.h"
#include "SDL3/SDL_events.h"

class Rectangle {
public:
    Rectangle(const SDL_Rect& Rect): Rect {Rect} {}

    virtual ~Rectangle() = default;

    void Render(SDL_Surface* Surface) const {
        const auto* Fmt = SDL_GetPixelFormatDetails(Surface->format);
        const Uint32 Color = isPointerHovering
            ? SDL_MapRGB(Fmt, nullptr, mHoverColor.r, mHoverColor.g, mHoverColor.b)
            : SDL_MapRGB(Fmt, nullptr, mColor.r, mColor.g, mColor.b);
        SDL_FillSurfaceRect(Surface, &Rect, Color);
    }

    virtual void OnMouseEnter() {}
    virtual void OnMouseExit() {}
    virtual void OnLeftClick() {}

    void HandleEvent(const SDL_Event& Event) {
        if (Event.type == SDL_EVENT_MOUSE_MOTION) {
            bool wasPointerHovering { isPointerHovering };
            isPointerHovering = isWithinRect(static_cast<int>(Event.motion.x), static_cast<int>(Event.motion.y));
            if (wasPointerHovering && !isPointerHovering) {
                OnMouseExit();
            } else if (!wasPointerHovering && isPointerHovering) {
                OnMouseEnter();
            }
        } else if (Event.type == SDL_EVENT_WINDOW_MOUSE_LEAVE) {
            if (isPointerHovering) {
                OnMouseExit();
            }
            isPointerHovering = false;
        } else if (Event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
            if (isPointerHovering && Event.button.button == SDL_BUTTON_LEFT) {
                OnLeftClick();
            }
        }
    }

    void SetColor(const SDL_Color color) {
        mColor = color;
    }

    [[nodiscard]] SDL_Color GetColor() const { return mColor; }

    void SetHoverColor(const SDL_Color color) { mHoverColor = color; }

    [[nodiscard]] SDL_Color GetHoverColor() const { return mHoverColor; }

private:
    SDL_Rect Rect;
    SDL_Color mColor { SDL_Color {255, 0, 0, 255 } };
    SDL_Color mHoverColor { SDL_Color {0, 255, 0, 255 } };
    bool isPointerHovering { false };

    [[nodiscard]] bool isWithinRect(int x, int y) const {
      return x >= Rect.x && x < Rect.x + Rect.w && y >= Rect.y && y < Rect.y + Rect.h;
    };
};
