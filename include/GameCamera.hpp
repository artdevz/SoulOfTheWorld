#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "raylib.h"

class GameCamera {

public:

    GameCamera(Vector2 , Vector2);
    void Update(Vector2);
    Camera2D GetCamera2D() const;

private:

    Camera2D camera;

};

#endif