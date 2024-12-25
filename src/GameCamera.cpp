#include "../include/GameCamera.hpp"

GameCamera::GameCamera(Vector2 target, Vector2 offset) {

    camera.target = target;
    camera.offset = offset;
    camera.rotation = 0;
    camera.zoom = 2;

}

void GameCamera::Update(Vector2 target) {
    camera.target = target;
}

Camera2D GameCamera::GetCamera2D() const {
    return camera;
}