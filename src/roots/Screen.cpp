#include "raylib.h"
#include "../include/roots/Screen.hpp"
#include "../include/screens/Game.hpp"
#include "../include/core/Player.hpp"
#include "roots/Screen.hpp"

Screen::Screen() {
    screenType = SCREEN_MAIN;
}

// Screen::~Screen() {}

void Screen::ClearScreen() {
    ClearBackground(Color{ 0x14, 0x16, 0x20, 255} );
}