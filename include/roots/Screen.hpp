#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "core/Player.hpp"

enum ScreenType { SCREEN_MAIN_MENU, SCREEN_SELECT_MENU, SCREEN_OPTIONS, SCREEN_GAME }; // Trocar para SCR_x

class Screen {

public:

    ScreenType screenType;
    
    Screen();
    void ClearScreen();
    
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    
private:

};

#endif