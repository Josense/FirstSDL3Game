#pragma once
#include "GreenRectangle.h"
#include "SDL3/SDL_events.h"
#include "SDL3/SDL_surface.h"


class UI {
public:
    UI() {
        int Row {5}, Column {12};
        Rectangles.reserve(Row * Column);
        for ( int R = 0; R < Row; R++ ) {
            for ( int C = 0; C < Column; C++ ) {
                const bool useGreen { (R + C) % 2 == 0};
                Rectangles.emplace_back(
                    useGreen
                    ? std::make_unique<GreenRectangle>(SDL_Rect {C * 60, R * 60, 50, 50})
                    :std::make_unique<Rectangle>(SDL_Rect {C * 60, R * 60, 50, 50})
                );
            }
        }
    }

    void Render(SDL_Surface* Surface) const {
        for (auto& rectangle : Rectangles) {
            rectangle->Render(Surface);
        }
    }

    void HandleEvent(const SDL_Event& Event) {
        for (auto& rectangle : Rectangles) {
            rectangle->HandleEvent(Event);
        }
    }


private:
    std::vector<std::unique_ptr<Rectangle>> Rectangles;
};
