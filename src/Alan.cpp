#include "Alan.h"
#include "Game.h"
#include "Sprite.h"

Alan::Alan(GameObject &associated, Vec2 gridPosition, int gridSizeHeight,
           int gridSizeWidth)
    : Component(associated),
      gridSizeWidth(gridSizeWidth),
      gridSizeHeight(gridSizeHeight),
      gridPosition(gridPosition),
      input(InputManager::GetInstance()) {}

// Direção do movimento
void Alan::GetMovement() {
    if (input.KeyPress(SDL_SCANCODE_UP)) {
        movementDirection.push(Alan::UP);
    }
    if (input.KeyPress(SDL_SCANCODE_DOWN)) {
        movementDirection.push(Alan::DOWN);
    }
    if (input.KeyPress(SDL_SCANCODE_LEFT)) {
        movementDirection.push(Alan::LEFT);
    }
    if (input.KeyPress(SDL_SCANCODE_RIGHT)) {
        movementDirection.push(Alan::RIGHT);
    }
}

void Alan::Update(float dt) {
    TileMap *tileMap = Game::GetInstance()->GetCurrentState().tileMap;
    // Testa se a marmota deve "cair" ou ficar na posição atual
    if (tileMap->At(gridPosition.x, gridPosition.y + 1) == 2) {
        associated.box.y += gridSizeHeight;
        gridPosition.y++;
    }

    GetMovement();

    Sprite *sprite = associated.GetComponent<Sprite *>();

    if (movementDirection.empty()) {
        return;
    }

    // Up não faz nada
    if (movementDirection.front() == Alan::UP) {
        movementDirection.pop();
        // Down bate na pedra embaixo dele
    } else if (movementDirection.front() == Alan::DOWN) {
        if (frameNumber == 0) {
            frameNumber = 5;
            sprite->SetFrame(frameNumber);
        } else {
            frameNumber = 0;
            Vec2 damage = {gridPosition.x, gridPosition.y + 1};
            tileMap->GetDamageGround(1, damage);
            movementDirection.pop();
            sprite->SetFrame(frameNumber);
        }
    } else if (movementDirection.front() == Alan::LEFT) {
        // Testa se o valor do grid a esquerda é uma pedra
        if (tileMap->At(gridPosition.x - 1, gridPosition.y) != 2) {
            // Se for, da hit na pedra
            if (frameNumber == 0) {
                frameNumber = 3;
                sprite->SetFrame(frameNumber);
            } else {
                frameNumber = 0;
                // Testa se a possição do grid é "pedra" ou a lateral do jogo
                if (tileMap->At(gridPosition.x - 1, gridPosition.y) != 1) {
                    Vec2 damage = {gridPosition.x - 1, gridPosition.y};
                    tileMap->GetDamageGround(1, damage);
                }
                movementDirection.pop();
                sprite->SetFrame(frameNumber);
            }
            return;
        }

        // Se não for pedra só anda
        if (frameNumber == 0) {
            associated.box.x -= gridSizeWidth / 2;
            frameNumber = 2;
            sprite->SetFrame(frameNumber);
        } else if (frameNumber == 2) {
            associated.box.x -= gridSizeWidth / 2;
            frameNumber = 0;
            sprite->SetFrame(0);
            movementDirection.pop();
            gridPosition.x--;
        }
    } else {
        // Mesmo processo anterior para a direita
        if (tileMap->At(gridPosition.x + 1, gridPosition.y) != 2) {
            if (frameNumber == 0) {
                frameNumber = 4;
                sprite->SetFrame(frameNumber);
            } else {
                frameNumber = 0;
                if (tileMap->At(gridPosition.x + 1, gridPosition.y) != 1) {
                    Vec2 damage = {gridPosition.x + 1, gridPosition.y};
                    tileMap->GetDamageGround(1, damage);
                }
                movementDirection.pop();
                sprite->SetFrame(frameNumber);
            }
            return;
        }

        if (frameNumber == 0) {
            associated.box.x += gridSizeWidth / 2;
            frameNumber = 2;
            sprite->SetFrame(frameNumber);
        } else if (frameNumber == 2) {
            associated.box.x += gridSizeWidth / 2;
            frameNumber = 0;
            sprite->SetFrame(0);
            movementDirection.pop();
            gridPosition.x++;
        }
    }
}
