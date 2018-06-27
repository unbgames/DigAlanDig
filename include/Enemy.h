#ifndef ENEMY_H
#define ENEMY_H
#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_TTF
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "Alan.h"
#include "Component.h"
#include "InputManager.h"
#include "Sprite.h"
#include "TileMap.h"
#include "Vec2.h"

class Enemy : public Component {
  public:
    enum Direction { LEFT = 0, RIGHT };
    enum State { NONE_S = 0, IDLE_S, WALKIN_S, HIT_S, DIE_S, STATE_MAX };

    Enemy(GameObject& associated, int enemyType = 1);

    ~Enemy() {}

    void Update(float dt);
    void RhythmUpdate() {
        numBeats++;

        if (!movimentAllowed && numBeats > 1) {
            movimentAllowed = true;
            numBeats = 0;
        }
    }
    void RhythmReset() {}
    void Render(Common::Layer layer) const {}

    void Fallin(float dt);

    Vec2 GetGridPosition() { return associated.GetGridPosition(); }

    Direction GetMovementDirection() { return movementDirection; }
    State GetState() { return state; }

    bool VerifyDeath(Alan* alan);

    void TakeDamage(int damage) { hp -= damage; }

  private:
    Direction movementDirection = Direction::LEFT;

    // 2<=range<=7
    int range, steps = 0;
    State state = State::IDLE_S;

    int numBeats = 0;

    int hp;

    Vec2 tileMapPos;

    Sprite::SpriteState EState[State::STATE_MAX];
    InputManager& input;
    bool movimentAllowed = false;
};

#endif  // ENEMY_H
