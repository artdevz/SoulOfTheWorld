#include "raylib.h"
#include "../include/Hotbar.hpp"
#include <string>

Hotbar::Hotbar() {}

void Hotbar::Init() {}

void Hotbar::Update() {

    // if (IsKeyPressed(MOUSE_BUTTON_LEFT)); ... To Do

}

void Hotbar::Draw() {

    Color standardHotKeyBackground = Color{ 0x7C, 0x7C, 0x7C, 255 };

    float hotKeyPosX = 435;
    float hoyKeyPosY = 640;
    float hotKeyPosXIncrement = 60;
    float hotKeyDimension = 50;

    Rectangle hotkey = { hotKeyPosX, hoyKeyPosY, hotKeyDimension, hotKeyDimension };
    DrawRectangleRec( hotkey, standardHotKeyBackground);
    DrawText("LB", hotKeyPosX+5, hoyKeyPosY+5, 16, WHITE);

    for (int i = 1; i < 6; i++) {
        hotKeyPosX += hotKeyPosXIncrement;
        DrawRectangleRec( { hotKeyPosX, hoyKeyPosY, hotKeyDimension, hotKeyDimension}, standardHotKeyBackground); // 1 - 5
        DrawText(std::to_string(i).c_str(), hotKeyPosX+5, hoyKeyPosY+5, 16, WHITE);
    }

    DrawRectangleRec( {hotKeyPosX+hotKeyPosXIncrement, hoyKeyPosY, hotKeyDimension, hotKeyDimension}, standardHotKeyBackground);
    DrawText("RB", hotKeyPosX+hotKeyPosXIncrement+5, hoyKeyPosY+5, 16, WHITE);

}