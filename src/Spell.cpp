// Isso não é a Classe Spell, e sim a Classe Basic Spell, mas por enquanto estará nomeado assim
#include "../include/Spell.hpp"
#include <cmath>
#include "Spell.hpp"
#include "Player.hpp"

Spell::Spell() :
    summonerPosition( {0, 0} ),
    currentPosition( {0, 0} ),
    targetPosition( {0, 0} ),    
    range(300),
    spellSpeed(100),
    active(false) {}

void Spell::Cast() {

    if (!active) {

        active = true;
        currentPosition = summonerPosition;
        
        direction = {targetPosition.x - summonerPosition.x, targetPosition.y - summonerPosition.y};
        float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y); // Modulo do Vetor
        
        if (magnitude) direction = {direction.x / magnitude, direction.y / magnitude};
                
    }

}

void Spell::Update(Vector2 spellSummonerPosition, Vector2 mousePosition) {

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        
        if (!active) {
            summonerPosition = spellSummonerPosition;
            targetPosition = mousePosition;              
            Cast();
                 
        }
        
    }

    if (active) {

        float deltaTime = GetFrameTime();
        
        // Current Distance
        float distance = sqrt(
            (currentPosition.x - summonerPosition.x) * (currentPosition.x - summonerPosition.x) +
            (currentPosition.y - summonerPosition.y) * (currentPosition.y - summonerPosition.y)
        );

        // Max Range
        if (distance > range) active = false;

        // Trace
        currentPosition.x += direction.x * spellSpeed * deltaTime;
        currentPosition.y += direction.y * spellSpeed * deltaTime;        
        
    }

}

void Spell::Draw() {

    if (active) DrawCircleV(currentPosition, 8, RED);

}