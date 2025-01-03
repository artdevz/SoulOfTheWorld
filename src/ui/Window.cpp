#include "raylib.h"
#include "ui/Window.hpp"

Vector2 Window::resolution = {0, 0};

Window::Window() {}

Window::Window(int width, int height, int fps, std::string title) {

    resolution = {(float)width, (float)height};

    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());
    // SetExitKey(KEY_NULL);

}