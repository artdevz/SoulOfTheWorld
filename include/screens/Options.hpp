#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include "roots/Screen.hpp"
#include "raylib.h"

#include <array>

enum SettingsType { OPT_NONE, OPT_CONTROLS, OPT_VIDEO, OPT_AUDIO, OPT_INTERFACE, OPT_GAMEPLAY };

class Options : public Screen {

    public:
        
        static std::array<Vector2, 6> resolutionOptions;
        static std::array<std::string, 3> displayOptions;
        static std::array<int, 6> fpsOptions;

        Options();

        void Init() override;
        void Update() override;
        void Draw() override;

        void DrawButtons(int, int);
        void DrawBack(int, int);

        void DrawControls(int, int);
        void DrawVideo(int, int);
        void DrawAudio(int, int);
        void DrawInterface(int, int);
        void DrawGameplay(int, int); // Language

    private:

        static bool resolutionDropdownBoxState;
        static bool displayDropdownBoxState;

        SettingsType settingsType;

};

#endif