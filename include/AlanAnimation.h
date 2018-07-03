#ifndef ALANANIMATION_H
#define ALANANIMATION_H
#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_TTF
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "Component.h"
#include "InputManager.h"
#include "Sprite.h"
#include "TileMap.h"
#include "Vec2.h"

class AlanAnimation : public Component {
  public:
    enum Transition {
        NONE_T,
        WALK,
        HIT_T,
        CLIMB,
        STOP_CLIMB,
        FLOOR,
        FALL,
        DIG_T,
        DANCE,
        DIE
    };

    enum Direction { W = 0, E, N, S };

    enum State {
        NONE_S = 0,
        IDLE,
        WALKIN,
        FALLIN,
        DIG,
        HIT,
        CLIMBIN,
        DIG_CLIMB,
        DANCIN,
        DEAD,
        STATE_MAX
    };

    explicit AlanAnimation(GameObject &associated);

    ~AlanAnimation();

    void Update(float dt);
    void RhythmUpdate() {}
    void Render(Common::Layer layer) const {}
    void Start() {
        currentState = State::IDLE;
        oldState = currentState;
        currentDirection = N;
        oldDirection = currentDirection;
    }

    void SetAction(Transition trans, Direction dir);

    Direction GetCurrentDirection() { return currentDirection; }
    Direction GetOldDirection() { return oldDirection; }

    State GetCurrentState() { return currentState; }
    State GetOldState() { return oldState; }

  private:
    State oldState = NONE_S, currentState = NONE_S;
    Direction oldDirection = W, currentDirection = W;
    Sprite::SpriteState AState[State::STATE_MAX];

    void PlaySound(Transition trans);
};

#endif  // ALANANIMATION_H
