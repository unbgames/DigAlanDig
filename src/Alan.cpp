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
    if (moved || movementDirection) return;

    if (input.KeyPress(SDL_SCANCODE_UP)) {
        movementDirection = Direction::UP;
    }
    if (input.KeyPress(SDL_SCANCODE_DOWN)) {
        movementDirection = Direction::DOWN;
        moved = true;
    }
    if (input.KeyPress(SDL_SCANCODE_LEFT)) {
        movementDirection = Direction::LEFT;
        moved = true;
    }
    if (input.KeyPress(SDL_SCANCODE_RIGHT)) {
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
            Game::GetInstance()->combo = 0;
        } else {
            std::cout << "\n\nHit: " << input.GetDeltaRhythm() << "\n\n";
            Game::GetInstance()->combo++;
        }
    }
}

void Alan::Update(float dt) {
    TileMap *tileMap = Game::GetInstance()->GetCurrentState().tileMap;
    Sprite *sprite = associated.GetComponent<Sprite *>();
    // Testa se a marmota deve "cair" ou ficar na posição atual
    if (tileMap->At(gridPosition.x, gridPosition.y + 1) == 2 && !input.IsKeyDown(SDL_SCANCODE_A)) {
        frameNumber = 0;
        sprite->SetFrame(frameNumber);
        associated.box.y += gridSizeHeight;
        gridPosition.y++;
    }

    GetMovement();

    if (movementDirection == Direction::NONE) {
        if(!input.IsKeyDown(SDL_SCANCODE_A) && (frameNumber == 0 || frameNumber == 1)){
            frameNumber = 0;
            sprite->SetFrame(frameNumber);
        }
        return;
    }

    // 'A' apertado indica que o movimento é de escalada 
    if(input.IsKeyDown(SDL_SCANCODE_A)){
        if (movementDirection == Direction::UP) {
            // Verifica se a posição acima do grid é um espaço vazio e se a marmota já está na posição de escalada
            if(tileMap->At(gridPosition.x, gridPosition.y - 1) == 2 && frameNumber != 0){
                if (!sprite->FrameTimePassed()){
                    if(frameNumber == 14 || frameNumber == 17){
                        // Verifica se a escalada é a esquerda ou a direita
                        if(frameNumber == 14){
                            // Se a posição acima e a esquerda for vazia a marmota "sobe" na pedra
                            if(tileMap->At(gridPosition.x - 1, gridPosition.y - 1) == 2){
                                associated.box.y -= gridSizeHeight;
                                associated.box.x -= gridSizeWidth;
                                frameNumber = 0;
                                sprite->SetFrame(frameNumber);
                                movementDirection = Direction::NONE;
                                gridPosition.x--;
                                gridPosition.y--;
                                return;
                            }                             
                        }else{
                            // Se a posição acima e a direita for vazia a marmota "sobe" na pedra
                            if(tileMap->At(gridPosition.x + 1, gridPosition.y - 1) == 2){
                                associated.box.y -= gridSizeHeight;
                                associated.box.x += gridSizeWidth;
                                frameNumber = 0;
                                sprite->SetFrame(frameNumber);
                                movementDirection = Direction::NONE;
                                gridPosition.x++;
                                gridPosition.y--;
                                return;
                            }
                        }
                        // Senão ela escala meia posição
                        associated.box.y -= gridSizeHeight / 2;
                        frameNumber--;
                        sprite->SetFrame(frameNumber);
                    }
                    else{
                        // Escala a outra metade da posição e atualiza a gridPosition 
                        associated.box.y -= gridSizeHeight / 2;
                        frameNumber++;
                        sprite->SetFrame(frameNumber);
                        movementDirection = Direction::NONE;
                        gridPosition.y--;
                        }
                }
            }
            // Verifica se a marmota está em posição de escalada 
            else if(frameNumber != 0){
                if (!sprite->FrameTimePassed()){
                    // Se estiver e a posição diretamente acima for uma pedra ela da o hit
                    if (frameNumber == 14 || frameNumber == 17) {
                        frameNumber--;
                        sprite->SetFrame(frameNumber);
                    } else {
                        frameNumber++;
                        Vec2 damage = {gridPosition.x, gridPosition.y - 1};
                        tileMap->GetDamageGround(1, damage);
                        movementDirection = Direction::NONE;
                        sprite->SetFrame(frameNumber);
                    }
                }
            }
        
        } else if (movementDirection == Direction::DOWN) {
            // Mesmo processo anterior para a baixo (quando a pedra abaixo do lado onde a marmota estiver escalando for vazia ela não faz nada)
            if(tileMap->At(gridPosition.x, gridPosition.y + 1) == 2 && frameNumber != 0){
                if (!sprite->FrameTimePassed()){
                    if(frameNumber == 6 || frameNumber == 8){
                        if(frameNumber == 6){
                            if(tileMap->At(gridPosition.x - 1, gridPosition.y + 1) == 2){
                                movementDirection = Direction::NONE;
                                return;
                            }
                                
                        }else{
                            if(tileMap->At(gridPosition.x + 1, gridPosition.y + 1) == 2){
                                movementDirection = Direction::NONE;
                                return;
                            }
                        }
                        associated.box.y += gridSizeHeight / 2;
                        frameNumber++;
                        sprite->SetFrame(frameNumber);
                    }else{
                        associated.box.y += gridSizeHeight / 2;
                        frameNumber--;
                        sprite->SetFrame(frameNumber);
                        movementDirection = Direction::NONE;
                        gridPosition.y++;
                    }
                }
            }else if(frameNumber != 0){
                if (!sprite->FrameTimePassed()){
                    if (frameNumber == 14 || frameNumber == 17) {
                        frameNumber++;
                        sprite->SetFrame(frameNumber);
                    } else {
                        frameNumber--;
                        Vec2 damage = {gridPosition.x, gridPosition.y + 1};
                        tileMap->GetDamageGround(1, damage);
                        movementDirection = Direction::NONE;
                        sprite->SetFrame(frameNumber);
                    }
                }
            }
        } else if (movementDirection == Direction::LEFT) {
            // Testa se o valor do grid a esquerda é uma pedra
            if (tileMap->At(gridPosition.x - 1, gridPosition.y) > 2) {
                // Se for, entra em posição de escalada
                if (!sprite->FrameTimePassed()){
                    if (frameNumber == 0) {
                        frameNumber = 14;
                        sprite->SetFrame(frameNumber);
                    } else{
                        movementDirection = Direction::NONE;
                    }
                }
                return;
            }

        } else {
            // Mesmo processo anterior para a direita
            if (tileMap->At(gridPosition.x + 1, gridPosition.y) > 2) {
                if (!sprite->FrameTimePassed()){
                    if (frameNumber == 0) {
                        frameNumber = 17;
                        sprite->SetFrame(frameNumber);
                    } else{
                        movementDirection = Direction::NONE;
                    }
                }
                return;
            }
        }
    }else{
        // Up bate na pedra acima dele se houver
        if (movementDirection == Direction::UP) {
            if(tileMap->At(gridPosition.x, gridPosition.y - 1) > 2){   
                if (!sprite->FrameTimePassed()) {
                    if (frameNumber == 0 || frameNumber == 1) {
                        frameNumber = 15;
                        sprite->SetFrame(frameNumber);
                    } else if (frameNumber == 15) {
                        frameNumber = 0;
                        sprite->SetFrame(frameNumber);
                        Vec2 damage = {gridPosition.x, gridPosition.y - 1};
                        tileMap->GetDamageGround(1, damage);
                        movementDirection = Direction::NONE;    
                    }
                }
                return;
            }else{
                movementDirection = Direction::NONE;
            }
        // Down bate na pedra embaixo dele
        } else if (movementDirection == Direction::DOWN) {
            if (!sprite->FrameTimePassed()) {
                if (tileMap->At(gridPosition.x, gridPosition.y + 1) - 2 == 1) {
                    if (frameNumber == 0 || frameNumber == 1) {
                        frameNumber = 10;
                        sprite->SetFrame(frameNumber);
                        associated.box.y += gridSizeHeight / 3;
                    } else if (frameNumber == 10) {
                        frameNumber = 11;
                        sprite->SetFrame(frameNumber);
                        associated.box.y += gridSizeHeight / 3;
                    } else if (frameNumber == 11) {
                        frameNumber = 12;
                        sprite->SetFrame(frameNumber);
                        associated.box.y =
                            (gridPosition.y + 1) * gridSizeHeight;
                    } else {
                        frameNumber = 0;
                        sprite->SetFrame(frameNumber);
                        Vec2 damage = {gridPosition.x, gridPosition.y + 1};
                        tileMap->GetDamageGround(1, damage);
                        movementDirection = Direction::NONE;
                        gridPosition.y++;
                    }
                } else {
                    if (frameNumber == 0 || frameNumber == 1) {
                        frameNumber = 10;
                        sprite->SetFrame(frameNumber);
                        associated.box.y += gridSizeHeight / 3;
                    } else if (frameNumber == 10) {
                        frameNumber = 11;
                        sprite->SetFrame(frameNumber);
                    } else if (frameNumber == 11) {
                        frameNumber = 12;
                        sprite->SetFrame(frameNumber);
                    } else {
                        frameNumber = 0;
                        sprite->SetFrame(frameNumber);
                        Vec2 damage = {gridPosition.x, gridPosition.y + 1};
                        tileMap->GetDamageGround(1, damage);
                        associated.box.y = (gridPosition.y) * gridSizeHeight;
                        movementDirection = Direction::NONE;
                    }
                }
            }
        } else if (movementDirection == Direction::LEFT) {
            // Testa se o valor do grid a esquerda é uma pedra
            if (tileMap->At(gridPosition.x - 1, gridPosition.y) != 2) {
                if (!sprite->FrameTimePassed()) {
                    if (frameNumber == 0 || frameNumber == 1) {
                        frameNumber = 8;
                        sprite->SetFrame(frameNumber);
                    } else if (frameNumber == 8) {
                        frameNumber = 0;
                        sprite->SetFrame(frameNumber);
                        Vec2 damage = {gridPosition.x - 1, gridPosition.y};
                        tileMap->GetDamageGround(1, damage);
                        movementDirection = Direction::NONE;    
                    }
                }
                return;
            }

            // Se não for pedra só anda
            if(tileMap->At(gridPosition.x - 1, gridPosition.y + 1) == 2){
                if (!sprite->FrameTimePassed()){
                    if (frameNumber == 0 || frameNumber == 1) {
                        frameNumber = 2;
                        sprite->SetFrame(frameNumber);
                        associated.box.x -= gridSizeWidth / 3;
                    } else if (frameNumber == 2) {
                        frameNumber = 3;
                        sprite->SetFrame(frameNumber);
                        associated.box.x -= gridSizeWidth / 3;
                    } else {
                        frameNumber = 0;
                        sprite->SetFrame(frameNumber);
                        associated.box.x = (gridPosition.x - 1) * gridSizeWidth;
                        movementDirection = Direction::NONE;
                        gridPosition.x--;
                    }
                }
            }else{
                if (!sprite->FrameTimePassed()) {
                    if (frameNumber == 0 || frameNumber == 1) {
                        frameNumber = 2;
                        sprite->SetFrame(frameNumber);
                        associated.box.x -= gridSizeWidth / 3;
                    } else if (frameNumber == 2) {
                        frameNumber = 3;
                        sprite->SetFrame(frameNumber);
                        associated.box.x -= gridSizeWidth / 3;
                    } else if (frameNumber == 3) {
                        frameNumber = 4;
                        sprite->SetFrame(frameNumber);
                        associated.box.x = (gridPosition.x - 1) * gridSizeWidth;
                    } else {
                        frameNumber = 0;
                        sprite->SetFrame(frameNumber);
                        movementDirection = Direction::NONE;
                        gridPosition.x--;
                    }
                }
            }
        } else {
            // Mesmo processo anterior para a direita
            if (tileMap->At(gridPosition.x + 1, gridPosition.y) != 2) {
                if (!sprite->FrameTimePassed()) {
                    if (frameNumber == 0 || frameNumber == 1) {
                        frameNumber = 9;
                        sprite->SetFrame(frameNumber);
                    } else if (frameNumber == 9) {
                        frameNumber = 0;
                        sprite->SetFrame(frameNumber);
                        Vec2 damage = {gridPosition.x + 1, gridPosition.y};
                        tileMap->GetDamageGround(1, damage);
                        movementDirection = Direction::NONE;    
                    }
                }
                return;
            }

            // Se não for pedra só anda
            if(tileMap->At(gridPosition.x + 1, gridPosition.y + 1) == 2){
                if (!sprite->FrameTimePassed()) {    
                    if (frameNumber == 0 || frameNumber == 1) {
                        frameNumber = 5;
                        sprite->SetFrame(frameNumber);
                        associated.box.x += gridSizeWidth / 3;
                    } else if (frameNumber == 5) {
                        frameNumber = 6;
                        sprite->SetFrame(frameNumber);
                        associated.box.x += gridSizeWidth / 3;
                    } else {
                        frameNumber = 0;
                        sprite->SetFrame(frameNumber);
                        associated.box.x = (gridPosition.x + 1) * gridSizeWidth;
                        movementDirection = Direction::NONE;
                        gridPosition.x++;
                    }
                }
            }else{
                if (!sprite->FrameTimePassed()) {
                    
                    if (frameNumber == 0 || frameNumber == 1) {
                        frameNumber = 5;
                        sprite->SetFrame(frameNumber);
                        associated.box.x += gridSizeWidth / 3;
                    } else if (frameNumber == 5) {
                        frameNumber = 6;
                        sprite->SetFrame(frameNumber);
                        associated.box.x += gridSizeWidth / 3;
                    } else if (frameNumber == 6) {
                        frameNumber = 7;
                        sprite->SetFrame(frameNumber);
                        associated.box.x = (gridPosition.x + 1) * gridSizeWidth;
                    } else {
                        frameNumber = 0;
                        sprite->SetFrame(frameNumber);
                        movementDirection = Direction::NONE;
                        gridPosition.x++;
                    }
                }
            }
            
        } 
    }

       
}
