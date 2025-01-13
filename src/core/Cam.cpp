#include "core/Cam.hpp"
#include "ui/Window.hpp"

Cam::Cam(Vector2 target, Vector2 offset) {

    camera.target = target;
    camera.offset = offset;
    camera.rotation = 0;
    camera.zoom = 1.5;

}

void Cam::Update(Vector2 target) {
    camera.target = target;
    target = {Window::resolution.x / 2, Window::resolution.y / 2};
    camera.offset = {Window::resolution.x / 2, Window::resolution.y / 2};
}

Camera2D Cam::GetCamera2D() const {
    return camera;
}