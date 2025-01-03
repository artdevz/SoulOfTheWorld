#include "raylib.h"
#include "world/Tile.hpp"

Tile::Tile() {}

Tile::Tile(Vector2 position, bool height, const Texture2D& textureRef) : 
    position(position),
    height(height),
    texture(textureRef) {}

void Tile::Draw() const {

    DrawTexture(texture, (int)position.x, (int)position.y, WHITE);

}

Vector2 Tile::GetPosition() const {
    return position;
}

bool Tile::GetHeight() const {
    return height;
}

int Tile::GetSize() const {
    return SIZE;
}