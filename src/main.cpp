#include "raylib.h"
#include "screens/Menu.hpp"
#include "screens/Select.hpp"
#include "screens/Game.hpp"
#include "ui/Window.hpp"

#include <memory>

int main() {    
    Window(1366, 768, 60, "Soul of The World");

    std::shared_ptr<Screen> screen = std::make_shared<Menu>();
    std::unique_ptr<Player> player = nullptr;
    std::shared_ptr<Game> game = nullptr;  
    // Array para Screens
    while (!WindowShouldClose()) { 
        
        screen->Update();
        screen->Draw();

        switch (screen->screenType) {

            case SCREEN_MAIN:
                screen = std::make_unique<Menu>(); 
                break;
            
            case SCREEN_SELECT: 
                screen = std::make_unique<Select>();
                break;

            case SCREEN_GAME:

                if (!game) {
                
                    game = std::make_shared<Game>();

                    if (!player) player = std::make_unique<Player>(Select::getSelectedElement());

                    game->SetPlayer(player.get());
                    game->Init();

                }

                screen = game;
                break;
        
        }

    }   

    return 0;
}
