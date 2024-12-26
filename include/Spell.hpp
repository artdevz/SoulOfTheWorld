// Isso não é a Classe Spell, e sim a Classe Basic Spell, mas por enquanto estará nomeado assim

// Feitiços que o Jogador e Inimigos poderão usar
#ifndef SPELL_HPP
#define SPELL_HPP

#include "raylib.h"
#include "Player.hpp"

class Spell {

public:

    Spell();

    void Cast();
    void Update(Vector2, Vector2);
    void Draw();    

    bool IsActive() const;

    void SetSummonerPosition(Vector2 summonerPosition);
    void SetTargetPosition(Vector2 target); 

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