// Isso não é a Classe Spell, e sim a Classe Basic Spell, mas por enquanto estará nomeado assim

// Feitiços que o Jogador e Inimigos poderão usar
#ifndef SPELL_HPP
#define SPELL_HPP

#include "raylib.h"

class Spell {

public:

    Spell();
    // Spell(Vector2 startPosition);

    void Cast();
    void Update();
    void Draw();
    
    bool IsActive() const;

     

private:

    Vector2 summonerPosition;
    Vector2 currentPosition;
    //Vector2 targetPosition;
    Vector2 direction;

    float range;
    float spellSpeed;
    bool active;

    static Vector2 targetPosition;

};

#endif