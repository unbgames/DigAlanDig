#include "AlanAnimation.h"
#include "Alan.h"

AlanAnimation::AlanAnimation(GameObject &associated) : Component(associated) {
    AState[State::IDLE] = {"assets/img/alan/idle.png", 2, 2, -1};
    AState[State::WALKIN] = {"assets/img/alan/walkin.png", 2, 4, 0.2};
    // AState[State::FALLIN] = {"assets/img/alan/fallin.png", 2, 2, -1};
    AState[State::FALLIN] = {"assets/img/alan/idle.png", 2, 2, 0.2};
    AState[State::DIG] = {"assets/img/alan/dig.png", 2, 8, 0.1};
    // AState[State::HIT] = {"assets/img/alan/hit.png", 2, 2, -1};
    AState[State::HIT] = {"assets/img/alan/idle.png", 2, 2, 0.2};
    // AState[State::CLIMBIN] = {"assets/img/alan/climbin.png", 2, 2, -1};
    AState[State::CLIMBIN] = {"assets/img/alan/dig.png", 2, 8, 0.2};
    AState[State::DIG_CLIMB] = {"assets/img/alan/idle.png", 2, 2, 0.2};
    AState[State::DANCIN] = {"assets/img/alan/dance.png", 10, 10, -1};
    AState[State::DEAD] = {"assets/img/alan/die.png", 3, 3, 0.2};
}

AlanAnimation::~AlanAnimation() {}

void AlanAnimation::Update(float dt) {
    if (currentState == State::DANCIN || currentState == State::DEAD) return;

    Sprite *sprite = associated.GetComponent<Sprite *>();
    Alan *alan = associated.GetComponent<Alan *>();

    if (sprite->FrameTimePassed() &&
        alan->GetMovementDirection() == Alan::Direction::NONE) {
        if ((oldState == State::CLIMBIN || currentState == State::CLIMBIN) &&
            currentState != State::IDLE) {
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
    switch (currentState) {
        case NONE_S:
            oldState = currentState;
            std::cout << "STATE NONE!" << std::endl;

            currentState = State::IDLE;
            break;

        case IDLE:
            switch (trans) {
                case WALK:
                    oldState = currentState;
                    currentState = State::WALKIN;
                    break;

                case HIT_T:
                    oldState = currentState;
                    currentState = State::HIT;
                    break;

                case CLIMB:
                    oldState = currentState;
                    currentState = State::CLIMBIN;
                    break;

                case DIG_T:
                    oldState = currentState;
                    currentState = State::DIG;
                    break;

                case DANCE:
                    oldState = currentState;
                    currentState = State::DANCIN;
                    break;

                case DIE:
                    oldState = currentState;
                    currentState = State::DEAD;
                    break;

                default:
                    return;
                    break;
            }
            break;

        case WALKIN:
            switch (trans) {
                case FALL:
                    oldState = currentState;
                    currentState = State::FALLIN;
                    break;

                case NONE_T:
                    oldState = currentState;
                    currentState = State::IDLE;
                    break;

                case DANCE:
                    oldState = currentState;
                    currentState = State::DANCIN;
                    break;

                case DIE:
                    oldState = currentState;
                    currentState = State::DEAD;
                    break;

                default:
                    return;
                    break;
            }
            break;

        case FALLIN:
            switch (trans) {
                case FLOOR:
                    oldState = currentState;
                    currentState = State::IDLE;
                    break;

                case NONE_T:
                    oldState = currentState;
                    currentState = State::IDLE;
                    break;

                case DANCE:
                    oldState = currentState;
                    currentState = State::DANCIN;
                    break;

                case DIE:
                    oldState = currentState;
                    currentState = State::DEAD;
                    break;

                default:
                    return;
                    break;
            }
            break;

        case DIG:
            switch (trans) {
                case FALL:
                    oldState = currentState;
                    currentState = State::WALKIN;
                    break;

                case NONE_T:
                    oldState = currentState;
                    currentState = State::IDLE;
                    break;

                case DANCE:
                    oldState = currentState;
                    currentState = State::DANCIN;
                    break;

                case DIE:
                    oldState = currentState;
                    currentState = State::DEAD;
                    break;

                default:
                    return;
                    break;
            }
            break;

        case HIT:
            oldState = currentState;
            currentState = State::IDLE;
            break;

        case CLIMBIN:
            switch (trans) {
                case NONE_T:
                    oldState = currentState;
                    currentState = State::IDLE;
                    break;
                case WALK:
                    oldState = currentState;
                    currentState = State::WALKIN;
                    break;

                case STOP_CLIMB:
                    oldState = currentState;
                    currentState = State::FALLIN;
                    break;

                case DIG_T:
                    oldState = currentState;
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