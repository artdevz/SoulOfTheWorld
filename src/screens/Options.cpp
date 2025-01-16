#include "raylib.h"
#include "core/Settings.hpp"
#include "screens/Options.hpp"
#include "ui/Window.hpp"

std::array<Rectangle, 5> Options::optionsButtons;
std::array<Rectangle, 6> Options::resolutionButtons;
std::array<Rectangle, 3> Options::displayButtons;
std::array<Rectangle, 6> Options::fpsButtons;

std::array<Vector2, 6> Options::resolutionOptions = { Vector2 { 720, 480 }, { 1280, 720 }, { 1600, 900 }, { 1920, 1080 }, { 2560, 1440 }, { 3840, 2160 } };
std::array<std::string, 3> Options::displayOptions = {"Windowed", "Borderless", "Fullscreen"};
std::array<int, 5> Options::fpsOptions = { 30, 60, 120, 144, 240 };

bool Options::fpsUnlimited;

bool Options::resolutionDropdownBoxState = false;
bool Options::displayDropdownBoxState = false;
bool Options::fpsCapDropdownBoxState = false;

Options::Options() {    
    settingsType = OPT_NONE;    
    TraceLog(LOG_INFO, "Criado a Options");
}

void Options::Init() {

    int width = Window::resolution.x, height = Window::resolution.y;

    fpsUnlimited = Settings::GetUnlimitedFps();

    optionsButtons = { Rectangle

        { width/5.49f, height/4.5f, width/8.0f, height/13.5f }, // Controls
        { width/3.20f, height/4.5f, width/8.0f, height/13.5f }, // Video
        { width/2.26f, height/4.5f, width/8.0f, height/13.5f }, // Audio
        { width/1.75f, height/4.5f, width/8.0f, height/13.5f }, // Interface
        { width/1.42f, height/4.5f, width/8.0f, height/13.5f }  // Language

    };

    resolutionButtons = { Rectangle

        { 640, 400, 200, 40 },  // 720x480
        { 640, 440, 200, 40 },  // 1280x720
        { 640, 480, 200, 40 },  // 1600x900
        { 640, 520, 200, 40 },  // 1920x1080
        { 640, 560, 200, 40 },  // 2560x1440
        { 640, 600, 200, 40 }   // 3840x2160

    };

    displayButtons = { Rectangle
    
        { 640, 470, 200, 40 },  // Windowed
        { 640, 510, 200, 40 },  // Borderless
        { 640, 550, 200, 40 }   // Fullscreen

    };

    fpsButtons = { Rectangle 
    
        { 640, 610, 200, 40 },  // 30 FPS
        { 640, 650, 200, 40 },  // 60 FPS
        { 640, 690, 200, 40 },  // 120 FPS
        { 640, 730, 200, 40 },  // 144 FPS
        { 640, 770, 200, 40 }   // 240 FPS

    };  

}

void Options::Update() {

    Screen::screenType = SCR_OPTIONS;
    
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

        // Options
        for (int i = 0; i < (int)optionsButtons.size(); i++) if (CheckCollisionPointRec(GetMousePosition(), optionsButtons[i])) settingsType = (SettingsType)(i+1);
        
        // BackToMenu
        if (CheckCollisionPointRec(GetMousePosition(), { 350, 730, 240, 80 } )) Screen::screenType = SCR_MAIN;

        // Resolution
        if (CheckCollisionPointRec(GetMousePosition(), { 640, 360, 200, 40} )) resolutionDropdownBoxState = !resolutionDropdownBoxState;        
        if (resolutionDropdownBoxState) for (int i = 0; i < (int)resolutionButtons.size(); i++) if (CheckCollisionPointRec(GetMousePosition(), resolutionButtons[i])) Settings::SetResolution(resolutionOptions[i]);

        // Display
        if (CheckCollisionPointRec(GetMousePosition(), { 640, 430, 200, 40} ) && !resolutionDropdownBoxState) displayDropdownBoxState = !displayDropdownBoxState;
        if (displayDropdownBoxState) for (int i = 0; i < (int)displayButtons.size(); i++) if (CheckCollisionPointRec(GetMousePosition(), displayButtons[i])) Settings::SetDisplayState((Display)i);

        // Fps
        if (CheckCollisionPointRec(GetMousePosition(), { 640, 505, 30, 30 } ) && !(resolutionDropdownBoxState && displayDropdownBoxState)) {
            Settings::SetUnlimitedFps(fpsUnlimited); // 2147483647 = MaxInt
            fpsUnlimited = !fpsUnlimited;
        }
        if (CheckCollisionPointRec(GetMousePosition(), { 640, 570, 200, 40 } ) && !(resolutionDropdownBoxState && displayDropdownBoxState)) fpsCapDropdownBoxState = !fpsCapDropdownBoxState;
        if (fpsCapDropdownBoxState) for (int i = 0; i < (int)fpsButtons.size(); i++) if (CheckCollisionPointRec(GetMousePosition(), fpsButtons[i])) Settings::SetFpsCap(fpsOptions[i]);

        // Close Boxes
        if (!(CheckCollisionPointRec(GetMousePosition(), { 640, 360, 200, 40} ))) resolutionDropdownBoxState = false;
        if (!(CheckCollisionPointRec(GetMousePosition(), { 640, 430, 200, 40} ))) displayDropdownBoxState = false;

    }

    Draw();

}

void Options::Draw() {

    int width = Window::resolution.x, height = Window::resolution.y;
    DrawFPS( width / 1.05f, height / 72.0f);
    BeginDrawing();

    ClearBackground(Color{ 0x14, 0x16, 0x20, 255});

    DrawText("Options", (int)(width / 2 - MeasureText("Options", width/20) / 2) , (int)height / 24, width/20, Color{ 0xE0, 0xA5, 0x26, 255});

    DrawButtons(width, height);
    DrawBack(width, height);

    switch (settingsType) {

        case OPT_NONE: break;

        case OPT_CONTROLS: DrawControls(width, height); break;
        case OPT_VIDEO: DrawVideo(width, height); break;
        case OPT_AUDIO: DrawAudio(width, height); break;
        case OPT_INTERFACE: DrawInterface(width, height); break;
        case OPT_GAMEPLAY: DrawGameplay(width, height); break;

    }

    EndDrawing();

}

void Options::DrawButtons(int width, int height) {
    
    const char* texts[] = { "Controls", "Video", "Audio", "Interface", "Language"};
    float posX[] = { width/5.49f, width/3.2f, width/2.26f, width/1.75f, width/1.42f };

    for (int i = 0; i < 5; i++) {

        DrawRectangleRec( { posX[i], height/4.5f, width/8.0f, height/13.5f }, Color{ 0x0D, 0x0F, 0x19, 255} );
        DrawText(texts[i], posX[i] + (height / 4.5f - MeasureText(texts[i], 24)) / 2.0f, height/4.5f + (height / 13.5f - 24) / 2.0f, 24, RAYWHITE);

    }

    DrawRectangleRec( {1500, 900, 50, 50}, ORANGE);
    DrawText("Apply", 1505, 905, 24, RAYWHITE);

}

void Options::DrawBack(int width, int height) {

    DrawRectangleRec( { width/5.49f, 730, width/8.0f, height/13.5f }, DARKPURPLE);
    DrawText("Back to Menu", width/5.49f + 5, 735, 24, RAYWHITE);

}

void Options::DrawControls(int width, int height) {

    // TraceLog(LOG_INFO, "OPTIONS -> CONTROLS");

}

void Options::DrawVideo(int width, int height) {

    DrawRectangleRec( { width/5.49f, height/3.2f, width/1.545f, height/2.12f }, Color{ 0x0D, 0x0F, 0x19, 255} );
    
    DrawText("Resolution:", 380, 360, 36, RAYWHITE);
    DrawText("Display Mode:", 380, 430, 36, RAYWHITE);
    DrawText("FPS Unlimited:", 380, 500, 36, RAYWHITE);
    DrawText("FPS Limit:", 380, 570, 36, RAYWHITE);

    DrawRectangleRec( { 640, 360, 200, 40 }, BLACK );
    DrawText( (std::to_string(Settings::GetWidth()) + " x " + std::to_string(Settings::GetHeight())).c_str() , 645, 365, 24, RAYWHITE);

    if (resolutionDropdownBoxState) {

        Rectangle resolutionDropdownBox = { 640, 360+40, 200, resolutionOptions.size() * 40 };
        DrawRectangleRec( {resolutionDropdownBox}, BLACK );

        for (int i = 0, posY = 405; i < (int)resolutionOptions.size(); i++, posY += 40) 
            DrawText( (std::to_string((int)resolutionOptions[i].x) + " x " + std::to_string((int)resolutionOptions[i].y)).c_str() , 645, posY, 24, RAYWHITE);

    }

    if (!(resolutionDropdownBoxState)) {

        Rectangle displaySelectBox = { 640, 430, 200, 40 };
        DrawRectangleRec( { displaySelectBox }, BLACK ); 
        DrawText(displayOptions[Settings::GetDisplayState()].c_str(), 645, 435, 24, RAYWHITE);

    }

    if (displayDropdownBoxState) {

        Rectangle displayDropdownBox = { 640, 430+40, 200, displayOptions.size() * 40 }; 
        DrawRectangleRec( { displayDropdownBox }, BLACK );

        for (int i = 0, posY = 475; i < (int)displayOptions.size(); i++, posY += 40) DrawText(displayOptions[i].c_str(), 645, posY, 24, RAYWHITE);

    }

    if (!(resolutionDropdownBoxState || displayDropdownBoxState)) {

        DrawRectangleRec( { 640, 505, 30, 30 }, BLACK );
        if (fpsUnlimited) DrawRectangleRec( { 645, 510, 20, 20 }, GRAY ); // 2147483647

    }

    if (!(resolutionDropdownBoxState || displayDropdownBoxState)) {

        DrawRectangleRec( { 640, 570, 200, 40 }, BLACK);
        DrawText( std::to_string(Settings::GetFpsCap()).c_str(), 645, 575, 24, RAYWHITE );      

    }

    /*
    if (fpsCapDropdownBoxState) {

        Rectangle fpsCapDropdownBox = { 640, 500+40, 200, fpsOptions.size() * 40 };
        DrawRectangleRec( { fpsCapDropdownBox }, BLACK );

        for (int i = 0, posY = 545; i < (int)fpsOptions.size(); i++, posY += 40) DrawText(std::to_string(fpsOptions[i]).c_str(), 645, posY, 24, RAYWHITE);

    }*/

}

void Options::DrawAudio(int width, int height) {

    // TraceLog(LOG_INFO, "OPTIONS -> AUDIO");

}

void Options::DrawInterface(int width, int height) {

    // TraceLog(LOG_INFO, "OPTIONS -> INTERFACE");

}

void Options::DrawGameplay(int width, int height) {

    // TraceLog(LOG_INFO, "OPTIONS -> GAMEPLAY");

}