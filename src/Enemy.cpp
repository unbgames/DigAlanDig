#include "Enemy.h"
#include "Alan.h"
#include "AlanActionControl.h"
#include "Camera.h"
#include "EnemySpawn.h"
#include "Game.h"
#include "Interpol.h"
#include "StageState.h"

Enemy::Enemy(GameObject &associated, int enemyType)
    : Component(associated), input(InputManager::GetInstance()) {
    if (enemyType == 1) {
        EState[State::IDLE_S] = {"assets/img/enemies/enemy1/idle.png", 2, 2,
                                 -1};
        EState[State::WALKIN_S] = {"assets/img/enemies/enemy1/walkin.png", 2, 4,
                                   0.2};
        EState[State::DIE_S] = {"assets/img/enemies/enemy1/idle.png", 2, 2,
                                0.2};
    } else if (enemyType == 2) {
        EState[State::IDLE_S] = {"assets/img/enemies/enemy2/idle.png", 2, 2,
                                 -1};
        EState[State::WALKIN_S] = {"assets/img/enemies/enemy2/walkin.png", 2, 4,
                                   0.2};
        EState[State::DIE_S] = {"assets/img/enemies/enemy2/idle.png", 2, 2,
                                0.2};
    } else if (enemyType == 3) {
        EState[State::IDLE_S] = {"assets/img/enemies/enemy3/idle.png", 2, 2,
                                 -1};
        EState[State::WALKIN_S] = {"assets/img/enemies/enemy3/walkin.png", 2, 4,
                                   0.2};
        EState[State::DIE_S] = {"assets/img/enemies/enemy3/idle.png", 2, 2,
                                0.2};
    } else {
        EState[State::IDLE_S] = {"assets/img/enemies/enemy1/idle.png", 2, 2,
                                 -1};
        EState[State::WALKIN_S] = {"assets/img/enemies/enemy1/walkin.png", 2, 4,
                                   0.2};
        EState[State::DIE_S] = {"assets/img/enemies/enemy1/idle.png", 2, 2,
                                0.2};
    }

    Sprite *sprite = new Sprite(associated);
    Interpol *interpol = new Interpol(associated);
    associated.AddComponent(sprite);
    associated.AddComponent(interpol);
    sprite->Open(EState[state], Enemy::Direction::LEFT);

    hp = enemyType;
    range = enemyType;

    tileMapPos.x = associated.box.x;
    tileMapPos.y = associated.box.y;
}

bool Enemy::VerifyDeath(Alan *alan) {
    // Inimigo morre se:
    // 1. HP <= 0
    if (hp <= 0) {
        return true;
    }
    // 2. Alan cai em cima dele
    if (Game::GetInstance()->GetGridControl()->TestPath(
            Vec2(associated.gridPosition.x, associated.gridPosition.y),
            false) == GridControl::WhatsThere::ALAN) {
        return true;
    }
    // 3. Scroll da camera já passou da posição dele
    if (associated.GetGridPosition().y <
        (Camera::pos.y / Game::GetInstance()->GetCurrentState().GetGridSize()) -
            3) {
        return true;
    }
    // 4. Espaço embaixo dele não é uma pedra
    if (Game::GetInstance()->GetGridControl()->TestPath(
            Vec2(associated.gridPosition.x, associated.gridPosition.y + 1),
            false) != GridControl::WhatsThere::ROCK) {
        return true;
    }

    return false;
}

void Enemy::ShouldTakeDamage(Alan *alan) {
    if (state != State::IDLE_S) return;

    if (Game::GetInstance()->GetGridControl()->TestPath(
            Vec2(associated.gridPosition.x - 1, associated.gridPosition.y),
            false) == GridControl::WhatsThere::ALAN &&
        alan->GetMovementDirection() == AlanActionControl::Direction::RIGHT) {
        if (!damageTaken) {
            TakeDamage(alan->GetDamage());
            damageTaken = true;
        }

    } else if (Game::GetInstance()->GetGridControl()->TestPath(
                   Vec2(associated.gridPosition.x + 1,
                        associated.gridPosition.y),
                   false) == GridControl::WhatsThere::ALAN &&
               alan->GetMovementDirection() ==
                   AlanActionControl::Direction::LEFT) {
        if (!damageTaken) {
            TakeDamage(alan->GetDamage());
            damageTaken = true;
        }
    } else {
        damageTaken = false;
    }
}

void Enemy::IsSurrounded() {
    if (Game::GetInstance()->GetGridControl()->TestPath(
            Vec2(associated.gridPosition.x - 1, associated.gridPosition.y),
            false) != GridControl::WhatsThere::FREE &&
        Game::GetInstance()->GetGridControl()->TestPath(
            Vec2(associated.gridPosition.x + 1, associated.gridPosition.y),
            false) != GridControl::WhatsThere::FREE)
        movementAllowed = false;
}

void Enemy::Update(float dt) {
    if (!Game::GetInstance()->GetGridControl()->GetAlan().lock() ||
        !associated.GetComponent<Interpol *>()->IsMovementDone())
        return;

    Sprite *sprite = associated.GetComponent<Sprite *>();
    Alan *alan = Game::GetInstance()
                     ->GetGridControl()
                     ->GetAlan()
                     .lock()
                     ->GetComponent<Alan *>();

    ShouldTakeDamage(alan);

    if (VerifyDeath(alan) || state == Enemy::State::DIE_S) {
        if (state != Enemy::State::DIE_S) {
            state = Enemy::State::DIE_S;
            sprite->Open(EState[state], Enemy::Direction::LEFT);
        }
        if (sprite->FrameTimePassed()) {
            Game::GetInstance()->GetGridControl()->DeleteEnemy(&associated);
            associated.RequestDelete();
        }
        return;
    }

    if (alan->GetAction() != AlanActionControl::Action::CLIMBING &&
        alan->GetAction() != AlanActionControl::Action::FALLIN) {
        if (Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x + 1, associated.gridPosition.y),
                false) == GridControl::WhatsThere::ALAN ||
            Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x - 1, associated.gridPosition.y),
                false) == GridControl::WhatsThere::ALAN) {
            // Change game color pallet
        }
    }

    if (movementDirection == Enemy::Direction::LEFT) {
        if (Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x - 1, associated.gridPosition.y),
                false) != GridControl::WhatsThere::FREE ||
            Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x - 1,
                     associated.gridPosition.y + 1),
                false) != GridControl::WhatsThere::ROCK) {
            movementAllowed = false;
            movementDirection = Enemy::Direction::RIGHT;
            steps = 0;
        }
    } else {
        if (Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x + 1, associated.gridPosition.y),
                false) != GridControl::WhatsThere::FREE ||
            Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x + 1,
                     associated.gridPosition.y + 1),
                false) != GridControl::WhatsThere::ROCK) {
            movementAllowed = false;
            movementDirection = Enemy::Direction::LEFT;
            steps = 0;
        }
    }

    IsSurrounded();
    Game::GetInstance()->GetGridControl()->CheckEnemyAlanCollision(false);

    if (movementAllowed) {
        if (state != Enemy::State::WALKIN_S) {
            state = Enemy::State::WALKIN_S;
            sprite->Open(EState[state], movementDirection);
        }
        if (steps < range) {
            if (movementDirection == Enemy::Direction::LEFT) {
                movementAllowed = false;
                steps++;
                associated.gridPosition.x--;

            } else {
                movementAllowed = false;
                steps++;
                associated.gridPosition.x++;
            }

        } else {
            if (movementDirection == Enemy::Direction::LEFT) {
                movementDirection = Enemy::Direction::RIGHT;
            } else {
                movementDirection = Enemy::Direction::LEFT;
            }
            steps = 0;
        }
    } else {
        if (state != Enemy::State::IDLE_S) {
            state = Enemy::State::IDLE_S;
            sprite->Open(EState[state], movementDirection);
        }
    }
}
