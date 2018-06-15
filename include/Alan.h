#ifndef ALAN_H
#define ALAN_H
#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_TTF
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include <iostream>
#include <queue>
#include <string>
#include "AlanAnimation.h"
#include "Component.h"
#include "Game.h"
#include "InputManager.h"
#include "Sprite.h"
#include "TileMap.h"
#include "Vec2.h"

class Alan : public Component {
  public:
    enum Direction { NONE = 0, UP, DOWN, LEFT, RIGHT };
    enum Action { STANDIN = 0, WALKIN, CLIMBING, FALLIN };

    Alan(GameObject& associated, int gridSize);

    ~Alan() {}

    void GetMovement();

    void Update(float dt);
    void RhythmUpdate() {}
    void RhythmReset() {
        static int missCounter = 0;
        if (!moved)
            missCounter++;
        else
            missCounter = 0;

        if (missCounter > 1) Game::GetInstance()->combo /= 2;

        moved = false;
    }
    void Render(Common::Layer layer) const {}

    int GetMaxPosition() const { return maxPosition; }

    void Fallin(float dt);

    Vec2 GetGridPosition() { return associated.GetGridPosition(); }

    Direction GetMovementDirection() { return movementDirection; }

  private:
    Direction movementDirection = Direction::NONE;
    Action action = Action::STANDIN;

    int maxPosition = 0;
    int frameNumber = 0;
    int gridsLeft = 0;

    InputManager& input;

    int gridSize;

    bool moved = false;
    bool animationOnGoing = false;
};

#endif  // ALAN_H
