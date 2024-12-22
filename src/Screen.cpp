#include "raylib.h"
#include "../include/Screen.hpp"

Screen::Screen() {}

void Screen::MainMenuScreen() {

    BeginDrawing();
    ClearBackground(Color{ 0x14, 0x16, 0x20, 255});

    // Title/Logo
    DrawText("Soul of the World", 360, 30, 64, Color{ 0xE0, 0xA5, 0x26, 255}); // E0A526

    // Play Button
    DrawRectangle(480, 280, 320, 80, Color{ 0x0A, 0xAC, 0x65, 255 }); // 08AC65
    DrawText("Play", 620, 310, 24, WHITE);

    // Options Button
    DrawRectangle(480, 400, 320, 80, Color{ 0x0A, 0xA4, 0x97, 255 }); // 0AA497
    DrawText("Options", 600, 430, 24, WHITE);

    // Exit Button
    DrawRectangle(480, 520, 320, 80, Color{ 0x86, 0x02, 0x02, 255 }); // 860202
    DrawText("Exit", 620, 550, 24, WHITE);

    EndDrawing();

}

void Screen::PlayMenuScreen() {}
void Screen::GameScreen() {}