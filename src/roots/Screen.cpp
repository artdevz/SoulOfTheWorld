#include "raylib.h"
#include "roots/Screen.hpp"
#include "screens/Game.hpp"
#include "core/Player.hpp"
#include "roots/Screen.hpp"

Screen::Screen() {
    screenType = SCR_MAIN;
    TraceLog(LOG_INFO, "Criado Screen");
}

// Screen::~Screen() {}

void Screen::ClearScreen() {
    ClearBackground(Color{ 0x14, 0x16, 0x20, 255} );
}