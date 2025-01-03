#include "raylib.h"
#include "screens/Select.hpp"
#include "ui/Window.hpp"

Element Select::selectedElement = NONE;

Select::Select() {
    screenType = SCREEN_SELECT;
}

Select::Select(Element element) {
    screenType = SCREEN_SELECT;
    selectedElement = element;    
}

Element Select::getSelectedElement() {
    return selectedElement;
}

void Select::Init() {}

void Select::Update() {}

void Select::Draw() {

    int width = Window::resolution.x, height = Window::resolution.y;
    
    float framePosY = height / 3.6f;
    float buttonPosY = height / 1.44f;

    float frameWidth = width / 6.4f;
    float frameHeight = height / 2.4f;

    float buttonWidth = frameWidth;
    float buttonHeight = height / 14.4f;

    BeginDrawing();
    ClearBackground(Color{ 0x14, 0x16, 0x20, 255});

    // Title/Logo
    DrawText("Soul of the World", (int)(width / 2 - MeasureText("Soul of the World", width/20) / 2) , (int)height / 24, width/20, Color{ 0xE0, 0xA5, 0x26, 255});
    
    // Fire
    DrawRectangleRec( { width/10.66f, framePosY, frameWidth, frameHeight }, BLACK);
    DrawRectangleRec( { width/10.66f, buttonPosY, buttonWidth, buttonHeight } , ORANGE);
    // DrawText("Fire - 15%", width/10.66f + frameWidth/32.0f + MeasureText("Fire - 15%", width / 53.3f) / 3.5, buttonPosY / 0.97f, (int)width / 53.3f, WHITE );

    // WATER
    DrawRectangleRec( { width/3.2f, framePosY, frameWidth, frameHeight }, BLACK);
    DrawRectangleRec( { width/3.2f, buttonPosY, buttonWidth, buttonHeight } , BLUE);
    // DrawText("Water - 99%", width/3.2f + width/32.0f + MeasureText("Water - 99%", width / 53.3f) / 3.5, buttonPosY / 0.97f, (int)(width / 53.3f), WHITE );

    // EARTH
    DrawRectangleRec( { width/1.88f, framePosY, frameWidth, frameHeight }, BLACK);
    DrawRectangleRec( { width/1.88f, buttonPosY, buttonWidth, buttonHeight } , RED);
    // DrawText("Earth - 5%", width/1.88f + width/32.0f + MeasureText("Earth - 5%", width / 53.3f) / 3.5, buttonPosY / 0.97f, (int)width / 53.3f, WHITE );

    // AIR
    DrawRectangleRec( { width/1.33f, framePosY, frameWidth, frameHeight }, BLACK);
    DrawRectangleRec( { width/1.33f, buttonPosY, buttonWidth, buttonHeight } , GREEN);
    // DrawText("Air - 75%", width/1.33f + width/32.0f + MeasureText("Air - 75%", width / 53.3f) / 3.5, buttonPosY / 0.97f, (int)width / 53.3f, WHITE );

    // BACK
    DrawRectangleRec( { width/2.25f, height/1.16f, width/9.14f, height/12.0f } , DARKPURPLE);
    DrawText("Back to Menu", width/2.20f, height/1.13f, width/71.f, WHITE);
    
    // BUTTONS
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {   

        if (CheckCollisionPointRec(GetMousePosition(), { width/10.66f, buttonPosY, buttonWidth, buttonHeight} )) selectedElement = FIRE; 
        if (CheckCollisionPointRec(GetMousePosition(), { width/3.2f, buttonPosY, buttonWidth, buttonHeight} )) selectedElement = WATER;
        if (CheckCollisionPointRec(GetMousePosition(), { width/1.88f, buttonPosY, buttonWidth, buttonHeight} )) selectedElement = EARTH;
        if (CheckCollisionPointRec(GetMousePosition(), { width/1.33f, buttonPosY, buttonWidth, buttonHeight} )) selectedElement = AIR;
        
        if (CheckCollisionPointRec(GetMousePosition(), { width/2.25f, height/1.16f, width/9.14f, height/12.0f } )) screenType = SCREEN_MAIN;
        if (selectedElement != NONE) screenType = SCREEN_GAME;

    }
    
    EndDrawing();

}