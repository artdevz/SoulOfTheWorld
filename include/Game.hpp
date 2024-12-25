#ifndef GAME_HPP
#define GAME_HPP

#include "Screen.hpp"
#include "Cam.hpp"
#include "Hotbar.hpp"
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
    UI ui;
    Inventory inventory;
    
    void DrawIcon();
    void DrawHP();
    void DrawMP();
    
};

#endif