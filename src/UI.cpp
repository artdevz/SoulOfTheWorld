#include "../include/UI.hpp"
#include "raylib.h"

UI::UI() {}

void UI::Update() {
}

void UI::Draw() {
    DrawText("Pressione as teclas W A S D para mover o jogador", 10, 695, 20, DARKGRAY);
}