// Isso não é a Classe Spell, e sim a Classe Basic Spell, mas por enquanto estará nomeado assim
#include "../include/Spell.hpp"
#include <cmath>
#include <iostream>
#include "Spell.hpp"

Spell::Spell() :
    summonerPosition( {640, 360} ),
    currentPosition( {0, 0} ),    
    range(300),
    spellSpeed(5),
    active(false) {}

void Spell::Cast() {

    if (!active) {
        active = true;
        currentPosition = summonerPosition;
        // Draw();
        
    }

}

void Spell::Update() {

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) Cast();

    float deltaTime = GetFrameTime();
    
    currentPosition.x += 100 * deltaTime;
    currentPosition.y += 100 * deltaTime;
    
    if (currentPosition.x > 900) active = false;

}

void Spell::Draw() {

    if (active) DrawCircleV(currentPosition, 16, RED);

}

bool Spell::IsActive() const {
    return active;
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

// void Spell::Draw() {
//     if(active) DrawCircleV(currentPosition, 16, RED);    
// }

// bool Spell::IsActive() const {
//     return active;
// }














// void Spell::BasicSpell() {

//     // BeginDrawing();

//     Vector2 summonerPosition = {640, 360}; // Centro
//     Vector2 mousePosition = GetMousePosition();
//     float range = 300;

//     Vector2 direction = {
//         mousePosition.x - summonerPosition.x,
//         mousePosition.y - summonerPosition.y
//     };

//     float magnitude = sqrt(direction.x * direction.x + direction.y * direction.y);
    
//     if (magnitude > 0) {
//         direction.x /= magnitude;
//         direction.y /= magnitude;
//     }
    
//     float spellSpeed = 5;
    
//     Vector2 currentPosition = summonerPosition;

//     while (true) {
        
//         // Current Distance
//         float distance = sqrt(
//             (currentPosition.x - summonerPosition.x) * (currentPosition.x - summonerPosition.x) +
//             (currentPosition.y - summonerPosition.y) * (currentPosition.y - summonerPosition.y)
//         );
        
//         // Max Range
//         if (distance > range || 
//             (fabs(currentPosition.x - mousePosition.x) < spellSpeed && fabs(currentPosition.y - mousePosition.y) < spellSpeed))
//             break;
        
//         DrawCircle(currentPosition.x - direction.x * spellSpeed, currentPosition.y - direction.y * spellSpeed, 16, RAYWHITE);
//         DrawCircle(currentPosition.x, currentPosition.y, 16, RED);
        
//         // Trace
//         currentPosition.x += direction.x * spellSpeed;
//         currentPosition.y += direction.y * spellSpeed;
//     }

//     // EndDrawing();

// }