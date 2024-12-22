#include "raylib.h"
#include "../include/Player.hpp"
#include "../include/UI.hpp"
#include "../include/Game.hpp"
#include "../include/Screen.hpp"

int main() {
    
    InitWindow(1280, 720, "Soul of The World");
    Screen screen;

    // Game game;
    // game.Init();

    SetTargetFPS(60);

    while (!WindowShouldClose()) { 
        
        switch (screen.screenType) {

        case MAIN: screen.MainMenuScreen(); break;
        case PLAY: screen.PlayMenuScreen(); break;
        case GAME: screen.GameScreen(); break;
        
        }

        // game.Update();
        // game.Draw();

    }
    
    CloseWindow();
    return 0;
}
