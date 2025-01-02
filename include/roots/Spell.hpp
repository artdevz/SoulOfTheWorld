#ifndef SPELL_HPP
#define SPELL_HPP

#include "raylib.h"

class Spell {

    public:

        Vector2 summonerPos;
        Vector2 currentPos;
        Vector2 targetPos;
        Vector2 direction;

        float cooldown; // Time in Seconds
        float manaCost;
        
        Spell();

        virtual void Cast();
        virtual void Update(Vector2, Vector2);
        virtual void Draw();

    private:

};

#endif