#ifndef GAME_HPP
#define GAME_HPP

#include "roots/Screen.hpp"
#include "Cam.hpp"
#include "Hotbar.hpp"
#include "HUD.hpp"
#include "Inventory.hpp"
#include "Player.hpp"
#include "spells/WaterBullet.hpp"
#include "UI.hpp"

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
    UI ui;
    
};

#endif