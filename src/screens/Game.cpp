#include "raylib.h"
#include "screens/Game.hpp"
#include "resources/Element.hpp"
#include "ui/Hotbar.hpp"
#include "ui/HUD.hpp"
#include "ui/Inventory.hpp"
#include "spells/WaterBullet.hpp"
#include "ui/Window.hpp"

#include <string>
#include <vector>

Game::Game() :
    Screen(),
    camera({Window::resolution.x / 2, Window::resolution.y / 2}, {Window::resolution.x / 2, Window::resolution.y / 2}),    
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
    Texture2D grassPathTexture = LoadTexture("assets/images/tiles/GrassPath.png");

    for (int y = 0; y < 4096; y += 32) for (int x = 0; x < 4096; x += 32) { // 4096 (Scenario) 36864 (Region) 2985984 (World) 107,49 km²

        if (x == 512 || x == 608 || x == 672) {

            tiles.push_back(Tile({(float)x, (float)y}, 0, grassPathTexture));
            continue;
            
        }

        if (x == 544) {

            Image image = LoadImage("assets/images/tiles/GrassPath.png");
            ImageRotateCW(&image);
            ImageRotateCW(&image);
            Texture2D texture = LoadTextureFromImage(image);
            tiles.push_back(Tile({(float)x, (float)y}, 0, texture));            
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

        for (const auto& tile : tiles) {
                        
            if (CheckCollisionRecs( {tile.GetPosition().x, tile.GetPosition().y, (float)tile.GetSize(), (float)tile.GetSize()},
                {   camera.GetCamera2D().target.x - camera.GetCamera2D().offset.x,
                    camera.GetCamera2D().target.y - camera.GetCamera2D().offset.y,
                    Window::resolution.x, Window::resolution.y }
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