#include "raylib.h"
#include "screens/Menu.hpp"
#include "ui/Window.hpp"

Menu::Menu() {
    screenType = SCR_MAIN;
    TraceLog(LOG_INFO, "Criado o Menu");    
}

void Menu::Init() {}

void Menu::Update() {
    Draw();
}

void Menu::Draw() {

    int width = Window::resolution.x, height = Window::resolution.y;

    BeginDrawing();
    ClearBackground(Color{ 0x14, 0x16, 0x20, 255});

    // Title/Logo    
    DrawText("Soul of the World", (int)(width / 2 - MeasureText("Soul of the World", width/20) / 2) , (int)height / 24, width/20, Color{ 0xE0, 0xA5, 0x26, 255});

    // Play Button
    DrawRectangleRec( { width/2.67f, height/2.57f, width/4.0f, height/9.0f }, Color{ 0x0A, 0xAC, 0x65, 255 });    
    DrawText("Play", (int)(width / 2 - MeasureText("Play", width/53.33) / 2), height / 2.32f, width/53.33, WHITE);

    // Options Button    
    DrawRectangleRec( { width/2.67f, height/1.8f, width/4.0f, height/9.0f } , Color{ 0x0A, 0xA4, 0x97, 255 });
    DrawText("Options", (int)(width / 2 - MeasureText("Options", width/53.33) / 2), height / 1.67f, width/53.33, WHITE);

    // Exit Button    
    DrawRectangleRec( { width/2.67f, height/1.38f, width/4.0f, height/9.0f } , Color{ 0x86, 0x02, 0x02, 255 });
    DrawText("Exit", (int)(width / 2 - MeasureText("Exit", width/53.33) / 2), height / 1.31f, width/53.33, WHITE);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), { width/2.67f, height/2.57f, width/4.0f, height/9.0f } )) screenType = SCR_SELECT;
    
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), { width/2.67f, height/1.8f, width/4.0f, height/9.0f } )) screenType = SCR_OPTIONS;
    
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), {width/2.67f, height/1.38f, width/4.0f, height/9.0f} )) CloseWindow();

    EndDrawing();

}