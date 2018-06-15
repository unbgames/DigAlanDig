#include "Alan.h"
#include <algorithm>
#include "Game.h"
#include "Interpol.h"
#include "Sprite.h"

Alan::Alan(GameObject &associated, int gridSize)
    : Component(associated),
      input(InputManager::GetInstance()),
      gridSize(gridSize) {}

// Direção do movimento
void Alan::GetMovement() {
    if (moved || movementDirection) return;
    //
    if (input.ActionPress(input.DIG_UP)) {
        movementDirection = Direction::UP;
        moved = true;
    }
    if (input.ActionPress(input.DIG_DOWN)) {
        movementDirection = Direction::DOWN;
        moved = true;
    }
    if (input.ActionPress(input.DIG_LEFT)) {
        movementDirection = Direction::LEFT;
        moved = true;
    }
    if (input.ActionPress(input.DIG_RIGHT)) {
        movementDirection = Direction::RIGHT;
        moved = true;
    }

    if (movementDirection) {
        float duty = 0.5;
        float dR = input.GetDeltaRhythm();
        dR = (dR > 0) ? dR : -dR;
        if (dR < duty) {
            movementDirection = Direction::NONE;
            std::cout << "\n\nMiss: " << input.GetDeltaRhythm() << "\n\n";
        } else {
            std::cout << "\n\nHit: " << input.GetDeltaRhythm() << "\n\n";
            Game::GetInstance()->combo++;
        }
    }
}

void Alan::Fallin(float dt) {
    Interpol *interpol = associated.GetComponent<Interpol *>();
    Vec2 newPos{associated.gridPosition.x * gridSize - gridSize / 2,
                (associated.gridPosition.y + 1) * gridSize - gridSize / 2};

    if (interpol->AttPosition(newPos) && gridsLeft == 0) {
        action = Action::STANDIN;
    }

    if (associated.box.y >=
        (associated.gridPosition.y + 1) * gridSize - gridSize / 2) {
        associated.gridPosition.y++;
        movementDirection = Direction::NONE;
        gridsLeft--;
    }
}

void Alan::Update(float dt) {
    AlanAnimation *animation = associated.GetComponent<AlanAnimation *>();

    if (maxPosition < std::max(associated.gridPosition.y + 4, 7.0)) {
        maxPosition = std::max(associated.gridPosition.y + 4, 7.0);
    }

    TileMap *tileMap = Game::GetInstance()->GetCurrentState().tileMap;
    Sprite *sprite = associated.GetComponent<Sprite *>();

    // Testa se a marmota deve "cair" ou ficar na posição atual
    if (gridsLeft ||
        ((tileMap->At(associated.gridPosition.x,
                      associated.gridPosition.y + 1) == 2 &&
          action != Action::CLIMBING && movementDirection == Direction::NONE) &&
         !input.KeyDown(SDL_SCANCODE_A))) {
        if (gridsLeft == 0) {
            movementDirection = Direction::DOWN;
            action = Action::FALLIN;
            int y = associated.gridPosition.y + 1;
            while (tileMap->At(associated.gridPosition.x, y) == 2) {
                gridsLeft++;
                y++;
            }
        }

        Fallin(dt);

        return;
    }

    GetMovement();

    if (animation->GetCurrentState() == AlanAnimation::State::FALLIN) {
        animation->SetAction(AlanAnimation::Transition::FLOOR,
                             AlanAnimation::Direction::W);
        action = Action::STANDIN;
        movementDirection = Direction::NONE;
    }

    if (movementDirection == Direction::NONE) {
        if (action != Action::CLIMBING || !input.KeyDown(SDL_SCANCODE_A)) {
            animation->SetAction(AlanAnimation::Transition::NONE_T,
                                 AlanAnimation::Direction::W);
            action = Action::STANDIN;
        }

        return;
    }

    Interpol *interpol = associated.GetComponent<Interpol *>();

    // 'A' apertado indica que o movimento é de escalada
    if (input.KeyDown(SDL_SCANCODE_A) && action != Action::WALKIN) {
        if (movementDirection == Direction::UP) {
            // Verifica se a posição acima do grid é um espaço vazio e se a
            // marmota já está na posição de escalada
            if ((animation->GetCurrentState() ==
                     AlanAnimation::State::CLIMBIN ||
                 animation->GetOldState() == AlanAnimation::State::CLIMBIN) &&
                animation->GetCurrentState() != AlanAnimation::State::IDLE) {
                if (tileMap->At(associated.gridPosition.x,
                                associated.gridPosition.y - 1) == 2) {
                    if ((animation->GetCurrentDirection() ==
                             AlanAnimation::Direction::W ||
                         animation->GetOldDirection() ==
                             AlanAnimation::Direction::W) &&
                        animation->GetCurrentDirection() !=
                            AlanAnimation::Direction::E) {
                        if (tileMap->At(associated.gridPosition.x - 1,
                                        associated.gridPosition.y - 1) == 2) {
                            Vec2 newPos{
                                (associated.gridPosition.x - 1) * gridSize -
                                    gridSize / 2,
                                (associated.gridPosition.y - 1) * gridSize -
                                    gridSize / 2};
                            if (interpol->AttPosition(newPos)) {
                                movementDirection = Direction::NONE;
                                associated.gridPosition.y--;
                                associated.gridPosition.x--;
                                animation->SetAction(
                                    AlanAnimation::Transition::NONE_T,
                                    AlanAnimation::Direction::W);
                            }
                        } else {
                            if (!animationOnGoing) {
                                animation->SetAction(
                                    AlanAnimation::Transition::WALK,
                                    AlanAnimation::Direction::N);
                                animationOnGoing = true;
                            }
                            Vec2 newPos{
                                (associated.gridPosition.x) * gridSize -
                                    gridSize / 2,
                                (associated.gridPosition.y - 1) * gridSize -
                                    gridSize / 2};
                            if (interpol->AttPosition(newPos)) {
                                movementDirection = Direction::NONE;
                                associated.gridPosition.y--;
                                animationOnGoing = false;
                            }
                        }
                        // Verifica se a marmota está em posição de escalada
                    } else {
                        if (tileMap->At(associated.gridPosition.x + 1,
                                        associated.gridPosition.y - 1) == 2) {
                            Vec2 newPos{
                                (associated.gridPosition.x + 1) * gridSize -
                                    gridSize / 2,
                                (associated.gridPosition.y - 1) * gridSize -
                                    gridSize / 2};
                            if (interpol->AttPosition(newPos)) {
                                movementDirection = Direction::NONE;
                                associated.gridPosition.y--;
                                associated.gridPosition.x++;
                                animation->SetAction(
                                    AlanAnimation::Transition::NONE_T,
                                    AlanAnimation::Direction::E);
                            }
                        } else {
                            if (!animationOnGoing) {
                                animation->SetAction(
                                    AlanAnimation::Transition::WALK,
                                    AlanAnimation::Direction::N);
                                animationOnGoing = true;
                            }
                            Vec2 newPos{
                                (associated.gridPosition.x) * gridSize -
                                    gridSize / 2,
                                (associated.gridPosition.y - 1) * gridSize -
                                    gridSize / 2};
                            if (interpol->AttPosition(newPos)) {
                                movementDirection = Direction::NONE;
                                associated.gridPosition.y--;
                                animationOnGoing = false;
                            }
                        }
                    }
                } else {
                    if (!animationOnGoing) {
                        animation->SetAction(AlanAnimation::Transition::DIG_T,
                                             AlanAnimation::Direction::N);
                        animationOnGoing = true;
                    }
                    if (sprite->FrameTimePassed()) {
                        Vec2 damage = {associated.gridPosition.x,
                                       associated.gridPosition.y - 1};
                        tileMap->GetDamageGround(1, damage);
                        movementDirection = Direction::NONE;
                        animationOnGoing = false;
                    }
                }

            } else {
                movementDirection = Direction::NONE;
            }
        } else if (movementDirection == Direction::DOWN) {
            // Mesmo processo anterior para a baixo (quando a pedra abaixo
            // do lado onde a marmota estiver escalando for vazia ela não
            // faz nada)
            if ((animation->GetCurrentState() ==
                     AlanAnimation::State::CLIMBIN ||
                 animation->GetOldState() == AlanAnimation::State::CLIMBIN) &&
                animation->GetCurrentState() != AlanAnimation::State::IDLE) {
                if (tileMap->At(associated.gridPosition.x,
                                associated.gridPosition.y + 1) == 2) {
                    if ((animation->GetCurrentDirection() ==
                             AlanAnimation::Direction::W ||
                         animation->GetOldDirection() ==
                             AlanAnimation::Direction::W) &&
                        animation->GetCurrentDirection() !=
                            AlanAnimation::Direction::E) {
                        if (tileMap->At(associated.gridPosition.x - 1,
                                        associated.gridPosition.y + 1) == 2) {
                            movementDirection = Direction::NONE;
                        } else {
                            if (!animationOnGoing) {
                                animation->SetAction(
                                    AlanAnimation::Transition::WALK,
                                    AlanAnimation::Direction::S);
                                animationOnGoing = true;
                            }
                            Vec2 newPos{
                                (associated.gridPosition.x) * gridSize -
                                    gridSize / 2,
                                (associated.gridPosition.y + 1) * gridSize -
                                    gridSize / 2};
                            if (interpol->AttPosition(newPos)) {
                                movementDirection = Direction::NONE;
                                associated.gridPosition.y++;
                                animationOnGoing = false;
                            }
                        }
                        // Verifica se a marmota está em posição de escalada
                    } else {
                        if (tileMap->At(associated.gridPosition.x + 1,
                                        associated.gridPosition.y + 1) == 2) {
                            movementDirection = Direction::NONE;
                        } else {
                            if (!animationOnGoing) {
                                animation->SetAction(
                                    AlanAnimation::Transition::WALK,
                                    AlanAnimation::Direction::S);

                                animationOnGoing = true;
                            }
                            Vec2 newPos{
                                (associated.gridPosition.x) * gridSize -
                                    gridSize / 2,
                                (associated.gridPosition.y + 1) * gridSize -
                                    gridSize / 2};
                            if (interpol->AttPosition(newPos)) {
                                movementDirection = Direction::NONE;
                                associated.gridPosition.y++;
                                animationOnGoing = false;
                            }
                        }
                    }
                } else {
                    if (!animationOnGoing) {
                        animation->SetAction(AlanAnimation::Transition::DIG_T,
                                             AlanAnimation::Direction::S);
                        animationOnGoing = true;
                    }
                    if (sprite->FrameTimePassed()) {
                        Vec2 damage = {associated.gridPosition.x,
                                       associated.gridPosition.y + 1};
                        tileMap->GetDamageGround(1, damage);
                        movementDirection = Direction::NONE;
                        animationOnGoing = false;
                    }
                }

            } else {
                movementDirection = Direction::NONE;
            }
        } else if (movementDirection == Direction::LEFT) {
            // Testa se o valor do grid a esquerda é uma pedra
            if (tileMap->At(associated.gridPosition.x - 1,
                            associated.gridPosition.y) > 2) {
                // Se for, entra em posição de escalada
                if (!animationOnGoing) {
                    action = Action::CLIMBING;
                    animation->SetAction(AlanAnimation::Transition::CLIMB,
                                         AlanAnimation::Direction::W);
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
        } else {
            // Mesmo processo anterior para a direita
            if (tileMap->At(associated.gridPosition.x + 1,
                            associated.gridPosition.y) > 2) {
                if (!animationOnGoing) {
                    action = Action::CLIMBING;
                    animation->SetAction(AlanAnimation::Transition::CLIMB,
                                         AlanAnimation::Direction::E);
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
        animation->SetAction(AlanAnimation::Transition::STOP_CLIMB,
                             animation->GetOldDirection());
        action = Action::WALKIN;
        // Up bate na pedra acima dele se houver
        if (movementDirection == Direction::UP) {
            if (tileMap->At(associated.gridPosition.x,
                            associated.gridPosition.y - 1) > 2) {
                if (!animationOnGoing) {
                    animation->SetAction(AlanAnimation::Transition::DIG_T,
                                         AlanAnimation::Direction::N);
                    animationOnGoing = true;
                }
                if (sprite->FrameTimePassed()) {
                    Vec2 damage = {associated.gridPosition.x,
                                   associated.gridPosition.y - 1};
                    tileMap->GetDamageGround(1, damage);
                    movementDirection = Direction::NONE;
                    animationOnGoing = false;
                }

                return;
            } else {
                movementDirection = Direction::NONE;
            }
            // Down bate na pedra embaixo dele
        } else if (movementDirection == Direction::DOWN) {
            if (tileMap->At(associated.gridPosition.x,
                            associated.gridPosition.y + 1) -
                    2 ==
                1) {
                animation->SetAction(AlanAnimation::Transition::DIG_T,
                                     AlanAnimation::Direction::S);

                Vec2 newPos{
                    associated.gridPosition.x * gridSize - gridSize / 2,
                    (associated.gridPosition.y + 1) * gridSize - gridSize / 2};
                if (interpol->AttPosition(newPos)) {
                    Vec2 damage = {associated.gridPosition.x,
                                   associated.gridPosition.y + 1};
                    tileMap->GetDamageGround(1, damage);
                    movementDirection = Direction::NONE;
                    associated.gridPosition.y++;
                }
            } else {
                if (!animationOnGoing) {
                    animation->SetAction(AlanAnimation::Transition::DIG_T,
                                         AlanAnimation::Direction::S);
                    animationOnGoing = true;
                }
                if (sprite->FrameTimePassed()) {
                    Vec2 damage = {associated.gridPosition.x,
                                   associated.gridPosition.y + 1};
                    tileMap->GetDamageGround(1, damage);
                    movementDirection = Direction::NONE;
                    animationOnGoing = false;
                }
            }

        } else if (movementDirection == Direction::LEFT) {
            // Testa se o valor do grid a esquerda é uma
            // pedra
            if (tileMap->At(associated.gridPosition.x - 1,
                            associated.gridPosition.y) != 2) {
                if (!animationOnGoing) {
                    animation->SetAction(AlanAnimation::Transition::DIG_T,
                                         AlanAnimation::Direction::W);
                    animationOnGoing = true;
                }
                if (sprite->FrameTimePassed()) {
                    Vec2 damage = {associated.gridPosition.x - 1,
                                   associated.gridPosition.y};
                    tileMap->GetDamageGround(1, damage);
                    movementDirection = Direction::NONE;
                    animationOnGoing = false;
                }

                return;
            }

            // Se não for pedra só anda
            animation->SetAction(AlanAnimation::Transition::WALK,
                                 AlanAnimation::Direction::W);

            Vec2 newPos{
                (associated.gridPosition.x - 1) * gridSize - gridSize / 2,
                (associated.gridPosition.y) * gridSize - gridSize / 2};
            if (interpol->AttPosition(newPos)) {
                movementDirection = Direction::NONE;
                associated.gridPosition.x--;
            }
        } else {
            // Mesmo processo anterior para a direita
            if (tileMap->At(associated.gridPosition.x + 1,
                            associated.gridPosition.y) != 2) {
                if (!animationOnGoing) {
                    animation->SetAction(AlanAnimation::Transition::DIG_T,
                                         AlanAnimation::Direction::E);
                    animationOnGoing = true;
                }
                if (sprite->FrameTimePassed()) {
                    Vec2 damage = {associated.gridPosition.x + 1,
                                   associated.gridPosition.y};
                    tileMap->GetDamageGround(1, damage);
                    movementDirection = Direction::NONE;
                    animationOnGoing = false;
                }

                return;
            }

            // Se não for pedra só anda
            animation->SetAction(AlanAnimation::Transition::WALK,
                                 AlanAnimation::Direction::E);
            Vec2 newPos{
                (associated.gridPosition.x + 1) * gridSize - gridSize / 2,
                (associated.gridPosition.y) * gridSize - gridSize / 2};
            if (interpol->AttPosition(newPos)) {
                movementDirection = Direction::NONE;
                associated.gridPosition.x++;
            }
        }
    }
}
