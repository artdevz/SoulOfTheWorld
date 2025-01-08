#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "core/Player.hpp"

enum ScreenType { SCR_MAIN, SCR_SELECT, SCR_OPTIONS, SCR_GAME };

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