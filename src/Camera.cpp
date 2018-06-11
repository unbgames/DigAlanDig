#include "Camera.h"
#include <iostream>
#include "InputManager.h"

Vec2 Camera::pos, Camera::shake, Camera::speed(200, 200), Camera::screenSize;
Vec2 Camera::offset;

GameObject* Camera::focus = nullptr;
int Camera::shakeIntensity = 0;
float Camera::shakeDuration = 0;

void Camera::Follow(GameObject* newFocus) { focus = newFocus; }

void Camera::Unfollow() { focus = nullptr; }

Vec2 Camera::Center() { return pos + screenSize / 2; }

void Camera::Update(float dt) {
    if (shakeDuration > 0) {
        shakeDuration -= dt;
        shake = {sin((rand() % (int)(2000 * M_PI)) / 1000.0) * shakeIntensity,
                 sin((rand() % (int)(2000 * M_PI)) / 1000.0) * shakeIntensity};
    } else {
        shake = {0, 0};
    }

    if (focus) {
        if (focus->box.y >= screenSize.y / 2) {
            offset.y = -(screenSize.y / 2) + focus->box.y;
        }
        pos = shake + offset;

        return;
    }
    if (InputManager::GetInstance().KeyDown(SDL_SCANCODE_RIGHT)) {
        pos.x += speed.x * dt;
    }
    if (InputManager::GetInstance().KeyDown(SDL_SCANCODE_LEFT)) {
        pos.x -= speed.x * dt;
    }
    if (InputManager::GetInstance().KeyDown(SDL_SCANCODE_UP)) {
        pos.y -= speed.y * dt;
    }
    if (InputManager::GetInstance().KeyDown(SDL_SCANCODE_DOWN)) {
        pos.y += speed.y * dt;
    }
}

void Camera::Shake(int intensity, float duration) {
    shakeIntensity = intensity;
    shakeDuration = duration;
}
