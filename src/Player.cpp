#include "raylib.h"
#include "../include/Player.hpp"

Player::Player() {
    position = {640, 360};
    moveSpeed = 5.0f;
}

void Player::Update() {

    if (IsKeyDown(KEY_D)) position.x += moveSpeed;
    if (IsKeyDown(KEY_A)) position.x -= moveSpeed;
    if (IsKeyDown(KEY_W)) position.y -= moveSpeed;
    if (IsKeyDown(KEY_S)) position.y += moveSpeed;

}

void Player::Draw() {
    DrawCircleV(position, 20, RED);
}