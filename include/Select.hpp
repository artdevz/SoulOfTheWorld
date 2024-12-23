#ifndef PLAYMENU_HPP
#define PLAYMENU_HPP

#include "Screen.hpp"

class Select : public Screen {

public:

    Select();
    void Init() override;
    void Update() override;
    void Draw() override;

};

#endif