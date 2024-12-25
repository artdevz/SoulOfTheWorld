#ifndef GAME_HPP
#define GAME_HPP

#include "Screen.hpp"
#include "Inventory.hpp"
#include "GameCamera.hpp"
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
    GameCamera camera;
    UI ui;
    Inventory inventory;
    
    void DrawIcon();
    void DrawHP();
    void DrawMP();
    void DrawHotBar();

};

#endif