#include "raylib.h"
#include "../include/screens/Game.hpp"
#include "../include/resources/Element.hpp"
#include "../include/ui/Hotbar.hpp"
#include "../include/ui/HUD.hpp"
#include "../include/ui/Inventory.hpp"
#include "../include/spells/WaterBullet.hpp"

#include <string>
#include <vector>

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

void Game::Init() {

    TraceLog(LOG_INFO, "Game iniciado");

    Texture2D grassTexture = LoadTexture("assets/images/tiles/Grass.png");
    Texture2D wall = LoadTexture("");

    for (int y = 0; y < 2000; y += 16) for (int x = 0; x < 2000; x += 16) {
        if (x == 512) {
            tiles.push_back(Tile({(float)x, (float)y}, 1, wall));
            continue;
        }
        tiles.push_back(Tile({(float)x, (float)y}, 0, grassTexture));
    }

}

void Game::Update() {
    
    if (player != nullptr) {
        
        player->Update(tiles);
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

        for (int y = -2000; y < 2000; y += 16) for (int x = -2000; x < 2000; x += 16) DrawRectangleLines(x, y, 16, 16, LIGHTGRAY);
        
        for (const auto& tile : tiles) {
            
            Vector2 tilePos = tile.GetPosition();
            
            if (CheckCollisionRecs( {tilePos.x, tilePos.y, 16, 16},
            {   camera.GetCamera2D().target.x - camera.GetCamera2D().offset.x,
                camera.GetCamera2D().target.y - camera.GetCamera2D().offset.y,
                1280, 720 }
            ) )

            tile.Draw();

        }

        player->Draw();
        waterBullet.Draw(); 

        EndMode2D();
    }    

    inventory.Draw();
    hotbar.Draw();
    hud.Draw();           

    EndDrawing();

}