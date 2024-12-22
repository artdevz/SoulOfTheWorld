#include "raylib.h"
#include "../include/Player.hpp"
#include "../include/UI.hpp"
#include "../include/Game.hpp"

int main() {
    
    InitWindow(1280, 720, "Soul of The World");
    
    Game game;
    game.Init();

    SetTargetFPS(60);

    while (!WindowShouldClose()) { 
        
        game.Update();
        game.Draw();

    }
    
    CloseWindow();
    return 0;
}
