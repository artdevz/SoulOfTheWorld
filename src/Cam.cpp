#include "../include/Cam.hpp"

Cam::Cam(Vector2 target, Vector2 offset) {

    camera.target = target;
    camera.offset = offset;
    camera.rotation = 0;
    camera.zoom = 2;

}

void Cam::Update(Vector2 target) {
    camera.target = target;
}

Camera2D Cam::GetCamera2D() const {
    return camera;
}