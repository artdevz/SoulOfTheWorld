#include "raylib.h"
#include "../include/Screen.hpp"

Screen::Screen() {}

void logo() {
    DrawText("Soul of the World", 360, 30, 64, Color{ 0xE0, 0xA5, 0x26, 255}); // E0A526
}

void Screen::MainMenuScreen() {

    BeginDrawing();
    ClearBackground(Color{ 0x14, 0x16, 0x20, 255});

    // Title/Logo
    logo();

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

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), buttonPlay)) {
        PlayMenuScreen();
        screenType = PLAY;
    }
    // if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), buttonOptions)) // Unimpl
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), buttonExit)) CloseWindow();

    EndDrawing();

}

void Screen::PlayMenuScreen() {

    BeginDrawing();
    ClearBackground(Color{ 0x14, 0x16, 0x20, 255});

    // Title/Logo
    logo();

    float widthFrame = 200;
    float heightFrame = 300;
    float heightButton = 50;

    float posYframes = 200;
    float posYbuttons = 500;

    float posXfireButton = 120;
    float posXwaterButton = 400;
    float posXearthButton = 680;
    float posXairButton = 960;

    float posYname = 515;

    float posXnameChange = 40;

    int nameFont = 24;

    Rectangle frameF = {posXfireButton, posYframes, widthFrame, heightFrame};
    Rectangle frameW = {posXwaterButton, posYframes, widthFrame, heightFrame};
    Rectangle frameE = {posXearthButton, posYframes, widthFrame, heightFrame};
    Rectangle frameA = {posXairButton, posYframes, widthFrame, heightFrame};

    DrawRectangleRec(frameF, BLACK);
    DrawRectangleRec(frameW, BLACK);
    DrawRectangleRec(frameE, BLACK);
    DrawRectangleRec(frameA, BLACK);

    // Fire Button
    Rectangle buttonFire = {posXfireButton, posYbuttons, widthFrame, heightButton};
    DrawRectangleRec(buttonFire, ORANGE);
    DrawText("Fire - 15%", posXfireButton+posXnameChange , posYname, nameFont, WHITE);

    // Water Button
    Rectangle buttonWater = {posXwaterButton, posYbuttons, widthFrame, heightButton};
    DrawRectangleRec(buttonWater, BLUE);
    DrawText("Water - 40%", posXwaterButton+posXnameChange, posYname, nameFont, WHITE);

    // Earth Button
    Rectangle buttonEarth = {posXearthButton, posYbuttons, widthFrame, heightButton};
    DrawRectangleRec(buttonEarth, RED);
    DrawText("Earth - 5%", posXearthButton+posXnameChange, posYname, nameFont, WHITE);

    // Air Button
    Rectangle buttonAir = {posXairButton, posYbuttons, widthFrame, heightButton};
    DrawRectangleRec(buttonAir, GREEN);
    DrawText("Air - 75%", posXairButton+posXnameChange, posYname, nameFont, WHITE);

    // Back Button
    Rectangle buttonBack = {570, 620, 140, 60};
    DrawRectangleRec(buttonBack, DARKPURPLE);
    DrawText("Back to Menu", 582, 640, 18, WHITE);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), buttonBack)) {
        MainMenuScreen();
        screenType = MAIN;
    }

    EndDrawing();

}
void Screen::GameScreen() {}