#include "InputManager.h"
InputManager::InputManager() {
    for (int i = 0; i < SDL_NumJoysticks(); i++) {
        if (AddController(i)) {
            std::cout << "Joystick" << i << "connected!" << std::endl;
            break;
        }
    }
}

inline void InputManager::UpdateKey(int &update, bool &state,
                                    bool newValue) const {
    if (state != newValue) {
        update = frame;
        state = newValue;
    }
}

float fixRange(float value, float fix) {
    float ret = value + fix;
    if (ret > 1.0)
        ret -= 2;
    else if (ret < -1.0)
        ret += 2;

    return ret;
}

void InputManager::Update(float deltaRhythm) {
    frame++;
    quitRequested = false;
    this->deltaRhythm = fixRange(deltaRhythm, 0.6);

    SDL_GetMouseState(&mouseX, &mouseY);
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        // Se o evento for quit, setar a flag para terminação
        switch (event.type) {
            case SDL_QUIT:
                quitRequested = true;
                break;

            case SDL_KEYDOWN:
            case SDL_KEYUP:
                UpdateKey(keyUpdate[event.key.keysym.scancode],
                          keyState[event.key.keysym.scancode],
                          event.type == SDL_KEYDOWN);
                break;

            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                UpdateKey(mouseUpdate[event.button.button],
                          mouseState[event.button.button],
                          event.type == SDL_MOUSEBUTTONDOWN);
                break;

            case SDL_CONTROLLERBUTTONDOWN:
            case SDL_CONTROLLERBUTTONUP:
                UpdateKey(gamepadUpdate[event.cbutton.button],
                          gamepadState[event.cbutton.button],
                          event.type == SDL_CONTROLLERBUTTONDOWN);
                break;

            case SDL_CONTROLLERDEVICEADDED:
                AddController(event.cdevice.which);
                std::cout << "control pad: "
                          << SDL_GameControllerName(gameController)
                          << std::endl;
                break;

            case SDL_CONTROLLERDEVICEREMOVED:
                RemoveController();
                break;
        }
    }

    if (KeyPress(SDL_SCANCODE_0)) {
        keyAdjust += 0.05;
        std::cout << "\nKey Adjust = " << keyAdjust << "ms\n";
    }
    if (KeyPress(SDL_SCANCODE_9)) {
        keyAdjust -= 0.05;
        std::cout << "\nKey Adjust = " << keyAdjust << "ms\n";
    }
}

bool InputManager::AddController(int id) {
    if (SDL_IsGameController(id)) {
        SDL_GameControllerClose(gameController);
        gameController = SDL_GameControllerOpen(id);
        if (gameController == NULL)
            std::cout << "SDL GameController(" << id
                      << ") Error: " << SDL_GetError() << std::endl;
        return true;
    }
    std::cout << "Controller not suported" << std::endl;

    return false;
}

void InputManager::RemoveController(void) {
    SDL_GameControllerClose(gameController);
}
