#include "raylib.h"
#include "core/Settings.hpp"
#include "screens/Menu.hpp"
#include "screens/Select.hpp"
#include "screens/Options.hpp"
#include "screens/Game.hpp"
#include "ui/Window.hpp"

#include <memory>

int main() {
    Settings::LoadSettings();
    Window(Settings::GetWidth(), Settings::GetHeight(), Settings::GetFpsCap(), "Soul of The World");

    std::vector<std::shared_ptr<Screen>> screens = { 
        std::make_shared<Menu>(), 
        std::make_shared<Select>(),
        std::make_shared<Options>(),
        std::make_shared<Game>()
        };

    std::shared_ptr<Screen> screen = screens[0];
    std::unique_ptr<Player> player = nullptr;
    std::shared_ptr<Game> game = nullptr;  

    while (!WindowShouldClose()) { 

        switch (screen->screenType) {
            
            case SCREEN_MAIN_MENU:                
                screen = screens[0];                               
                break;
            
            case SCREEN_SELECT_MENU:
                screen = screens[1];                
                break;

            case SCREEN_OPTIONS:
                screen = screens[2];
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

        screen->Update();

    }   

    return 0;
}
