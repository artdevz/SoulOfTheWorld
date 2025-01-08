#include "core/Settings.hpp"

#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

json Settings::LoadSettings() {

    std::ifstream file("assets/GameSettings.json");
    if (!file.is_open()) throw std::runtime_error("Failed to open GameSettings.json");
    
    json jsonData;
    file >> jsonData;
    return jsonData;

}

int Settings::GetWidth() {

    try {
        return LoadSettings()["video"]["width"];
    }

    catch (...) {        
        return 1;
    }

}

int Settings::GetHeight() {

    try {
        return LoadSettings()["video"]["height"];
    }

    catch (...) {        
        return 1;
    }

}

int Settings::GetFpsCap() {

    try {
        return LoadSettings()["video"]["fpsCap"];
    }

    catch (...) {        
        return 1;
    }

}