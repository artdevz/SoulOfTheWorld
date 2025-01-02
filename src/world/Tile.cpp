#include "raylib.h"
#include "../include/world/Tile.hpp"

Tile::Tile() {}

Tile::Tile(Vector2 position, const char* texturePath) : 
    position(position) {
        texture = LoadTexture(texturePath);
    }

void Tile::Draw() const {

    DrawTexture(texture, position.x, position.y, WHITE);

}

Vector2 Tile::GetPosition() const {
    return position;
}