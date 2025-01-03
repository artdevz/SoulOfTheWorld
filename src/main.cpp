#include "raylib.h"
#include "../include/screens/Menu.hpp"
#include "../include/screens/Select.hpp"
#include "../include/screens/Game.hpp"
#include "../include/ui/Window.hpp"

#include <memory>

int main() {    
    Window(Window(1920, 1080, 60, "Soul of The World"));

    std::shared_ptr<Screen> screen = std::make_unique<Menu>();
    std::unique_ptr<Player> player = nullptr;
    std::shared_ptr<Game> game = nullptr;  

    while (!WindowShouldClose()) { 
        
        screen->Update();
        screen->Draw();
        
        if (screen->screenType == SCREEN_GAME && !game) {

            game = std::make_shared<Game>();

            if (!player) player = std::make_unique<Player>(Select::getSelectedElement());
            
            game->SetPlayer(player.get());
            game->Init();
            screen = game;

        }

        switch (screen->screenType) {

            case SCREEN_MAIN: 
                screen = std::make_unique<Menu>(); 
                break;
            
            case SCREEN_SELECT: 
                screen = std::make_unique<Select>();
                break;

            case SCREEN_GAME:
                break;
        
        }

    }   

    return 0;
}
