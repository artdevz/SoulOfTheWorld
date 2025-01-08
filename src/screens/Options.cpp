#include "raylib.h"
#include "screens/Options.hpp"
#include "ui/Window.hpp"

Options::Options() {
    screenType = SCR_OPTIONS;
    settingsType = OPT_NONE;
    TraceLog(LOG_INFO, "Criado a Options");
}

void Options::Init() {}

void Options::Update() {

    int width = Window::resolution.x, height = Window::resolution.y;
    // Completar e Refatorar
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), { width/7.0f, height/4.0f, 150, 50 })) settingsType = OPT_VIDEO;

    Draw();

}

void Options::Draw() {

    int width = Window::resolution.x, height = Window::resolution.y;

    BeginDrawing();

    ClearBackground(Color{ 0x14, 0x16, 0x20, 255});

    DrawText("Options", (int)(width / 2 - MeasureText("Options", width/20) / 2) , (int)height / 24, width/20, Color{ 0xE0, 0xA5, 0x26, 255});
    DrawButtons(width, height);
    // DrawBack(width, height);

    switch (settingsType) {

        case OPT_NONE: break;

        case OPT_VIDEO: DrawVideo(width, height); break;
        case OPT_AUDIO: DrawAudio(width, height); break;
        case OPT_CONTROLS: DrawControls(width, height); break;
        case OPT_INTERFACE: DrawInterface(width, height); break;
        case OPT_GAMEPLAY: DrawGameplay(width, height); break;

    }

    EndDrawing();

}

void Options::DrawButtons(int width, int height) { // Calcular Largura e Altura do Rect
    
    DrawRectangleRec( { width/7.0f, height/4.0f, 150, 50 }, BLACK);
    DrawText("Video", width/7.0f+5, height/4.0f+5, 24, RAYWHITE);

    DrawRectangleRec( { width/7.0f, 300, 150, 50 }, BLACK);
    DrawText("Audio", width/7.0f+5, 305, 24, RAYWHITE);

    DrawRectangleRec( { width/7.0f, 400, 150, 50 }, BLACK);
    DrawText("Controls", width/7.0f+5, 405, 24, RAYWHITE);

    DrawRectangleRec( { width/7.0f, 500, 150, 50 }, BLACK);
    DrawText("Interface", width/7.0f+5, 505, 24, RAYWHITE);

    DrawRectangleRec( { width/7.0f, 600, 150, 50 }, BLACK);
    DrawText("Gameplay", width/7.0f+5, 605, 24, RAYWHITE);

}

void Options::DrawVideo(int width, int height) {

    TraceLog(LOG_INFO, "OPTIONS -> VIDEO");

}

void Options::DrawAudio(int width, int height) {

    TraceLog(LOG_INFO, "OPTIONS -> AUDIO");

}

void Options::DrawControls(int width, int height) {

    TraceLog(LOG_INFO, "OPTIONS -> CONTROLS");

}

void Options::DrawInterface(int width, int height) {

    TraceLog(LOG_INFO, "OPTIONS -> INTERFACE");

}

void Options::DrawGameplay(int width, int height) {

    TraceLog(LOG_INFO, "OPTIONS -> GAMEPLAY");

}