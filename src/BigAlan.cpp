#include "BigAlan.h"
#include "InputManager.h"
#include "Sprite.h"

void BigAlan::Update(float dt) {
    Sprite *sprite = associated.GetComponent<Sprite *>();

    if (InputManager::GetInstance().IsKeyDown(SDL_SCANCODE_1)) {
        sprite->Open("assets/img/mood1.png");
    }
    if (InputManager::GetInstance().IsKeyDown(SDL_SCANCODE_2)) {
        sprite->Open("assets/img/mood2.png");
    }
    if (InputManager::GetInstance().IsKeyDown(SDL_SCANCODE_3)) {
        sprite->Open("assets/img/mood3.png");
    }
}
