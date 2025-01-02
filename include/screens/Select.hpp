#ifndef SELECT_HPP
#define SELECT_HPP

#include "roots/Screen.hpp"
#include "Element.hpp"

class Select : public Screen {

public:

    static Element selectedElement;

    Select();
    Select(Element);
    static Element getSelectedElement();
    void Init() override;
    void Update() override;
    void Draw() override;

};

#endif