#include "raylib.h"

int main() {
    // Inicializa a janela
    InitWindow(800, 600, "Soul of The World");

    // Variáveis do jogo
    Vector2 player = {400, 300};

    SetTargetFPS(60); // Definir FPS

    while (!WindowShouldClose()) { // Loop do jogo
        // Lógica de movimento
        if (IsKeyDown(KEY_D)) player.x += 5;
        if (IsKeyDown(KEY_A)) player.x -= 5;
        if (IsKeyDown(KEY_W)) player.y -= 5;
        if (IsKeyDown(KEY_S)) player.y += 5;

        // Desenhar
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(player, 20, RED);
        EndDrawing();
    }

    // Fechar janela
    CloseWindow();
    return 0;
}
