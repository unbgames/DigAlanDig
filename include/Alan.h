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

        if (missCounter > 1) {
            Game::GetInstance()->combo /= 2;
            movementDirection = Direction::NONE;
        }

        moved = false;
    }
    void Render(Common::Layer layer) const {}

    int GetMaxPosition() const { return maxPosition; }

    void Fallin(float dt);

    Vec2 GetGridPosition() { return associated.GetGridPosition(); }

    Direction GetMovementDirection() { return movementDirection; }
    Action GetAction() { return action; }

    int GetDamage() { return damage; }
    void TakeDamage() {
        std::cout << "HP = " << hp << std::endl;
        hp--;
    }
    void SetDamage(int damage) { this->damage = damage; }
    int GetHP() { return hp; }

  private:
    Direction movementDirection = Direction::NONE;
    Action action = Action::STANDIN;

    int hp = 6;

    int maxPosition = 0;
    int gridsLeft = 0;

    InputManager& input;

    int gridSize;
    int damage = 1;

    bool moved = false;
    bool animationOnGoing = false;
};

#endif  // ALAN_H
