// Inventário que será Dividido em Botas, Itens, Itens Suportes e Feitiços
/*
Poderá trocar com a Hotbar
*/
#ifndef INVENTORY_HPP
#define INVENTORY_HPP

class Inventory {

public:

    Inventory();
    void Update();
    void Draw();

private:

    static bool inventoryState;    

};

#endif