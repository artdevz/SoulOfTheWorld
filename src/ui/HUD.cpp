#include "raylib.h"
#include "ui/HUD.hpp"
#include "ui/Window.hpp"

#include <string>

HUD::HUD() {}

void HUD::Init() {}

void HUD::Update() {}

void HUD::Draw() {

    float width = Window::resolution.x, height = Window::resolution.y;

    DrawIcon(width, height);
    DrawHP(width, height);
    DrawMP(width, height);

    DrawFPS( width / 1.05f, height / 72.0f);

}

void HUD::DrawIcon(float width, float height) {

    DrawRectangleRec( { width / 128.0f, height / 72.0f, width / 12.8f, height / 7.2f }, BLACK);
    DrawCircle( width / 21.33f, height / 12.0f, width / 25.6f, PURPLE);
    DrawText("Name", width / 10.66f, height / 85.33f, width / 53.33f, BLACK);

}

void HUD::DrawHP(float width, float height) {

    DrawRectangleRec( { width / 10.66f, height / 18.0f, width / 6.4f, height / 28.8f }, Color{ 0x34, 0xAE, 0x08, 255 }); // 34AE08
    DrawText("HP", width / 10.24f, height / 16.0f, width / 71.11f, WHITE);

    int currentHP = 200;
    int maxHP = 200;

    std::string hpText = std::to_string(currentHP) + "/" + std::to_string(maxHP);
    DrawText(hpText.c_str(), width / 6.56f, height / 16.0f, width / 80.0f, WHITE);

}

void HUD::DrawMP(float width, float height) {

    DrawRectangleRec( { width / 10.66f, height / 9.6f, width / 6.4f, height / 28.8f }, Color{ 0x2A, 0x76, 0xBD, 255 }); // 2A76BD
    DrawText("MP", width / 10.24f, height / 9.0f, width / 71.11f, WHITE);

    int currentMP = 100;
    int maxMP = 100;

    std::string mpText = std::to_string(currentMP) + "/" + std::to_string(maxMP);
    DrawText(mpText.c_str(), width / 6.56f, height / 9.0f, width / 80.0f, WHITE);

}