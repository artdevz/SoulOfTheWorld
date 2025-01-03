#ifndef MENU_HPP
#define MENU_HPP

#include "roots/Screen.hpp"
#include "ui/Window.hpp"

class Menu : public Screen {

    public:

        Menu();
        void Init() override;
        void Update() override;
        void Draw() override;

    private:

        Window window;

};

#endif