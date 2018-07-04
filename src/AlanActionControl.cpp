#include "AlanActionControl.h"
#include "Alan.h"
#include "Game.h"
#include "Interpol.h"
#include "Sprite.h"

bool AlanActionControl::ShouldFall() {
    return gridsLeft ||
           ((Game::GetInstance()->GetGridControl()->TestPath(
                 Vec2(associated.gridPosition.x, associated.gridPosition.y + 1),
                 true) == GridControl::WhatsThere::FREE ||
             Game::GetInstance()->GetGridControl()->TestPath(
                 Vec2(associated.gridPosition.x, associated.gridPosition.y + 1),
                 true) == GridControl::WhatsThere::ENEMY) &&
            action != Action::CLIMBING);
}

void AlanActionControl::Fallin(float dt) {
    Interpol *interpol = associated.GetComponent<Interpol *>();

    if (interpol->AttPosition(
            Vec2(associated.gridPosition.x * gridSize - gridSize / 2,
                 (associated.gridPosition.y + 1) * gridSize - gridSize / 2)) &&
        gridsLeft == 0) {
        action = Action::STANDIN;
    }

    if (associated.box.y >=
        (associated.gridPosition.y + 1) * gridSize - gridSize / 2) {
        associated.gridPosition.y++;
        movementDirection = Direction::NONE;
        gridsLeft--;
        associated.GetComponent<Sprite *>()->TimeElapsedReset();
    }
}

bool AlanActionControl::IsFree() {
    if (movementDirection == Direction::LEFT) {
        if (Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x - 1, associated.gridPosition.y),
                true) == GridControl::WhatsThere::FREE)
            return true;
    }

    if (movementDirection == Direction::RIGHT) {
        if (Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x + 1, associated.gridPosition.y),
                true) == GridControl::WhatsThere::FREE)
            return true;
    }

    return false;
}

bool AlanActionControl::IsBlock() {
    if (movementDirection == Direction::LEFT) {
        if (Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x - 1, associated.gridPosition.y),
                true) == GridControl::WhatsThere::ROCK)
            return true;
    }

    if (movementDirection == Direction::RIGHT) {
        if (Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x + 1, associated.gridPosition.y),
                true) == GridControl::WhatsThere::ROCK)
            return true;
    }
    return false;
}

bool AlanActionControl::CanClimb() {
    return input.KeyDown(SDL_SCANCODE_A) && action != Action::WALKIN;
}

bool AlanActionControl::InClimbPosition(AlanAnimation *animation) {
    return (animation->GetCurrentState() == AlanAnimation::State::CLIMBIN ||
            animation->GetOldState() == AlanAnimation::State::CLIMBIN) &&
           animation->GetCurrentState() != AlanAnimation::State::IDLE;
}

bool AlanActionControl::ClimbPathFree() {
    if (movementDirection == Direction::UP) {
        if (Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x, associated.gridPosition.y - 1),
                true) == GridControl::WhatsThere::FREE)
            return true;
    }

    if (movementDirection == Direction::DOWN) {
        if (Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x, associated.gridPosition.y + 1),
                true) == GridControl::WhatsThere::FREE)
            return true;
    }

    return false;
}

bool AlanActionControl::IsNone() {
    if (movementDirection == Direction::LEFT) {
        if (Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x - 1, associated.gridPosition.y),
                true) == GridControl::WhatsThere::NONE)
            return true;
    }

    if (movementDirection == Direction::RIGHT) {
        if (Game::GetInstance()->GetGridControl()->TestPath(
                Vec2(associated.gridPosition.x + 1, associated.gridPosition.y),
                true) == GridControl::WhatsThere::NONE)
            return true;
    }

    return false;
}

bool AlanActionControl::IsClimbDirectionLeft(AlanAnimation *animation) {
    return (animation->GetCurrentDirection() ==
                AlanAnimation::Direction::LEFT ||
            animation->GetOldDirection() == AlanAnimation::Direction::LEFT) &&
           animation->GetCurrentDirection() != AlanAnimation::Direction::RIGHT;
}

void AlanActionControl::Update(float dt) {
    Alan *alan = associated.GetComponent<Alan *>();
    AlanAnimation *animation = associated.GetComponent<AlanAnimation *>();
    TileMap *tileMap = Game::GetInstance()->GetCurrentState().tileMap;
    Sprite *sprite = associated.GetComponent<Sprite *>();

    if (alan->GetHP() <= 0) {
        if (animation->GetCurrentState() != AlanAnimation::State::DEAD) {
            animation->SetAction(AlanAnimation::Transition::DIE,
                                 AlanAnimation::Direction::LEFT);

            /*
                        std::cout << "\n\n\n\n\n\n\nCAMERAPOS = " <<
               Camera::pos.y
                                  << std::endl;
                        Camera::SetNewCameraPos(
                            Vec2(Camera::pos.x, Camera::pos.y -
               Camera::screenSize.y)); std::cout << "CAMERAPOS = " <<
               Camera::pos.y << std::endl;
             */
        }

        if (sprite->FrameTimePassed()) {
            Game::GetInstance()->combo = 0;
        }
        return;
    }

    // Testa se a marmota deve "cair" ou ficar na posição atual
    if (ShouldFall()) {
        if (gridsLeft == 0) {
            movementDirection = Direction::DOWN;
            action = Action::FALLIN;
            int y = associated.gridPosition.y + 1;
            while (!tileMap->At(associated.gridPosition.x, y)) {
                gridsLeft++;
                y++;
            }
            animation->SetAction(AlanAnimation::Transition::FALL,
                                 AlanAnimation::Direction::LEFT);
        }

        Fallin(dt);

        return;
    }

    if (animation->GetCurrentState() == AlanAnimation::State::FALLIN) {
        animation->SetAction(AlanAnimation::Transition::FLOOR,
                             AlanAnimation::Direction::LEFT);
        action = Action::STANDIN;
        movementDirection = Direction::NONE;
    }

    if (movementDirection == Direction::NONE) {
        if (action != Action::CLIMBING || !input.KeyDown(SDL_SCANCODE_A)) {
            animation->SetAction(AlanAnimation::Transition::NONE_T,
                                 AlanAnimation::Direction::LEFT);
            action = Action::STANDIN;
        }

        return;
    }

    Interpol *interpol = associated.GetComponent<Interpol *>();

    // 'A' apertado indica que o movimento é de escalada
    if (CanClimb()) {
        if (InClimbPosition(animation)) {
            if (movementDirection == Direction::UP) {
                if (ClimbPathFree()) {
                    if (IsClimbDirectionLeft(animation)) {
                        if (Game::GetInstance()->GetGridControl()->TestPath(
                                Vec2(associated.gridPosition.x - 1,
                                     associated.gridPosition.y - 1),
                                true) == GridControl::WhatsThere::FREE) {
                            if (interpol->AttPosition(Vec2(
                                    (associated.gridPosition.x - 1) * gridSize -
                                        gridSize / 2,
                                    (associated.gridPosition.y - 1) * gridSize -
                                        gridSize / 2))) {
                                movementDirection = Direction::NONE;
                                associated.gridPosition.y--;
                                associated.gridPosition.x--;
                                animation->SetAction(
                                    AlanAnimation::Transition::NONE_T,
                                    AlanAnimation::Direction::LEFT);
                            }
                        } else {
                            if (!animationOnGoing) {
                                animation->SetAction(
                                    AlanAnimation::Transition::WALK,
                                    AlanAnimation::Direction::UP);
                                animationOnGoing = true;
                            }
                            if (interpol->AttPosition(Vec2(
                                    (associated.gridPosition.x) * gridSize -
                                        gridSize / 2,
                                    (associated.gridPosition.y - 1) * gridSize -
                                        gridSize / 2))) {
                                movementDirection = Direction::NONE;
                                associated.gridPosition.y--;
                                animationOnGoing = false;
                            }
                        }
                        // Verifica se a marmota está em posição de escalada
                    } else {
                        if (Game::GetInstance()->GetGridControl()->TestPath(
                                Vec2(associated.gridPosition.x + 1,
                                     associated.gridPosition.y - 1),
                                true) == GridControl::WhatsThere::FREE) {
                            if (interpol->AttPosition(Vec2(
                                    (associated.gridPosition.x + 1) * gridSize -
                                        gridSize / 2,
                                    (associated.gridPosition.y - 1) * gridSize -
                                        gridSize / 2))) {
                                movementDirection = Direction::NONE;
                                associated.gridPosition.y--;
                                associated.gridPosition.x++;
                                animation->SetAction(
                                    AlanAnimation::Transition::NONE_T,
                                    AlanAnimation::Direction::RIGHT);
                            }
                        } else {
                            if (!animationOnGoing) {
                                animation->SetAction(
                                    AlanAnimation::Transition::WALK,
                                    AlanAnimation::Direction::UP);
                                animationOnGoing = true;
                            }
                            if (interpol->AttPosition(Vec2(
                                    (associated.gridPosition.x) * gridSize -
                                        gridSize / 2,
                                    (associated.gridPosition.y - 1) * gridSize -
                                        gridSize / 2))) {
                                movementDirection = Direction::NONE;
                                associated.gridPosition.y--;
                                animationOnGoing = false;
                            }
                        }
                    }
                } else {
                    if (!animationOnGoing) {
                        animation->SetAction(AlanAnimation::Transition::DIG_T,
                                             AlanAnimation::Direction::UP);
                        animationOnGoing = true;
                    }
                    if (sprite->FrameTimePassed()) {
                        tileMap->GetDamageGround(
                            1, Vec2(associated.gridPosition.x,
                                    associated.gridPosition.y - 1));
                        movementDirection = Direction::NONE;
                        animationOnGoing = false;
                    }
                }

            } else if (movementDirection == Direction::DOWN) {
                // Mesmo processo anterior para a baixo (quando a pedra
                // abaixo do lado onde a marmota estiver escalando for vazia
                // ela não faz nada)

                if (ClimbPathFree()) {
                    if (IsClimbDirectionLeft(animation)) {
                        if (Game::GetInstance()->GetGridControl()->TestPath(
                                Vec2(associated.gridPosition.x - 1,
                                     associated.gridPosition.y + 1),
                                true) == GridControl::WhatsThere::FREE) {
                            movementDirection = Direction::NONE;
                        } else {
                            if (!animationOnGoing) {
                                animation->SetAction(
                                    AlanAnimation::Transition::WALK,
                                    AlanAnimation::Direction::DOWN);
                                animationOnGoing = true;
                            }
                            if (interpol->AttPosition(Vec2(
                                    (associated.gridPosition.x) * gridSize -
                                        gridSize / 2,
                                    (associated.gridPosition.y + 1) * gridSize -
                                        gridSize / 2))) {
                                movementDirection = Direction::NONE;
                                associated.gridPosition.y++;
                                animationOnGoing = false;
                            }
                        }
                        // Verifica se a marmota está em posição de
                        // escalada
                    } else {
                        if (Game::GetInstance()->GetGridControl()->TestPath(
                                Vec2(associated.gridPosition.x + 1,
                                     associated.gridPosition.y + 1),
                                true) == GridControl::WhatsThere::FREE) {
                            movementDirection = Direction::NONE;
                        } else {
                            if (!animationOnGoing) {
                                animation->SetAction(
                                    AlanAnimation::Transition::WALK,
                                    AlanAnimation::Direction::DOWN);

                                animationOnGoing = true;
                            }
                            if (interpol->AttPosition(Vec2(
                                    (associated.gridPosition.x) * gridSize -
                                        gridSize / 2,
                                    (associated.gridPosition.y + 1) * gridSize -
                                        gridSize / 2))) {
                                movementDirection = Direction::NONE;
                                associated.gridPosition.y++;
                                animationOnGoing = false;
                            }
                        }
                    }
                } else {
                    if (!animationOnGoing) {
                        animation->SetAction(AlanAnimation::Transition::DIG_T,
                                             AlanAnimation::Direction::DOWN);
                        animationOnGoing = true;
                    }
                    if (sprite->FrameTimePassed()) {
                        tileMap->GetDamageGround(
                            1, Vec2(associated.gridPosition.x,
                                    associated.gridPosition.y + 1));
                        movementDirection = Direction::NONE;
                        animationOnGoing = false;
                    }
                }
            }
        } else if (movementDirection == Direction::LEFT) {
            if (action != Action::WALKIN) {
                action = Action::WALKIN;
            }
            // Testa se o valor do grid a esquerda é uma pedra
            if (Game::GetInstance()->GetGridControl()->TestPath(
                    Vec2(associated.gridPosition.x - 1,
                         associated.gridPosition.y),
                    true) == GridControl::WhatsThere::ROCK) {
                // Se for, entra em posição de escalada
                if (!animationOnGoing) {
                    action = Action::CLIMBING;
                    animation->SetAction(AlanAnimation::Transition::CLIMB,
                                         AlanAnimation::Direction::LEFT);
                    animationOnGoing = true;
                }
                if (sprite->FrameTimePassed()) {
                    movementDirection = Direction::NONE;
                    animationOnGoing = false;
                }

                return;
            } else {
                movementDirection = Direction::NONE;
            }
        } else if (movementDirection == Direction::RIGHT) {
            // Mesmo processo anterior para a direita
            if (Game::GetInstance()->GetGridControl()->TestPath(
                    Vec2(associated.gridPosition.x + 1,
                         associated.gridPosition.y),
                    true) == GridControl::WhatsThere::ROCK) {
                if (!animationOnGoing) {
                    action = Action::CLIMBING;
                    animation->SetAction(AlanAnimation::Transition::CLIMB,
                                         AlanAnimation::Direction::RIGHT);
                    animationOnGoing = true;
                }
                if (sprite->FrameTimePassed()) {
                    movementDirection = Direction::NONE;
                    animationOnGoing = false;
                }
                return;
            } else {
                movementDirection = Direction::NONE;
            }
        }
    } else {
        // Up bate na pedra acima dele se houver
        if (movementDirection == Direction::UP) {
            if (Game::GetInstance()->GetGridControl()->TestPath(
                    Vec2(associated.gridPosition.x,
                         associated.gridPosition.y - 1),
                    true) == GridControl::WhatsThere::ROCK) {
                if (!animationOnGoing) {
                    animation->SetAction(AlanAnimation::Transition::DIG_T,
                                         AlanAnimation::Direction::UP);
                    animationOnGoing = true;
                }
                if (sprite->FrameTimePassed()) {
                    tileMap->GetDamageGround(
                        1, Vec2(associated.gridPosition.x,
                                associated.gridPosition.y - 1));
                    movementDirection = Direction::NONE;
                    animationOnGoing = false;
                }

                return;
            } else {
                movementDirection = Direction::NONE;
            }
            // Down bate na pedra embaixo dele
        } else if (movementDirection == Direction::DOWN) {
            if (Game::GetInstance()->GetGridControl()->WillDestroyBlock()) {
                if (!animationOnGoing) {
                    animation->SetAction(AlanAnimation::Transition::DIG_T,
                                         AlanAnimation::Direction::DOWN);
                    animationOnGoing = true;
                }
                if (interpol->AttPosition(Vec2(
                        associated.gridPosition.x * gridSize - gridSize / 2,
                        (associated.gridPosition.y + 1) * gridSize -
                            gridSize / 2))) {
                    Vec2 damage = {associated.gridPosition.x,
                                   associated.gridPosition.y + 1};
                    tileMap->GetDamageGround(1, damage);
                    movementDirection = Direction::NONE;
                    associated.gridPosition.y++;
                    animationOnGoing = false;
                }
            } else {
                if (!animationOnGoing) {
                    animation->SetAction(AlanAnimation::Transition::DIG_T,
                                         AlanAnimation::Direction::DOWN);
                    animationOnGoing = true;
                }
                if (sprite->FrameTimePassed()) {
                    tileMap->GetDamageGround(
                        1, Vec2(associated.gridPosition.x,
                                associated.gridPosition.y + 1));
                    movementDirection = Direction::NONE;
                    animationOnGoing = false;
                }
            }

        } else if (movementDirection == Direction::LEFT) {
            // Testa se o valor do grid a esquerda é uma
            // pedra
            if (!IsFree()) {
                if (!animationOnGoing) {
                    animation->SetAction(AlanAnimation::Transition::DIG_T,
                                         AlanAnimation::Direction::LEFT);
                    animationOnGoing = true;
                }
                if (sprite->FrameTimePassed()) {
                    if (IsBlock()) {
                        tileMap->GetDamageGround(
                            1, Vec2(associated.gridPosition.x - 1,
                                    associated.gridPosition.y));
                    }
                    movementDirection = Direction::NONE;
                    animationOnGoing = false;
                }

                return;
            } else {
                if (!animationOnGoing) {
                    animation->SetAction(AlanAnimation::Transition::WALK,
                                         AlanAnimation::Direction::LEFT);
                    animationOnGoing = true;
                }

                if (interpol->AttPosition(
                        Vec2((associated.gridPosition.x - 1) * gridSize -
                                 gridSize / 2,
                             (associated.gridPosition.y) * gridSize -
                                 gridSize / 2))) {
                    movementDirection = Direction::NONE;
                    associated.gridPosition.x--;
                    animationOnGoing = false;
                }
                return;
            }

            movementDirection = Direction::NONE;

        } else {
            // Mesmo processo anterior para a direita
            if (!IsFree()) {
                if (!animationOnGoing) {
                    animation->SetAction(AlanAnimation::Transition::DIG_T,
                                         AlanAnimation::Direction::RIGHT);
                    animationOnGoing = true;
                }
                if (sprite->FrameTimePassed()) {
                    if (IsBlock()) {
                        tileMap->GetDamageGround(
                            1, Vec2(associated.gridPosition.x + 1,
                                    associated.gridPosition.y));
                    }
                    movementDirection = Direction::NONE;
                    animationOnGoing = false;
                }

                return;
            } else {
                if (!animationOnGoing) {
                    animation->SetAction(AlanAnimation::Transition::WALK,
                                         AlanAnimation::Direction::RIGHT);
                    animationOnGoing = true;
                }

                if (interpol->AttPosition(
                        Vec2((associated.gridPosition.x + 1) * gridSize -
                                 gridSize / 2,
                             (associated.gridPosition.y) * gridSize -
                                 gridSize / 2))) {
                    movementDirection = Direction::NONE;
                    associated.gridPosition.x++;
                    animationOnGoing = false;
                }
                return;
            }

            movementDirection = Direction::NONE;
        }
        if (animation->GetCurrentState() == AlanAnimation::State::IDLE) {
            animationOnGoing = false;
        }
    }
}
