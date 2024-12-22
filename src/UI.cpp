#include "../include/UI.hpp"
#include "raylib.h"

UI::UI() {}

void UI::Update() {
}

void UI::Draw() {
    DrawText("Pressione as teclas para mover o jogador", 10, 10, 20, DARKGRAY);
}