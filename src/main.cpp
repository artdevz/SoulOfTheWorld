#include "raylib.h"
#include "../include/Menu.hpp"
#include "../include/Select.hpp"
#include "../include/Game.hpp"

int main() {    
    InitWindow(1280, 720, "Soul of The World");

    Screen* screen = new Menu();
    
    SetTargetFPS(60);

    Player* player = nullptr;

    while (!WindowShouldClose()) { 
        
        screen->Update();
        screen->Draw();
        
        if (screen->screenType == SCREEN_GAME && player == nullptr) player = new Player(Select::getSelectedElement()); 
          
        switch (screen->screenType) {

            case SCREEN_MAIN: delete screen; screen = new Menu(); break;
            
            case SCREEN_SELECT: 
                delete screen;
                screen = new Select(); 
                break;

            case SCREEN_GAME:
                if (player != nullptr) {
                    Game* gameScreen = new Game();
                    gameScreen->SetPlayer(player);
                    delete screen;
                    screen = gameScreen;
                } 
                break;
        
        }

    }
    
    delete player;
    CloseWindow();
    return 0;
}
