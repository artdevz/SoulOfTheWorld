#include "raylib.h"
#include "../include/ui/HUD.hpp"
#include <string>

HUD::HUD() {}

void HUD::Init() {}

void HUD::Update() {}

void HUD::Draw() {

    DrawIcon();
    DrawHP();
    DrawMP();

    DrawFPS(10, 690);

}

void HUD::DrawIcon() {

    Rectangle icon = { 10, 10, 100, 100 };
    DrawRectangleRec(icon, BLACK);
    DrawCircle(60, 60, 50, PURPLE);
    DrawText("Name", 120, 15, 24, BLACK);

}

void HUD::DrawHP() {

    Rectangle hp = { 120, 40, 200, 25 };
    DrawRectangleRec(hp, Color{ 0x34, 0xAE, 0x08, 255 }); // 34AE08
    DrawText("HP", 125, 45, 18, WHITE);

    int currentHP = 200;
    int maxHP = 200;

    std::string hpText = std::to_string(currentHP) + "/" + std::to_string(maxHP);
    DrawText(hpText.c_str(), 195, 45, 16, WHITE);

}

void HUD::DrawMP() {

    Rectangle mp = { 120, 75, 200, 25 };
    DrawRectangleRec(mp, Color{ 0x2A, 0x76, 0xBD, 255 }); // 2A76BD
    DrawText("MP", 125, 80, 18, WHITE);

    int currentMP = 100;
    int maxMP = 100;

    std::string mpText = std::to_string(currentMP) + "/" + std::to_string(maxMP);
    DrawText(mpText.c_str(), 195, 80, 16, WHITE);

}