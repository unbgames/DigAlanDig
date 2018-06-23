#include "Enemy.h"
#include "Alan.h"
#include "Game.h"
#include "Interpol.h"

Enemy::Enemy(GameObject &associated, int enemyType, int range)
    : Component(associated), range(range), input(InputManager::GetInstance()) {
    if (enemyType == 1) {
        EState[State::IDLE_S] = {"assets/img/enemies/enemy1/idle.png", 2, 2,
                                 -1};
        EState[State::WALKIN_S] = {"assets/img/enemies/enemy1/walkin.png", 2, 4,
                                   0.2};
        // EState[State::HIT_S] = {"assets/img/alan/hit.png", 2, 2, -1};
        EState[State::HIT_S] = {"assets/img/enemies/enemy1/hit.png", 2, 2, 0.2};
        EState[State::DIE_S] = {"assets/img/enemies/enemy1/die.png", 2, 2, 0.2};
    } else if (enemyType == 2) {
        EState[State::IDLE_S] = {"assets/img/enemies/enemy2/idle.png", 2, 2,
                                 -1};
        EState[State::WALKIN_S] = {"assets/img/enemies/enemy2/walkin.png", 2, 4,
                                   0.2};
        // EState[State::HIT_S] = {"assets/img/alan/hit.png", 2, 2, -1};
        EState[State::HIT_S] = {"assets/img/enemies/enemy2/hit.png", 2, 2, 0.2};
        EState[State::DIE_S] = {"assets/img/enemies/enemy2/die.png", 2, 2, 0.2};
    } else if (enemyType == 3) {
        EState[State::IDLE_S] = {"assets/img/enemies/enemy3/idle.png", 2, 2,
                                 -1};
        EState[State::WALKIN_S] = {"assets/img/enemies/enemy3/walkin.png", 2, 4,
                                   0.2};
        // EState[State::HIT_S] = {"assets/img/alan/hit.png", 2, 2, -1};
        EState[State::HIT_S] = {"assets/img/enemies/enemy3/hit.png", 2, 2, 0.2};
        EState[State::DIE_S] = {"assets/img/enemies/enemy3/die.png", 2, 2, 0.2};
    } else {
        std::cout << "ERRO: enemy not valid!" << std::endl;
        return;
    }

    hp = enemyType * 2;
}

void Enemy::Update(float dt) {
    Sprite *sprite = associated.GetComponent<Sprite *>();

    if (hp <= 0) {
        if (state != Enemy::State::DIE_S) {
            state = Enemy::State::DIE_S;
            sprite->Open(EState[state], Enemy::Direction::LEFT);
        }
        if (sprite->FrameTimePassed()) {
            associated.RequestDelete();
        }
        return;
    }

    Interpol *interpol = associated.GetComponent<Interpol *>();
    Alan *alan = Game::GetInstance()
                     ->GetGridControl()
                     ->GetAlan()
                     .lock()
                     ->GetComponent<Alan *>();

    if (alan->GetAction() != Alan::Action::CLIMBING &&
        alan->GetAction() != Alan::Action::FALLIN) {
        if (Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x + 1, associated.gridPosition.y),
                false) == GridControl::WhatsThere::ALAN ||
            Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x - 1, associated.gridPosition.y),
                false) == GridControl::WhatsThere::ALAN) {
            // Change game color pallet
        }

    } else if (movimentAllowed) {
        if (state != Enemy::State::WALKIN_S) {
            state = Enemy::State::WALKIN_S;
            sprite->Open(EState[state], movementDirection);
        }

        if (steps < range) {
            if (Game::GetInstance()->GetGridControl()->TestPath(
                    Vec2(associated.gridPosition.x - 1,
                         associated.gridPosition.y + 1),
                    true) == GridControl::WhatsThere::FREE ||
                Game::GetInstance()->GetGridControl()->TestPath(
                    Vec2(associated.gridPosition.x + 1,
                         associated.gridPosition.y + 1),
                    true) == GridControl::WhatsThere::FREE) {
                if (movementDirection == Enemy::Direction::LEFT) {
                    movementDirection = Enemy::Direction::RIGHT;
                } else {
                    movementDirection = Enemy::Direction::LEFT;
                }
                steps = 0;
                sprite->Open(EState[state], movementDirection);

            } else if (movementDirection == Enemy::Direction::LEFT) {
                if (Game::GetInstance()->GetGridControl()->TestPath(
                        Vec2(associated.gridPosition.x - 1,
                             associated.gridPosition.y),
                        true) == GridControl::WhatsThere::ROCK_STRONG ||
                    Game::GetInstance()->GetGridControl()->TestPath(
                        Vec2(associated.gridPosition.x - 1,
                             associated.gridPosition.y),
                        true) == GridControl::WhatsThere::ROCK_WEAK) {
                    movementDirection = Enemy::Direction::RIGHT;
                    sprite->Open(EState[state], movementDirection);
                    movimentAllowed = false;
                    steps = 0;
                    return;
                }

                if (interpol->AttPosition(Vec2(
                        (associated.gridPosition.x - 1) *
                                Game::GetInstance()
                                    ->GetCurrentState()
                                    .GetGridSize() -
                            Game::GetInstance()
                                    ->GetCurrentState()
                                    .GetGridSize() /
                                2,
                        (associated.gridPosition.y) * Game::GetInstance()
                                                          ->GetCurrentState()
                                                          .GetGridSize() -
                            Game::GetInstance()
                                    ->GetCurrentState()
                                    .GetGridSize() /
                                2))) {
                    movimentAllowed = false;
                    steps++;
                    associated.gridPosition.x--;
                }
            } else {
                if (Game::GetInstance()->GetGridControl()->TestPath(
                        Vec2(associated.gridPosition.x + 1,
                             associated.gridPosition.y),
                        true) == GridControl::WhatsThere::ROCK_STRONG ||
                    Game::GetInstance()->GetGridControl()->TestPath(
                        Vec2(associated.gridPosition.x + 1,
                             associated.gridPosition.y),
                        true) == GridControl::WhatsThere::ROCK_WEAK) {
                    movementDirection = Enemy::Direction::LEFT;
                    sprite->Open(EState[state], movementDirection);
                    movimentAllowed = false;
                    steps = 0;
                    return;
                }

                if (interpol->AttPosition(Vec2(
                        (associated.gridPosition.x + 1) *
                                Game::GetInstance()
                                    ->GetCurrentState()
                                    .GetGridSize() -
                            Game::GetInstance()
                                    ->GetCurrentState()
                                    .GetGridSize() /
                                2,
                        (associated.gridPosition.y) * Game::GetInstance()
                                                          ->GetCurrentState()
                                                          .GetGridSize() -
                            Game::GetInstance()
                                    ->GetCurrentState()
                                    .GetGridSize() /
                                2))) {
                    movimentAllowed = false;
                    steps++;
                    associated.gridPosition.x++;
                }
            }
        } else {
            if (movementDirection == Enemy::Direction::LEFT) {
                movementDirection = Enemy::Direction::RIGHT;
            } else {
                movementDirection = Enemy::Direction::LEFT;
            }
            steps = 0;
            sprite->Open(EState[state], movementDirection);
        }
    } else {
        if (state != Enemy::State::IDLE_S) {
            state = Enemy::State::IDLE_S;
            sprite->Open(EState[state], movementDirection);
        }
    }
}