#ifndef MENU_HPP
#define MENU_HPP

#include "Screen.hpp"

class Menu : public Screen {

public:

    Menu();
    void Init() override;
    void Update() override;
    void Draw() override;

};

#endif