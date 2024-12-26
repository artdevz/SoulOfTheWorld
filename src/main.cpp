#include "raylib.h"
#include "../include/Menu.hpp"
#include "../include/Select.hpp"
#include "../include/Game.hpp"
#include <memory>

int main() {    
    InitWindow(1280, 720, "Soul of The World");

    std::unique_ptr<Screen> screen = std::make_unique<Menu>();
    std::unique_ptr<Player> player = nullptr;
        
    SetTargetFPS(60);    

    while (!WindowShouldClose()) { 
        
        screen->Update();
        screen->Draw();
        
        if (screen->screenType == SCREEN_GAME && !player) player = std::make_unique<Player>(Select::getSelectedElement()); 
          
        switch (screen->screenType) {

            case SCREEN_MAIN: 
                screen = std::make_unique<Menu>(); 
                break;
            
            case SCREEN_SELECT: 
                screen = std::make_unique<Select>();
                break;

            case SCREEN_GAME:
                if (player) {
                    auto gameScreen = std::make_unique<Game>();
                    gameScreen->SetPlayer(player.get());
                    screen = std::move(gameScreen);
                } 
                break;
        
        }

    }   
    
    CloseWindow();
    return 0;
}
