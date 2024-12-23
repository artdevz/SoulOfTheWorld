#include "raylib.h"
#include "../include/Game.hpp"
#include "../include/Element.hpp"
#include <string>

Game::Game() {

    screenType = SCREEN_GAME;
    player = nullptr;
    ui = UI();

}

void Game::SetPlayer(Player* p) {
    player = p;
}

void Game::Init() {
    ui = UI();
}

void Game::Update() {
    
    if (player != nullptr) {
        player->Update();
    }
    // player.Update();

    ui.Update();

}

void Game::Draw() {

    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (player != nullptr) player->Draw();
    ui.Draw();

    DrawIcon();
    DrawHP();
    DrawMP();
    DrawHotBar();  

    EndDrawing();

}

void Game::DrawIcon() {

    Rectangle icon = { 10, 10, 100, 100 };
    DrawRectangleRec(icon, BLACK);
    DrawCircle(60, 60, 50, PURPLE);
    DrawText("Name", 120, 15, 24, BLACK);

}

void Game::DrawHP() {

    Rectangle hp = { 120, 40, 200, 25 };
    DrawRectangleRec(hp, Color{ 0x34, 0xAE, 0x08, 255 }); // 34AE08
    DrawText("HP", 125, 45, 18, WHITE);

    int currentHP = 200;
    int maxHP = 200;

    std::string hpText = std::to_string(currentHP) + "/" + std::to_string(maxHP);
    DrawText(hpText.c_str(), 195, 45, 16, WHITE);

}

void Game::DrawMP() {

    Rectangle mp = { 120, 75, 200, 25 };
    DrawRectangleRec(mp, Color{ 0x2A, 0x76, 0xBD, 255 }); // 2A76BD
    DrawText("MP", 125, 80, 18, WHITE);

    int currentMP = 100;
    int maxMP = 100;

    std::string mpText = std::to_string(currentMP) + "/" + std::to_string(maxMP);
    DrawText(mpText.c_str(), 195, 80, 16, WHITE);

}

void Game::DrawHotBar() {

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