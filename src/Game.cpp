#include "raylib.h"
#include "../include/Game.hpp"
#include "../include/Element.hpp"
#include "../include/Hotbar.hpp"
#include "../include/Inventory.hpp"
#include <string>

Game::Game() : camera({640, 360}, {1280 / 2, 720 / 2}) {

    screenType = SCREEN_GAME;
    player = nullptr;
    ui = UI();
    hotbar = Hotbar();
    inventory = Inventory();

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
        camera.Update(player->GetPosition());
        inventory.Update();

    }    
    
    ui.Update();

}

void Game::Draw() {

    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (player != nullptr) {
        BeginMode2D(camera.GetCamera2D());

        for (int y = 0; y < 2000; y += 16) for (int x = 0; x < 2000; x += 16) DrawRectangleLines(x, y, 16, 16, LIGHTGRAY);

        player->Draw();

        EndMode2D();
    }    

    ui.Draw();
    inventory.Draw();
    hotbar.Draw();

    DrawIcon();
    DrawHP();
    DrawMP();    

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