#ifndef ALAN_H
#define ALAN_H
#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_TTF
#define INCLUDE_SDL_MIXER
#include <iostream>
#include <queue>
#include <string>
#include "Component.h"
#include "Sprite.h"
#include "Game.h"
#include "InputManager.h"
#include "SDL_include.h"
#include "TileMap.h"
#include "Vec2.h"

class Alan : public Component {
  public:
    Alan(GameObject& associated, Vec2 gridPosition, int gridSizeHeight,
         int gridSizeWidth);

    ~Alan() {}

    void GetMovement();

    void Update(float dt);
    void RhythmUpdate() {
        if(movementDirection == Direction::NONE){
            Sprite *sprite = associated.GetComponent<Sprite *>();
            if(frameNumber == 0){
                frameNumber = 1;
                sprite->SetFrame(frameNumber);
            }else{
                frameNumber = 0;
                sprite->SetFrame(frameNumber);
            }
        }
    }
    void RhythmReset() {
        if (!moved) {
            Game::GetInstance()->combo /= 2;
        }

        moved = false;
    }
    void Render() const {}
    bool Is(const std::string& type) const { return !type.compare("Alan"); }

    Vec2 GetGridPosition() const { return gridPosition; }

  private:
    enum Direction { NONE = 0, UP, DOWN, LEFT, RIGHT };
    int gridSizeWidth;
    int gridSizeHeight;
    Direction movementDirection = Direction::NONE;

    Vec2 gridPosition;
    int frameNumber = 0;
    int countTimeStanding = 0;

    InputManager& input;

    bool moved = false;
};

#endif  // ALAN_H
