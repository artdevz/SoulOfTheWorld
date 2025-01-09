#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <nlohmann/json.hpp>
using json = nlohmann::json;

enum Display { DP_WINDOWED, DP_BORDERLESS, DP_FULLSCREEN };

// class Window; // Forward de Window

class Settings {

    public:
        
        static json ReadSettings();
        static void StorageSettings();
        static void SaveSettings();

        static int GetWidth();
        static int GetHeight();
        static int GetFpsCap();
        static int GetDisplayState();
        static void SetDisplayState(Display);

    private:
    
        static json settings;
        static std::string gameSettingsFile;

};

#endif