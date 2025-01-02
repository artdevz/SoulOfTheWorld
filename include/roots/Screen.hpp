#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "core/Player.hpp"

enum ScreenType { SCREEN_MAIN, SCREEN_SELECT, SCREEN_GAME };

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