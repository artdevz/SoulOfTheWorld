#ifndef WATERBULLET_HPP
#define WATERBULLET_HPP

#include "raylib.h"
#include "core/Player.hpp"
#include "roots/Spell.hpp"

class WaterBullet : public Spell {

    public:

        WaterBullet();

        void Cast();
        void Update(Vector2, Vector2);
        void Draw();

    private:

        Vector2 summonerPosition;
        Vector2 currentPosition;
        Vector2 targetPosition;
        Vector2 direction;

        float range;
        float spellSpeed;
        bool active;

};

#endif