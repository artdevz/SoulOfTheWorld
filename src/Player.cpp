#include "raylib.h"
#include "../include/Player.hpp"

Player::Player() {
    position = {640, 360};
    moveSpeed = 100.0f;
    element = WATER;    
}

Player::Player(Element element) {
    position = {640, 360};
    moveSpeed = 100.0f;
    this->element = element;
}

void Player::Update() {

    float deltaTime = GetFrameTime();

    if (IsKeyDown(KEY_D)) position.x += moveSpeed * deltaTime;
    if (IsKeyDown(KEY_A)) position.x -= moveSpeed * deltaTime;
    if (IsKeyDown(KEY_W)) position.y -= moveSpeed * deltaTime;
    if (IsKeyDown(KEY_S)) position.y += moveSpeed * deltaTime;

}

void Player::Draw() {

    switch (this->element) {
        
        case FIRE:
            DrawCircleV(position, 20, ORANGE);                       
            break;

        case WATER:
            DrawCircleV(position, 20, BLUE);            
            break;

        case EARTH:
            DrawCircleV(position, 20, RED);
            break;

        case AIR:
            DrawCircleV(position, 20, GREEN);
            break;
    
        default:
            DrawCircleV(position, 20, BLACK);
            break;
        }
    
}

// Vector2 Player::GetPosition() const {
//     return position;
// }