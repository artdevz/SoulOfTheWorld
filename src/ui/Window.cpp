#include "raylib.h"
#include "ui/Window.hpp"
#include "core/Settings.hpp"

Vector2 Window::resolution = {0, 0};

Window::Window() {}

Window::Window(int width, int height, int fps, std::string title) {

    resolution = {(float)width, (float)height};

    InitWindow(width, height, title.c_str());
    
    SetDisplay((Display)Settings::GetDisplayState());
    SetTargetFPS(fps);
    // SetExitKey(KEY_NULL);

}

void Window::SetDisplay(Display display) {

    SetWindowSize(resolution.x, resolution.y);

    switch (display) {

        case DP_WINDOWED:
            if (IsWindowFullscreen()) ToggleFullscreen();
            if (IsWindowState(FLAG_BORDERLESS_WINDOWED_MODE)) SetWindowState(FLAG_WINDOW_MAXIMIZED);
            break;

        // case DP_BORDERLESS:          
        //     if (!IsWindowState(FLAG_BORDERLESS_WINDOWED_MODE)) SetWindowState(FLAG_BORDERLESS_WINDOWED_MODE);
        //     break;

        case DP_FULLSCREEN:
            if (!IsWindowFullscreen()) ToggleFullscreen();
            break;
        
        default:
            break;

    }

}