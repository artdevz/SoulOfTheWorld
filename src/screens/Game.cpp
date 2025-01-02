#include "raylib.h"
#include "../include/screens/Game.hpp"
#include "../include/resources/Element.hpp"
#include "../include/ui/Hotbar.hpp"
#include "../include/ui/HUD.hpp"
#include "../include/ui/Inventory.hpp"
#include "../include/spells/WaterBullet.hpp"

#include <string>

Game::Game() :
    Screen(),
    camera({640, 360}, {1280 / 2, 720 / 2}),    
    hotbar(),
    hud(),
    inventory(),
    player(nullptr),
    waterBullet() {
        screenType = SCREEN_GAME;
    }

void Game::SetPlayer(Player* p) {
    player = p;
}

void Game::Init() {}

void Game::Update() {
    
    if (player != nullptr) {
        
        player->Update();
        camera.Update(player->GetPosition());
        hotbar.Update();
        inventory.Update();
        waterBullet.Update(player->GetPosition(), GetScreenToWorld2D(GetMousePosition(), camera.GetCamera2D()));

    }    

}

void Game::Draw() {

    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (player != nullptr) {
        BeginMode2D(camera.GetCamera2D());

        for (int y = 0; y < 2000; y += 16) for (int x = 0; x < 2000; x += 16) DrawRectangleLines(x, y, 16, 16, LIGHTGRAY);
        
        DrawRectangle(400, 400, 16, 16, BLACK);
        DrawRectangle(400, 800, 16, 16, BLACK);
        DrawRectangle(800, 400, 16, 16, BLACK);
        DrawRectangle(800, 800, 16, 16, BLACK);

        player->Draw();
        waterBullet.Draw(); 

        EndMode2D();
    }    

    inventory.Draw();
    hotbar.Draw();
    hud.Draw();           

    EndDrawing();

}