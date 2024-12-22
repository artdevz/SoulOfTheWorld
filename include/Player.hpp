#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"

class Player {

public:

    Player();

    void Update();

    void Draw();

private:

    Vector2 position;
    float moveSpeed; 
       
};

#endif