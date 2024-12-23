#include "raylib.h"
#include "../include/Game.hpp"
#include "../include/Element.hpp"

Game::Game() {
    screenType = SCREEN_GAME;
    player = nullptr;
    ui = UI();
}

void Game::SetPlayer(Player* p) {
    player = p;
}

void Game::Init() {
    // player = Player();
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

    if (player != nullptr) {
        player->Draw();
    }
    ui.Draw();

    EndDrawing();

}