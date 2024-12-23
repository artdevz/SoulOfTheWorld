#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "Element.hpp"

class Player {

public:

    Player();

    Player(Element element);

    void Update();

    void Draw();

private:

    Vector2 position;
    float moveSpeed;
    Element element; 
       
};

#endif