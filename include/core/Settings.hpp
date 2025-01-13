#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include "raylib.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

enum Display { DP_WINDOWED, DP_BORDERLESS, DP_FULLSCREEN };

// class Window; // Forward de Window

class Settings {

    public:
        
        static json ReadSettings();        
        static void SaveSettings();

        static int GetWidth();
        static int GetHeight();
        static void SetResolution(Vector2);

        static int GetFpsCap();
        static void SetFpsCap(int);

        static int GetDisplayState();
        static void SetDisplayState(Display);

    private:
    
        static json settings;
        static std::string gameSettingsFile;

};

#endif