#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include "roots/Screen.hpp"

enum SettingsType { OPT_NONE, OPT_VIDEO, OPT_AUDIO, OPT_CONTROLS, OPT_INTERFACE, OPT_GAMEPLAY };

class Options : public Screen {

    public:
        
        Options();

        void Init() override;
        void Update() override;
        void Draw() override;

        void DrawButtons(int, int);
        void DrawVideo(int, int);
        void DrawAudio(int, int);
        void DrawControls(int, int);
        void DrawInterface(int, int);
        void DrawGameplay(int, int); // Language

    private:

        SettingsType settingsType;

};

#endif