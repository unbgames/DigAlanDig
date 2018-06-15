#include "AlanAnimation.h"

AlanAnimation::AlanAnimation(GameObject &associated) : Component(associated) {
    AState[State::IDLE] = {"assets/img/alan/idle.png", 2, 2, -1};
    AState[State::WALKIN] = {"assets/img/alan/walkin.png", 2, 4, 0.2};
    // AState[State::FALLIN] = {"assets/img/alan/fallin.png", 2, 2, -1};
    AState[State::FALLIN] = {"assets/img/alan/idle.png", 2, 2, 0.2};
    AState[State::DIG] = {"assets/img/alan/dig.png", 2, 8, 0.2};
    // AState[State::HIT] = {"assets/img/alan/hit.png", 2, 2, -1};
    AState[State::HIT] = {"assets/img/alan/idle.png", 2, 2, 0.2};
    // AState[State::CLIMBIN] = {"assets/img/alan/climbin.png", 2, 2, -1};
    AState[State::CLIMBIN] = {"assets/img/alan/dig.png", 2, 8, 0.2};
    AState[State::DIG_CLIMB] = {"assets/img/alan/idle.png", 2, 2, 0.2};
    AState[State::DANCIN] = {"assets/img/alan/idle.png", 2, 2, 0.2};
    AState[State::DEAD] = {"assets/img/alan/idle.png", 2, 2, 0.2};
}

AlanAnimation::~AlanAnimation() {}

void AlanAnimation::Update(float dt) {
    Sprite *sprite = associated.GetComponent<Sprite *>();

    if (sprite->FrameTimePassed()) {
        if (oldState == State::CLIMBIN || currentState == State::CLIMBIN) {
            oldState = currentState;
            currentState = State::CLIMBIN;
            if (currentDirection != Direction::W &&
                currentDirection != Direction::E)
                currentDirection = oldDirection;
            sprite->Open(AState[currentState], currentDirection);
        } else {
            oldState = currentState;
            currentState = State::IDLE;
            sprite->Open(AState[currentState], Direction::W);
        }
    }
}

void AlanAnimation::SetAction(Transition trans, Direction dir) {
    oldState = currentState;
    switch (currentState) {
        case NONE_S:
            std::cout << "STATE NONE!" << std::endl;

            currentState = State::IDLE;
            break;

        case IDLE:
            switch (trans) {
                case WALK:
                    currentState = State::WALKIN;
                    break;

                case HIT_T:
                    currentState = State::HIT;
                    break;

                case CLIMB:
                    currentState = State::CLIMBIN;
                    break;

                case DIG_T:
                    currentState = State::DIG;
                    break;

                default:
                    return;
                    break;
            }
            break;

        case WALKIN:
            switch (trans) {
                case FALL:
                    currentState = State::FALLIN;
                    break;

                default:
                    return;
                    break;
            }
            break;

        case FALLIN:
            switch (trans) {
                case FLOOR:
                    currentState = State::IDLE;
                    break;

                default:
                    return;
                    break;
            }
            break;

        case DIG:
            switch (trans) {
                case FALL:
                    currentState = State::WALKIN;
                    break;

                case NONE_T:
                    currentState = State::IDLE;
                    break;

                default:
                    return;
                    break;
            }
            break;

        case HIT:

            break;

        case CLIMBIN:
            switch (trans) {
                case NONE_T:
                    currentState = State::IDLE;
                    break;
                case WALK:
                    currentState = State::WALKIN;
                    break;

                case STOP_CLIMB:
                    currentState = State::FALLIN;
                    break;

                case DIG_T:
                    currentState = State::DIG_CLIMB;
                    break;

                default:
                    return;
                    break;
            }
            break;

        case DIG_CLIMB:

            break;

        case DANCIN:

            break;

        case DEAD:

            break;

        default:
            return;
            break;
    }

    oldDirection = currentDirection;
    currentDirection = dir;

    Sprite *sprite = associated.GetComponent<Sprite *>();
    sprite->Open(AState[currentState], dir);
}