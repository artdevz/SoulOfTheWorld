#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "UI.hpp"

class Game {

public:

    Game();
    void Init();
    void Update();
    void Draw();

private:

    Player player;
    UI ui;

};

#endif