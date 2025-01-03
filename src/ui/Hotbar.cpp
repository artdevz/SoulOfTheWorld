#include "raylib.h"
#include "ui/Hotbar.hpp"
#include "ui/Window.hpp"

#include <string>

Hotbar::Hotbar() {
    // spell = Spell();
}

void Hotbar::Init() {}

void Hotbar::Update() {

    // if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) spell.Cast();
    // spell.Update();

}

void Hotbar::Draw() {
    
    float width = Window::resolution.x, height = Window::resolution.y;
    float hotbarPosX = width / 2.94f;

    Color standardHotKeyBackground = Color{ 0x7C, 0x7C, 0x7C, 255 };

    for (int i = 1; i < 8; i++) {

        DrawRectangleRec( { hotbarPosX, height / 1.13f , width / 25.6f , width / 25.6f }, standardHotKeyBackground);
        DrawText(std::to_string(i).c_str(), hotbarPosX +5, height / 1.13f+5, width / 80, WHITE);
        hotbarPosX += ( width / 21.33f );

    }

}