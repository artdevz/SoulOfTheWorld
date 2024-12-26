#include "raylib.h"
#include "../include/Game.hpp"
#include "../include/Element.hpp"
#include "../include/Hotbar.hpp"
#include "../include/HUD.hpp"
#include "../include/Inventory.hpp"
#include <string>

Game::Game() : camera({640, 360}, {1280 / 2, 720 / 2}) {

    screenType = SCREEN_GAME;
    player = nullptr;
    ui = UI();
    hotbar = Hotbar();
    hud = HUD();
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
        hotbar.Update();
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
    hud.Draw();        

    EndDrawing();

}