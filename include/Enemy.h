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
#include "Component.h"
#include "InputManager.h"
#include "Sprite.h"
#include "TileMap.h"
#include "Vec2.h"

class Enemy : public Component {
  public:
    enum Direction { LEFT = 0, RIGHT };
    enum State { NONE_S = 0, IDLE_S, WALKIN_S, HIT_S, DIE_S, STATE_MAX };

    Enemy(GameObject& associated, int enemyType, int range = 2);

    ~Enemy() {}

    void Update(float dt);
    void RhythmUpdate() {
        if (!movimentAllowed) movimentAllowed = true;
    }
    void RhythmReset() {}
    void Render(Common::Layer layer) const {}

    void Fallin(float dt);

    Vec2 GetGridPosition() { return associated.GetGridPosition(); }

    Direction GetMovementDirection() { return movementDirection; }
    State GetState() { return state; }

    void TakeDamage(int damage) { hp -= damage; }

  private:
    Direction movementDirection = Direction::LEFT;

    // 2<=range<=7
    int range, steps = 0;
    State state = State::WALKIN_S;

    int hp;

    Sprite::SpriteState EState[State::STATE_MAX];
    InputManager& input;
    bool movimentAllowed = false;
};

#endif  // ENEMY_H
