#include "raylib.h"
#include "core/Settings.hpp"
#include "screens/Menu.hpp"
#include "screens/Select.hpp"
#include "screens/Options.hpp"
#include "screens/Game.hpp"
#include "ui/Window.hpp"

#include <memory>

int main() {
    Settings::ReadSettings();
    auto window = std::make_unique<Window>(Settings::GetWidth(), Settings::GetHeight(), Settings::GetFpsCap(), "Soul of The World");

    std::vector<std::shared_ptr<Screen>> screens = { 
        std::make_shared<Menu>(), 
        std::make_shared<Select>(),
        std::make_shared<Options>(),
        std::make_shared<Game>()
        };

    std::shared_ptr<Screen> screen = screens[SCR_MAIN];
    std::shared_ptr<Game> game = std::make_shared<Game>();  
    std::unique_ptr<Player> player = nullptr;

    while (!WindowShouldClose()) { 

        screen = screens[screen->screenType];
        
        if (screen->screenType == SCR_GAME) {

            if (!player) {                
                    
                    player = std::make_unique<Player>(Select::getSelectedElement());

                    game->SetPlayer(player.get());
                    game->Init();

                }

            screen = game;

        }

        screen->Update();

    }

    TraceLog(LOG_INFO, "Exiting...");
    return 0;
}