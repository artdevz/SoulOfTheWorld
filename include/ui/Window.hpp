#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

class Window {

    public:

        static Vector2 resolution;

        Window();
        Window(int width, int height, int fps, std::string title);
        // ~Window();

        // static Vector2 GetResolution();
        // void SetResolution(Vector2);

    private:

};

#endif