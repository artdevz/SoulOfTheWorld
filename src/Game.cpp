#include "raylib.h"
#include "../include/Game.hpp"
#include "../include/Element.hpp"
#include "../include/Hotbar.hpp"
#include "../include/HUD.hpp"
#include "../include/Inventory.hpp"
#include "../include/Spell.hpp"
#include <string>

Game::Game() :
    Screen(),
    camera({640, 360}, {1280 / 2, 720 / 2}),    
    hotbar(),
    hud(),
    inventory(),
    player(nullptr),
    spell(), 
    ui() {
        screenType = SCREEN_GAME;
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
        spell.Update(player->GetPosition(), GetScreenToWorld2D(GetMousePosition(), camera.GetCamera2D()));

    }    
    
    ui.Update();

}

void Game::Draw() {

    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (player != nullptr) {
        BeginMode2D(camera.GetCamera2D());

        for (int y = 0; y < 2000; y += 16) for (int x = 0; x < 2000; x += 16) DrawRectangleLines(x, y, 16, 16, LIGHTGRAY);
        
        DrawRectangle(400, 400, 20, 20, BLACK);
        DrawRectangle(400, 800, 20, 20, BLACK);
        DrawRectangle(800, 400, 20, 20, BLACK);
        DrawRectangle(800, 800, 20, 20, BLACK);

        player->Draw();
        spell.Draw(); 

        EndMode2D();
    }    

    ui.Draw();
    inventory.Draw();
    hotbar.Draw();
    hud.Draw();           

    EndDrawing();

}