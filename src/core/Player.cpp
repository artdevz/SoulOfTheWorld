#include "raylib.h"
#include "../include/core/Player.hpp"
#include "../include/world/Tile.hpp"

#include <vector>

Player::Player() {
    position = {0, 0};
    moveSpeed = 100.0f;
    element = WATER;    
}

Player::Player(Element element) {
    position = {0, 0};
    moveSpeed = 100.0f;
    this->element = element;
}

void Player::Update(const std::vector<Tile>& tiles) {

    float deltaTime = GetFrameTime();

    Vector2 nextPos = position;

    if (IsKeyDown(KEY_D)) nextPos.x += (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) ? 10 * moveSpeed * deltaTime : moveSpeed * deltaTime;
    if (IsKeyDown(KEY_A)) nextPos.x -= (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) ? 10 * moveSpeed * deltaTime : moveSpeed * deltaTime;
    if (IsKeyDown(KEY_W)) nextPos.y -= (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) ? 10 * moveSpeed * deltaTime : moveSpeed * deltaTime;
    if (IsKeyDown(KEY_S)) nextPos.y += (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) ? 10 * moveSpeed * deltaTime : moveSpeed * deltaTime;

    bool canMove = true;

    for (const auto& tile : tiles) {

        Rectangle tileRect = { tile.GetPosition().x, tile.GetPosition().y, (float)tile.GetSize(), (float)tile.GetSize() };

        if (
            (CheckCollisionPointRec(nextPos, tileRect) && tile.GetHeight()) ||    // Centro
            (CheckCollisionPointRec({ nextPos.x+16, nextPos.y }, tileRect) && tile.GetHeight()) ||    // Esquerda
            (CheckCollisionPointRec({ nextPos.x-16, nextPos.y }, tileRect) && tile.GetHeight()) ||    // Direita
            (CheckCollisionPointRec({ nextPos.x, nextPos.y-16 }, tileRect) && tile.GetHeight()) ||    // Cima
            (CheckCollisionPointRec({ nextPos.x, nextPos.y+16 }, tileRect) && tile.GetHeight())       // Baixo
            ) {
            canMove = false; break;
        }

    }

    if (canMove) position = nextPos;

}

void Player::Draw() {
    const char* coords = TextFormat("X: %.2f , Y: %.2f", position.x, position.y);
    DrawText(coords, 200, 200, 24, BLACK);
    switch (this->element) {
        
        case FIRE:
            DrawCircleV(position, 16, ORANGE);                       
            break;

        case WATER:
            DrawCircleV(position, 16, BLUE);            
            break;

        case EARTH:
            DrawCircleV(position, 16, RED);
            break;

        case AIR:
            DrawCircleV(position, 16, GREEN);
            break;
    
        default:
            DrawCircleV(position, 16, BLACK);
            break;
        }
    
}