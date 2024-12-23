#include "raylib.h"
#include "../include/Screen.hpp"
#include "../include/Game.hpp"
#include "../include/Player.hpp"
#include "Screen.hpp"

Screen::Screen() {
    screenType = SCREEN_MAIN;
}

// Screen::~Screen() {}

void Screen::ClearScreen() {
    ClearBackground(Color{ 0x14, 0x16, 0x20, 255} );
}