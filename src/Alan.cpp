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

    if (input.ActionPress(input.DIG_UP)) {
        movementDirection = Direction::UP;
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
            // movementDirection = Direction::NONE;
            std::cout << "\n\nMiss: " << input.GetDeltaRhythm() << "\n\n";
            // Game::GetInstance()->combo = 0;
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
        std::cout << "AAAAAAAAAH" << std::endl;
        associated.gridPosition.y++;
        gridsLeft--;
    }
}

void Alan::Update(float dt) {
    if (maxPosition < std::max(associated.gridPosition.y + 4, 7.0)) {
        maxPosition = std::max(associated.gridPosition.y + 4, 7.0);
    }

    TileMap *tileMap = Game::GetInstance()->GetCurrentState().tileMap;
    Sprite *sprite = associated.GetComponent<Sprite *>();
    // Testa se a marmota deve "cair" ou ficar na posição atual
    if (gridsLeft ||
        (tileMap->At(associated.gridPosition.x,
                     associated.gridPosition.y + 1) == 2 &&
         action != Action::CLIMBING && movementDirection == Direction::NONE)) {
        if (gridsLeft == 0) {
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

    if (movementDirection == Direction::NONE) {
        if (action != Action::CLIMBING || !input.KeyDown(SDL_SCANCODE_A)) {
            action = Action::STANDIN;
        }

        return;
    }

    Interpol *interpol = associated.GetComponent<Interpol *>();
    AlanAnimation *animation = associated.GetComponent<AlanAnimation *>();

    animation->Update(dt);

    // 'A' apertado indica que o movimento é de escalada
    if (input.KeyDown(SDL_SCANCODE_A) &&
        (action != Action::WALKIN || (frameNumber == 0 || frameNumber == 1))) {
        if (movementDirection == Direction::UP) {
            // Verifica se a posição acima do grid é um espaço vazio e se a
            // marmota já está na posição de escalada
            if (tileMap->At(associated.gridPosition.x,
                            associated.gridPosition.y - 1) == 2 &&
                (frameNumber != 0 && frameNumber != 1)) {
                if (!sprite->FrameTimePassed()) {
                    if (frameNumber == 14 || frameNumber == 17) {
                        // Verifica se a escalada é a esquerda ou a direita
                        if (frameNumber == 14) {
                            // Se a posição acima e a esquerda for vazia a
                            // marmota "sobe" na pedra
                            if (tileMap->At(associated.gridPosition.x - 1,
                                            associated.gridPosition.y - 1) ==
                                2) {
                                frameNumber = 0;
                                sprite->SetFrame(frameNumber);
                                movementDirection = Direction::NONE;
                                associated.gridPosition.x--;
                                associated.gridPosition.y--;
                                return;
                            }
                        } else {
                            // Se a posição acima e a direita for vazia a
                            // marmota "sobe" na pedra
                            if (tileMap->At(associated.gridPosition.x + 1,
                                            associated.gridPosition.y - 1) ==
                                2) {
                                frameNumber = 0;
                                sprite->SetFrame(frameNumber);
                                movementDirection = Direction::NONE;
                                associated.gridPosition.x++;
                                associated.gridPosition.y--;
                                return;
                            }
                        }
                        // Senão ela escala meia posição

                        frameNumber--;
                        sprite->SetFrame(frameNumber);
                    } else {
                        // Escala a outra metade da posição e atualiza a
                        // associated.gridPosition

                        frameNumber++;
                        sprite->SetFrame(frameNumber);
                        movementDirection = Direction::NONE;
                        associated.gridPosition.y--;
                    }
                }
            }
            // Verifica se a marmota está em posição de escalada
            else if ((frameNumber != 0 && frameNumber != 1)) {
                if (!sprite->FrameTimePassed()) {
                    // Se estiver e a posição diretamente acima for uma pedra
                    // ela da o hit
                    if (frameNumber == 14 || frameNumber == 17) {
                        frameNumber--;
                        sprite->SetFrame(frameNumber);
                    } else {
                        frameNumber++;
                        Vec2 damage = {associated.gridPosition.x,
                                       associated.gridPosition.y - 1};
                        tileMap->GetDamageGround(1, damage);
                        movementDirection = Direction::NONE;
                        sprite->SetFrame(frameNumber);
                    }
                }
            } else {
                movementDirection = Direction::NONE;
            }

        } else if (movementDirection == Direction::DOWN) {
            // Mesmo processo anterior para a baixo (quando a pedra abaixo do
            // lado onde a marmota estiver escalando for vazia ela não faz nada)
            if (tileMap->At(associated.gridPosition.x,
                            associated.gridPosition.y + 1) == 2 &&
                (frameNumber != 0 && frameNumber != 1)) {
                if (!sprite->FrameTimePassed()) {
                    if (frameNumber == 6 || frameNumber == 8) {
                        if (frameNumber == 6) {
                            if (tileMap->At(associated.gridPosition.x - 1,
                                            associated.gridPosition.y + 1) ==
                                2) {
                                movementDirection = Direction::NONE;
                                return;
                            }

                        } else {
                            if (tileMap->At(associated.gridPosition.x + 1,
                                            associated.gridPosition.y + 1) ==
                                2) {
                                movementDirection = Direction::NONE;
                                return;
                            }
                        }

                        frameNumber++;
                        sprite->SetFrame(frameNumber);
                    } else {
                        frameNumber--;
                        sprite->SetFrame(frameNumber);
                        movementDirection = Direction::NONE;
                        associated.gridPosition.y++;
                    }
                }
            } else if ((frameNumber != 0 && frameNumber != 1)) {
                if (!sprite->FrameTimePassed()) {
                    if (frameNumber == 14 || frameNumber == 17) {
                        frameNumber++;
                        sprite->SetFrame(frameNumber);
                    } else {
                        frameNumber--;
                        Vec2 damage = {associated.gridPosition.x,
                                       associated.gridPosition.y + 1};
                        tileMap->GetDamageGround(1, damage);
                        movementDirection = Direction::NONE;
                        sprite->SetFrame(frameNumber);
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
                if (!sprite->FrameTimePassed()) {
                    if (frameNumber == 0) {
                        frameNumber = 14;
                        sprite->SetFrame(frameNumber);
                        action = Action::CLIMBING;
                    } else {
                        movementDirection = Direction::NONE;
                    }
                }
                return;
            } else {
                movementDirection = Direction::NONE;
            }

        } else {
            // Mesmo processo anterior para a direita
            if (tileMap->At(associated.gridPosition.x + 1,
                            associated.gridPosition.y) > 2) {
                if (!sprite->FrameTimePassed()) {
                    if (frameNumber == 0) {
                        frameNumber = 17;
                        sprite->SetFrame(frameNumber);
                        action = Action::CLIMBING;
                    } else {
                        movementDirection = Direction::NONE;
                    }
                }
                return;
            } else {
                movementDirection = Direction::NONE;
            }
        }
    } else {
        action = Action::WALKIN;
        // Up bate na pedra acima dele se houver
        if (movementDirection == Direction::UP) {
            if (tileMap->At(associated.gridPosition.x,
                            associated.gridPosition.y - 1) > 2) {
                animation->SetAction(AlanAnimation::Transition::DIG_T,
                                     AlanAnimation::Direction::N);
                Vec2 damage = {associated.gridPosition.x,
                               associated.gridPosition.y - 1};
                tileMap->GetDamageGround(1, damage);
                movementDirection = Direction::NONE;
                /*
                if (!sprite->FrameTimePassed()) {
                    if (frameNumber == 0 || frameNumber == 1) {
                        frameNumber = 15;
                        sprite->SetFrame(frameNumber);
                    } else if (frameNumber == 15) {
                        frameNumber = 0;
                        sprite->SetFrame(frameNumber);


                    }
                }
                */
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
                /*
                if (frameNumber == 0 || frameNumber == 1) {
                    frameNumber = 10;
                    sprite->SetFrame(frameNumber);
                } else if (frameNumber == 10) {
                    frameNumber = 11;
                    sprite->SetFrame(frameNumber);
                } else if (frameNumber == 11) {
                    frameNumber = 12;
                    sprite->SetFrame(frameNumber);
                } else {
                    frameNumber = 10;
                    sprite->SetFrame(frameNumber);
                }
                */
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
                Vec2 damage = {associated.gridPosition.x,
                               associated.gridPosition.y + 1};
                tileMap->GetDamageGround(1, damage);
                movementDirection = Direction::NONE;
                animation->SetAction(AlanAnimation::Transition::DIG_T,
                                     AlanAnimation::Direction::S);
            }

        } else if (movementDirection == Direction::LEFT) {
            // Testa se o valor do grid a esquerda é uma pedra
            if (tileMap->At(associated.gridPosition.x - 1,
                            associated.gridPosition.y) != 2) {
                if (!sprite->FrameTimePassed()) {
                    if (frameNumber == 0 || frameNumber == 1) {
                        frameNumber = 8;
                        sprite->SetFrame(frameNumber);
                    } else if (frameNumber == 8) {
                        frameNumber = 0;
                        sprite->SetFrame(frameNumber);
                        Vec2 damage = {associated.gridPosition.x - 1,
                                       associated.gridPosition.y};
                        tileMap->GetDamageGround(1, damage);
                        movementDirection = Direction::NONE;
                    }
                }
                return;
            }

            // Se não for pedra só anda
            animation->SetAction(AlanAnimation::Transition::WALK,
                                 AlanAnimation::Direction::W);
            /*
            if (tileMap->At(associated.gridPosition.x - 1,
                            associated.gridPosition.y + 1) == 2) {
                if (frameNumber == 0 || frameNumber == 1) {
                    frameNumber = 2;
                    sprite->SetFrame(frameNumber);
                } else if (frameNumber == 2) {
                    frameNumber = 3;
                    sprite->SetFrame(frameNumber);
                } else {
                    frameNumber = 2;
                    sprite->SetFrame(frameNumber);
                }

            } else {
                if (frameNumber == 0 || frameNumber == 1) {
                    frameNumber = 2;
                    sprite->SetFrame(frameNumber);
                } else if (frameNumber == 2) {
                    frameNumber = 3;
                    sprite->SetFrame(frameNumber);
                } else if (frameNumber == 3) {
                    frameNumber = 4;
                    sprite->SetFrame(frameNumber);
                } else {
                    frameNumber = 2;
                    sprite->SetFrame(frameNumber);
                }
            }
            */
            Vec2 newPos{
                (associated.gridPosition.x - 1) * gridSize - gridSize / 2,
                (associated.gridPosition.y) * gridSize - gridSize / 2};
            if (interpol->AttPosition(newPos)) {
                frameNumber = 0;
                sprite->SetFrame(frameNumber);
                movementDirection = Direction::NONE;
                associated.gridPosition.x--;
            }
        } else {
            // Mesmo processo anterior para a direita
            if (tileMap->At(associated.gridPosition.x + 1,
                            associated.gridPosition.y) != 2) {
                if (!sprite->FrameTimePassed()) {
                    if (frameNumber == 0 || frameNumber == 1) {
                        frameNumber = 9;
                        sprite->SetFrame(frameNumber);
                    } else if (frameNumber == 9) {
                        frameNumber = 0;
                        sprite->SetFrame(frameNumber);
                        Vec2 damage = {associated.gridPosition.x + 1,
                                       associated.gridPosition.y};
                        tileMap->GetDamageGround(1, damage);
                        movementDirection = Direction::NONE;
                    }
                }
                return;
            }

            // Se não for pedra só anda
            animation->SetAction(AlanAnimation::Transition::WALK,
                                 AlanAnimation::Direction::E);
            /*
            if (tileMap->At(associated.gridPosition.x + 1,
                            associated.gridPosition.y + 1) == 2) {
                if (frameNumber == 0 || frameNumber == 1) {
                    frameNumber = 5;
                    sprite->SetFrame(frameNumber);
                } else if (frameNumber == 5) {
                    frameNumber = 6;
                    sprite->SetFrame(frameNumber);
                } else {
                    frameNumber = 5;
                    sprite->SetFrame(frameNumber);
                }

            } else {
                if (frameNumber == 0 || frameNumber == 1) {
                    frameNumber = 5;
                    sprite->SetFrame(frameNumber);
                } else if (frameNumber == 5) {
                    frameNumber = 6;
                    sprite->SetFrame(frameNumber);
                } else if (frameNumber == 6) {
                    frameNumber = 7;
                    sprite->SetFrame(frameNumber);
                } else {
                    frameNumber = 5;
                    sprite->SetFrame(frameNumber);
                }
            }
            */
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
