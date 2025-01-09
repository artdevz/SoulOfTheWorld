#include "core/Settings.hpp"
#include "ui/Window.hpp"

#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

std::string Settings::gameSettingsFile = "assets/GameSettings.json";

json Settings::settings;

json Settings::ReadSettings() {

    std::ifstream inputFile(gameSettingsFile);
    if (!inputFile.is_open()) throw std::runtime_error("Failed to read GameSettings.json");
    
    inputFile >> settings;
    return settings;

}

void Settings::StorageSettings() {

    std::ifstream inputFile(gameSettingsFile);
    if (!inputFile.is_open()) throw std::runtime_error("Failed to store in GameSettings.json");

    inputFile >> settings;
    inputFile.close();

}

void Settings::SaveSettings() {

    std::ofstream outputFile(gameSettingsFile);
    if (!outputFile.is_open()) throw std::runtime_error("Failed to save GameSettings.json");

    outputFile << settings.dump(4);
    outputFile.close();

}

int Settings::GetWidth() {

    try {
        return ReadSettings()["video"]["width"];
    }

    catch (...) {        
        return 1;
    }

}

int Settings::GetHeight() {

    try {
        return ReadSettings()["video"]["height"];
    }

    catch (...) {        
        return 1;
    }

}

int Settings::GetFpsCap() {

    try {
        return ReadSettings()["video"]["fpsCap"];
    }

    catch (...) {        
        return 1;
    }

}

int Settings::GetDisplayState() {

    try {        
        return ReadSettings()["video"]["display"];
    }
    catch(...)
    {
        return -1;
    }

}

void Settings::SetDisplayState(Display display) {

    StorageSettings();
    settings["video"]["display"] = display;
    SaveSettings();

    Window::SetDisplay(display);

}