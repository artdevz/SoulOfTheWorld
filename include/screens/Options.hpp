#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include "roots/Screen.hpp"
#include "raylib.h"

#include <array>

enum SettingsType { OPT_NONE, OPT_CONTROLS, OPT_VIDEO, OPT_AUDIO, OPT_INTERFACE, OPT_GAMEPLAY };

class Options : public Screen {

    public:
        
        static std::vector<std::pair<Rectangle, void(*)()>> buttons;

        static std::array<Rectangle, 5> optionsButtons;
        static std::array<Rectangle, 6> resolutionButtons;
        static std::array<Rectangle, 3> displayButtons;
        static std::array<Rectangle, 6> fpsButtons;
        
        static std::array<Vector2, 6> resolutionOptions;
        static std::array<std::string, 3> displayOptions;
        static std::array<int, 5> fpsOptions;

        Options();

        void Init() override;
        void Update() override;
        void Draw() override;

        void DrawButtons(int, int);
        void DrawBack(int, int);

        void DrawControls();
        void DrawVideo(int, int);
        void DrawAudio(int, int);
        void DrawInterface(int, int);
        void DrawGameplay(int, int); // Language

    private:

        static bool fpsUnlimited;

        static bool resolutionDropdownBoxState;
        static bool displayDropdownBoxState;
        static bool fpsCapDropdownBoxState;

        SettingsType settingsType;

};

#endif