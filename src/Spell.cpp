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
        
        if (magnitude) {
            direction.x /= magnitude;
            direction.y /= magnitude;
        }
        
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
        if (distance > range) {
            active = false;
            currentPosition = summonerPosition;
        }

        // Trace
        currentPosition.x += direction.x * spellSpeed * deltaTime;
        currentPosition.y += direction.y * spellSpeed * deltaTime;

    }

}

void Spell::Draw() {

    if (active) DrawCircleV(currentPosition, 8, RED);

}

bool Spell::IsActive() const {
    return active;
}

void Spell::SetSummonerPosition(Vector2 currentSummonerPosition) {
    summonerPosition = currentSummonerPosition;
}

void Spell::SetTargetPosition(Vector2 target) {
    targetPosition = target;
}

// Vector2 Spell::currentPosition = {0, 0};
// // Vector2 Spell::targetPosition = {0, 0};

// Spell::Spell() : 
//     summonerPosition({0, 0}),
//     // currentPosition({0, 0}),
//     range(300),
//     spellSpeed(5),
//     active(false) {}

// Spell::Spell(Vector2 startPosition) :
//     summonerPosition(startPosition), 
//     // currentPosition(startPosition), 
//     range(300), 
//     spellSpeed(5), 
//     active(false) {
//         this->currentPosition = startPosition;
//     }

// void Spell::Cast(Vector2 targetPosition) {
//     // this->targetPosition = targetPosition;
//     direction = {targetPosition.x - summonerPosition.x, targetPosition.y - summonerPosition.y};
//     float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);

//     if (magnitude > 0) {
//         direction.x /= magnitude;
//         direction.y /= magnitude;
//     }

//     currentPosition = summonerPosition;
//     active = true;

// }

// void Spell::Update() {
    
//     if (active) {

//         // Current Distance
//         float distance = sqrt(
//             (currentPosition.x - summonerPosition.x) * (currentPosition.x - summonerPosition.x) +
//             (currentPosition.y - summonerPosition.y) * (currentPosition.y - summonerPosition.y)
//         );
        
//         // Max Range
//         if (distance > range) {
//             active = false;
//             currentPosition = summonerPosition;
//         }

//         // Trace
//         currentPosition.x += direction.x * spellSpeed;
//         currentPosition.y += direction.y * spellSpeed;

//         Draw();

//     }

    

// }