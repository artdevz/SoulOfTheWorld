#include "raylib.h"
#include "screens/Menu.hpp"

Menu::Menu() {
    screenType = SCREEN_MAIN;
}

void Menu::Init() {}

void Menu::Update() {}

void Menu::Draw() {

    BeginDrawing();
    ClearBackground(Color{ 0x14, 0x16, 0x20, 255});

    // Title/Logo
    DrawText("Soul of the World", 360, 30, 64, Color{ 0xE0, 0xA5, 0x26, 255}); // E0A526

    // Play Button
    Rectangle buttonPlay = {480, 280, 320, 80};
    DrawRectangleRec(buttonPlay, Color{ 0x0A, 0xAC, 0x65, 255 });    
    DrawText("Play", 620, 310, 24, WHITE);

    // Options Button
    Rectangle buttonOptions = {480, 400, 320, 80};
    DrawRectangleRec(buttonOptions, Color{ 0x0A, 0xA4, 0x97, 255 });
    DrawText("Options", 600, 430, 24, WHITE);

    // Exit Button
    Rectangle buttonExit = {480, 520, 320, 80};
    DrawRectangleRec(buttonExit, Color{ 0x86, 0x02, 0x02, 255 });
    DrawText("Exit", 620, 550, 24, WHITE);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), buttonPlay)) screenType = SCREEN_SELECT;
    
    // if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), buttonOptions)) // Unimpl
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), buttonExit)) CloseWindow();

    EndDrawing();

}