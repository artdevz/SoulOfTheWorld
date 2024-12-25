#include "../include/Inventory.hpp"
#include "raylib.h"

bool Inventory::inventoryState = false;

Inventory::Inventory() {}

void Inventory::Update() {

    if (IsKeyPressed(KEY_T)) inventoryState = !inventoryState;

}

void Inventory::Draw() {

    if (inventoryState) {
        DrawRectangle(200, 200, 400, 400, BLACK);
        DrawText("Inventory", 250, 220, 20, WHITE);
    }

}