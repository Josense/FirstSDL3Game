#pragma once
#include <iostream>
#include <ostream>
#include <SDL3/SDL.h>

class Window {
public:
    Window() {
        // 窗口名称、宽度、高度、窗口可调整大小且可最小化
        SDLWindow = SDL_CreateWindow(
            "Hello Window",
            GetWidth(), GetHeight(),
            SDL_WINDOW_RESIZABLE | SDL_WINDOW_MINIMIZED
        );
    }

    int GetWidth() const { return 800; }
    int GetHeight() const { return 300; }

    void Render() {
        // 从 surface 获取到当前硬件表现像素颜色的格式信息
        const SDL_PixelFormatDetails* FmtDetails { SDL_GetPixelFormatDetails(GetSurface()->format) };

        //判断格式是否支持 alpha 通道
        // if (FmtDetails->Amask) {
        //     std::cout << "Alpha is Supported" << std::endl;
        // } else {
        //     std::cout << "No Alpha Supported" << std::endl;
        // }

        // 创建一个红色颜色
        Uint32 RedColor { SDL_MapRGB(FmtDetails, nullptr, 50, 50, 50) };

        // 绘制到当前窗口的 surface 上
        SDL_FillSurfaceRect(GetSurface(), nullptr, RedColor);
    }

    void Update() {
        // 更新才能让绘制生效
        SDL_UpdateWindowSurface(SDLWindow);
    }

    [[nodiscard]] SDL_Surface* GetSurface() const {
        return SDL_GetWindowSurface(SDLWindow);
    }

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    ~Window() {
        if (SDLWindow != nullptr && SDL_WasInit(SDL_INIT_VIDEO)) {
            SDL_DestroyWindow(SDLWindow);
        } else {
            std::cout << "Skipping SDL_DestroyWindow" << std::endl;
        }
    }

private:
    SDL_Window* SDLWindow { nullptr };
};