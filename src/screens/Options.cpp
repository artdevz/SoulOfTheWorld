#include "raylib.h"
#include "core/Settings.hpp"
#include "screens/Options.hpp"
#include "ui/Window.hpp"

std::array<std::string, 3> Options::displayOptions = {"Windowed", "Borderless", "Fullscreen"};

bool Options::displayDropdownBoxState = false;

Options::Options() {
    screenType = SCR_OPTIONS;
    settingsType = OPT_NONE;    
    TraceLog(LOG_INFO, "Criado a Options");
}

void Options::Init() {}

void Options::Update() {

    int width = Window::resolution.x, height = Window::resolution.y;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), { width/5.49f, height/4.5f, width/8.0f, height/13.5f })) settingsType = OPT_CONTROLS;
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), { width/3.2f, height/4.5f, width/8.0f, height/13.5f })) settingsType = OPT_VIDEO;
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), { width/2.26f, height/4.5f, width/8.0f, height/13.5f })) settingsType = OPT_AUDIO;
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), { width/1.75f, height/4.5f, width/8.0f, height/13.5f })) settingsType = OPT_INTERFACE;
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), { width/1.42f, height/4.5f, width/8.0f, height/13.5f })) settingsType = OPT_GAMEPLAY;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), { 640, 430, 200, 40 } )) displayDropdownBoxState = !displayDropdownBoxState; 

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), { 640, 470, 200, 40 } )) {
        Settings::SetDisplayState(DP_WINDOWED);
        displayDropdownBoxState = false;
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), { 640, 510, 200, 40 } )) {
        Settings::SetDisplayState(DP_BORDERLESS);
        displayDropdownBoxState = false;
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), { 640, 550, 200, 40 } )) {
        Settings::SetDisplayState(DP_FULLSCREEN);
        displayDropdownBoxState = false;
    }

    Draw();

}

void Options::Draw() {

    int width = Window::resolution.x, height = Window::resolution.y;

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

    // DrawRectangleRec( { 350, 730, 240, 80}, PURPLE);
    // DrawText("Back to Menu", 350+5, 735, 24, RAYWHITE);

}

void Options::DrawControls(int width, int height) {

    TraceLog(LOG_INFO, "OPTIONS -> CONTROLS");

}

void Options::DrawVideo(int width, int height) {

    DrawRectangleRec( { width/5.49f, height/3.2f, width/1.545f, height/2.12f }, Color{ 0x0D, 0x0F, 0x19, 255} );
    
    DrawText("Resolution:", 380, 360, 36, RAYWHITE);
    DrawText("Display Mode:", 380, 430, 36, RAYWHITE);
    DrawText("FPS Limit:", 380, 500, 36, RAYWHITE);

    Rectangle displaySelectBox = { 640, 430, 200, 40 };
    DrawRectangleRec( { displaySelectBox }, BLACK ); 
    DrawText(displayOptions[Settings::GetDisplayState()].c_str(), 645, 435, 24, RAYWHITE);

    if (displayDropdownBoxState) {

        Rectangle displayDropdownBox = { 640, 430+40, 200, displayOptions.size() * 40 }; 
        DrawRectangleRec( { displayDropdownBox }, BLACK );

        for (int i = 0, posY = 475; i < (int)displayOptions.size(); i++, posY += 40) DrawText(displayOptions[i].c_str(), 645, posY, 24, RAYWHITE);

    }      

}

void Options::DrawAudio(int width, int height) {

    TraceLog(LOG_INFO, "OPTIONS -> AUDIO");

}

void Options::DrawInterface(int width, int height) {

    TraceLog(LOG_INFO, "OPTIONS -> INTERFACE");

}

void Options::DrawGameplay(int width, int height) {

    TraceLog(LOG_INFO, "OPTIONS -> GAMEPLAY");

}