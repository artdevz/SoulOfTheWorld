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

    DrawHP();
    DrawMP();
    DrawHotBar();  

    EndDrawing();

}

void Game::DrawHP() {

    Rectangle hp = { 400, 580, 232, 35 };
    DrawRectangleRec(hp, Color{ 0x34, 0xAE, 0x08, 255 }); // 34AE08
    DrawText("HP", 405, 587, 24, WHITE);

    int currentHP = 200;
    int maxHP = 200;

    std::string hpText = std::to_string(currentHP) + "/" + std::to_string(maxHP);
    DrawText(hpText.c_str(), 485, 590, 16, WHITE);

}

void Game::DrawMP() {

    Rectangle mp = { 648, 580, 232, 35 };
    DrawRectangleRec(mp, Color{ 0x2A, 0x76, 0xBD, 255 }); // 2A76BD
    DrawText("MP", 842, 587, 24, WHITE);

    int currentMP = 100;
    int maxMP = 100;

    std::string mpText = std::to_string(currentMP) + "/" + std::to_string(maxMP);
    DrawText(mpText.c_str(), 733, 590, 16, WHITE);

}

void Game::DrawHotBar() {

    Color standardHotKeyBackground = Color{ 0x7C, 0x7C, 0x7C, 255 };

    float hotKeyPosX = 400;
    float hotKeyPosXIncrement = 70;

    Rectangle hotkey = { hotKeyPosX, 625, 60, 60 };
    DrawRectangleRec( hotkey, standardHotKeyBackground);
    DrawText("LB", hotKeyPosX+5, 630, 16, WHITE);

    for (int i = 1; i < 6; i++) {
        hotKeyPosX += hotKeyPosXIncrement;
        DrawRectangleRec( { hotKeyPosX, 625, 60, 60}, standardHotKeyBackground); // 1 - 5
        DrawText(std::to_string(i).c_str(), hotKeyPosX+5, 630, 16, WHITE);
    }

    DrawRectangleRec( {hotKeyPosX+hotKeyPosXIncrement, 625, 60, 60}, standardHotKeyBackground);
    DrawText("RB", hotKeyPosX+hotKeyPosXIncrement+5, 630, 16, WHITE);

}