#include "raylib.h"
#include "../include/world/Tile.hpp"

Tile::Tile() {}

Tile::Tile(Vector2 position, const Texture2D& textureRef) : 
    position(position),
    texture(textureRef) {}

void Tile::Draw() const {

    DrawTexture(texture, (int)position.x, (int)position.y, WHITE);

}

Vector2 Tile::GetPosition() const {
    return position;
}