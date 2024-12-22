#include "raylib.h"
#include "../include/Game.hpp"

Game::Game() {
    player = Player();
    ui = UI();
}

void Game::Init() {}

void Game::Update() {

    player.Update();

    ui.Update();

}

void Game::Draw() {

    BeginDrawing();
    ClearBackground(RAYWHITE);

    player.Draw();
    ui.Draw();

    EndDrawing();

}