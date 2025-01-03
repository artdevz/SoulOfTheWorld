#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "resources/Element.hpp"
#include "world/Tile.hpp"

#include <vector>

class Player {

public:

    Player();

    Player(Element element);

    void Update(const std::vector<Tile> &tiles);

    void Draw();

    Vector2 GetPosition() const { return position; }

private:

    Vector2 position;
    float moveSpeed;
    Element element; 
       
};

#endif