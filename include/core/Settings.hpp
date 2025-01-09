#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <nlohmann/json.hpp>
using json = nlohmann::json;

enum Display { DP_WINDOWED, DP_BORDERLESS, DP_FULLSCREEN };

class Settings {

    public:

        static json LoadSettings();

        static int GetWidth();
        static int GetHeight();
        static int GetFpsCap();
        static std::string GetDisplayState();
        static void SetDisplayState();

    private:
    
};

#endif