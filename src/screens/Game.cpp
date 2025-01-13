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
        screenType = SCR_GAME;
        TraceLog(LOG_INFO, "Game Criado"); // Está sendo criado 2x, Talvez: Window criado 2x por isso
    }

void Game::SetPlayer(Player* p) {
    player = p;
}

void Game::Init() {

    TraceLog(LOG_INFO, "Game iniciado");

    Texture2D grassTexture = LoadTexture("assets/images/tiles/Grass.png");
    // Texture2D grassPathTexture = LoadTexture("assets/images/tiles/GrassPath.png");

    for (int y = 0; y < 1024; y += 32) for (int x = 0; x < 1024; x += 32) {

        tiles.push_back(Tile({(float)x, (float)y}, 0, grassTexture));

    }

}

void Game::Update() {
    
    if (player) {
        
        player->Update(tiles);
        camera.Update(player->GetPosition());
        hotbar.Update();
        inventory.Update();
        waterBullet.Update(player->GetPosition(), GetScreenToWorld2D(GetMousePosition(), camera.GetCamera2D()));

    }

    Draw();    

}

void Game::Draw() {

    BeginDrawing();
    ClearBackground(RAYWHITE);

    if (player) {
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