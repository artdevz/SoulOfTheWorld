#include "raylib.h"
#include "Select.hpp"

Select::Select() {
    screenType = SCREEN_SELECT;
}

void Select::Init() {}

void Select::Update() {}

void Select::Draw() {

    BeginDrawing();
    ClearBackground(Color{ 0x14, 0x16, 0x20, 255});

    // Title/Logo
    DrawText("Soul of the World", 360, 30, 64, Color{ 0xE0, 0xA5, 0x26, 255}); // E0A526

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

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), buttonFire)) {
        // element = FIRE;
        
        screenType = SCREEN_GAME;
    }


    // Water Button
    Rectangle buttonWater = {posXwaterButton, posYbuttons, widthFrame, heightButton};
    DrawRectangleRec(buttonWater, BLUE);
    DrawText("Water - 40%", posXwaterButton+posXnameChange, posYname, nameFont, WHITE);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), buttonWater)) {
        // element = WATER;
        
        screenType = SCREEN_GAME;
    }


    // Earth Button
    Rectangle buttonEarth = {posXearthButton, posYbuttons, widthFrame, heightButton};
    DrawRectangleRec(buttonEarth, RED);
    DrawText("Earth - 5%", posXearthButton+posXnameChange, posYname, nameFont, WHITE);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), buttonEarth)) {
        // element = EARTH;
        
        screenType = SCREEN_GAME;
    }


    // Air Button
    Rectangle buttonAir = {posXairButton, posYbuttons, widthFrame, heightButton};
    DrawRectangleRec({posXairButton, posYbuttons, widthFrame, heightButton}, GREEN);
    DrawText("Air - 75%", posXairButton+posXnameChange, posYname, nameFont, WHITE);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), buttonAir)) {
        // element = AIR;
        
        screenType = SCREEN_GAME;
    }


    // Back Button
    Rectangle buttonBack = {570, 620, 140, 60};
    DrawRectangleRec(buttonBack, DARKPURPLE);
    DrawText("Back to Menu", 582, 640, 18, WHITE);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), buttonBack)) {
        
        screenType = SCREEN_MAIN;
    }

    EndDrawing();

}