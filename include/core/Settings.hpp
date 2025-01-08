#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Settings {

    public:

        static json LoadSettings();

        static int GetWidth();
        static int GetHeight();
        static int GetFpsCap();

    private:
    
};

#endif