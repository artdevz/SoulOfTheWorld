#include "raylib.h"
#include "../include/Player.hpp"

Player::Player() {
    position = {640, 360};
    moveSpeed = 5.0f;
    element = FIRE;    
}

Player::Player(Element element) {
    position = {640, 360};
    moveSpeed = 5.0f;
    element = element;
}

void Player::Update() {

    if (IsKeyDown(KEY_D)) position.x += moveSpeed;
    if (IsKeyDown(KEY_A)) position.x -= moveSpeed;
    if (IsKeyDown(KEY_W)) position.y -= moveSpeed;
    if (IsKeyDown(KEY_S)) position.y += moveSpeed;

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