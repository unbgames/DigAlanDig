#include "Interpol.h"
#include "Game.h"
#include "Sprite.h"

Interpol::Interpol(GameObject &associated) : Component(associated) {}

void Interpol::Update(float dt) {
    Sprite *sprite = associated.GetComponent<Sprite *>();

    speed.x = 10 * dt * Game::GetInstance()->GetCurrentState().GetGridSize() /
              sprite->GetFrameCount();
    speed.y = 10 * dt * Game::GetInstance()->GetCurrentState().GetGridSize() /
              sprite->GetFrameCount();
}

bool Interpol::AttPosition(Vec2 newPos) {
    if (associated.box.x != newPos.x) {
        if (abs(newPos.x - associated.box.x) < speed.x) {
            associated.box.x += (newPos.x - associated.box.x);
        } else if (associated.box.x < newPos.x) {
            associated.box.x += speed.x;
        } else {
            associated.box.x -= speed.x;
        }
    }

    if (associated.box.y != newPos.y) {
        if (abs(newPos.y - associated.box.y) < speed.y) {
            associated.box.y += (newPos.y - associated.box.y);
        } else if (associated.box.y < newPos.y) {
            associated.box.y += speed.y;
        } else {
            associated.box.y -= speed.y;
        }
    }

    if (associated.box.x == newPos.x && associated.box.y == newPos.y)
        return true;

    return false;
}