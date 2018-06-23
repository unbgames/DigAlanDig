#include "BigAlan.h"
#include "Game.h"
#include "InputManager.h"

void BigAlan::Update(float dt) {
    Sprite *sprite = associated.GetComponent<Sprite *>();

    if (currentState == BigAlan::BAState::STARTER) {
        if (Game::GetInstance()->combo > 10) {
            currentState = BigAlan::BAState::GOOD;
        }
    } else if (Game::GetInstance()->combo < 5 &&
               currentState != BigAlan::BAState::TRASH) {
        currentState = BigAlan::BAState::TRASH;
        state.file = "assets/img/mood3.png";
        sprite->Open(state, 0);
    } else if ((Game::GetInstance()->combo < 10 &&
                Game::GetInstance()->combo >= 5) &&
               currentState != BigAlan::BAState::DECENT) {
        currentState = BigAlan::BAState::DECENT;
        state.file = "assets/img/mood2.png";
        sprite->Open(state, 0);
    } else if (Game::GetInstance()->combo >= 10 &&
               currentState != BigAlan::BAState::GOOD) {
        currentState = BigAlan::BAState::GOOD;
        state.file = "assets/img/mood1.png";
        sprite->Open(state, 0);
    }
}
