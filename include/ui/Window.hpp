#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "raylib.h"
#include "core/Settings.hpp"

#include <string>

class Window {

    public:

        static Vector2 resolution;

        Window();
        Window(int, int, int, std::string);
        
        ~Window();

        static void SetResolution(int, int);
        static void SetDisplay(Display);

        // static Vector2 GetResolution();
        // void SetResolution(Vector2);

    private:

};

#endif