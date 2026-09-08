#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Window.h"

void HandleMotionEvent(SDL_MouseMotionEvent& Event, Window& GameWindow) {
    std::cout << "Mouse Motion Detected - "
        << "x: " << Event.x
        << ", y: " << Event.y;

    std::cout << "\n  Distance from Right: "
        << static_cast<float>(GameWindow.GetWidth()) - Event.x;

    std::cout << "\n  Distance from Bottom: "
        << static_cast<float>(GameWindow.GetHeight()) - Event.y << '\n';
}

void HandleButtonEvent(SDL_MouseButtonEvent& Event) {
    if (Event.button == SDL_BUTTON_RIGHT) {
        std::cout << "Right Click or Release\n";
    }

    if (Event.button == SDL_BUTTON_LEFT &&
        Event.down &&
        Event.clicks >= 2
    ) {
        std::cout << "Left Double Click\n";
    }
}


int main(int, char**) {

    // Initialization
    SDL_Init(SDL_INIT_VIDEO);

    Window GameWindow;

    // Loop
    bool IsRunning = true;
    SDL_Event Event;
    while (IsRunning) {
        while (SDL_PollEvent(&Event)) {
            if (Event.type == SDL_EVENT_MOUSE_MOTION) {
                HandleMotionEvent(Event.motion, GameWindow);
            } else if (Event.type == SDL_EVENT_WINDOW_MOUSE_ENTER) {
                std::cout << "Mouse Entered Window" << std::endl;
            } else if (Event.type == SDL_EVENT_WINDOW_MOUSE_LEAVE) {
                std::cout << "Mouse Left Window" << std::endl;
            } else if (Event.type == SDL_EVENT_MOUSE_BUTTON_DOWN || Event.type == SDL_EVENT_MOUSE_BUTTON_UP) {
                HandleButtonEvent(Event.button);
            } else if (Event.type == SDL_EVENT_QUIT) {
                IsRunning = false;
            }
        }

        GameWindow.Render();

        GameWindow.Update();
    }

    // Shutdown
    SDL_Quit();
    return 0;
}
