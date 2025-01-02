#include "raylib.h"
#include "../include/core/Player.hpp"

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

void Player::Update() {

    float deltaTime = GetFrameTime();

    if (IsKeyDown(KEY_D)) (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))? position.x += 10*moveSpeed * deltaTime : position.x += moveSpeed * deltaTime;
    if (IsKeyDown(KEY_A)) (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))? position.x -= 10*moveSpeed * deltaTime : position.x -= moveSpeed * deltaTime;
    if (IsKeyDown(KEY_W)) (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))? position.y -= 10*moveSpeed * deltaTime : position.y -= moveSpeed * deltaTime;
    if (IsKeyDown(KEY_S)) (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))? position.y += 10*moveSpeed * deltaTime : position.y += moveSpeed * deltaTime;

}

void Player::Draw() {
    const char* coords = TextFormat("X: %.2f , Y: %.2f", position.x, position.y);
    DrawText(coords, 200, 200, 24, BLACK);
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