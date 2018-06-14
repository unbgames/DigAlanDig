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
#include "Game.h"
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
        DIG_T
    };

    enum Direction { E, W, N, S };

    AlanAnimation(GameObject &associated);

    ~AlanAnimation();

    void Update(float dt);
    void RhythmUpdate() {}
    void Render(Common::Layer layer) const {}
    void Start() {
        currentState = State::IDLE;
        oldState = currentState;
        direction = N;
    }

    void SetAction(Transition trans, Direction dir);

    int GetCurrentState() { return currentState; }

  private:
    enum State {
        NONE_S = 0,
        IDLE,
        WALKIN,
        FALLIN,
        DIG,
        HIT,
        CLIMBIN,
        WALKIN_CLIMB,
        DIG_CLIMB,
        DANCIN,
        DEAD,
        STATE_MAX
    };

    State oldState, currentState;
    Direction direction;
    Sprite::SpriteState AState[State::STATE_MAX];
};

#endif  // ALANANIMATION_H