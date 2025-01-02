#ifndef GAME_HPP
#define GAME_HPP

#include "roots/Screen.hpp"
#include "core/Cam.hpp"
#include "ui/Hotbar.hpp"
#include "ui/HUD.hpp"
#include "ui/Inventory.hpp"
#include "core/Player.hpp"
#include "spells/WaterBullet.hpp"
#include "world/Tile.hpp"

class Game : public Screen {

    public:

        Game();
        
        void SetPlayer(Player*);
        void Init();
        void Update();
        void Draw();

    private:

        Cam camera;
        Hotbar hotbar;
        HUD hud;
        Inventory inventory;
        Player* player;
        WaterBullet waterBullet;
        
        std::vector<Tile> tiles;

    };

#endif