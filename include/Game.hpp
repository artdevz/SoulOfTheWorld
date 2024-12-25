#ifndef GAME_HPP
#define GAME_HPP

#include "Screen.hpp"
#include "Cam.hpp"
#include "Hotbar.hpp"
#include "HUD.hpp"
#include "Inventory.hpp"
#include "Player.hpp"
#include "UI.hpp"

class Game : public Screen {

public:

    Game();
    void SetPlayer(Player*);
    void Init();
    void Update();
    void Draw();

private:

    Player* player;
    Cam camera;
    Hotbar hotbar;
    HUD hud;
    UI ui;
    Inventory inventory;
    
};

#endif