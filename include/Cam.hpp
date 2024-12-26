#ifndef CAM_HPP
#define CAM_HPP

#include "raylib.h"

class Cam {

public:

    Cam(Vector2 , Vector2);
    void Update(Vector2);
    Camera2D GetCamera2D() const;

private:

    Camera2D camera;

};

#endif