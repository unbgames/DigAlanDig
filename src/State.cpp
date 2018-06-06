#include "State.h"
#include <stdio.h>
#include "Camera.h"
#include "Common.h"
#include "Game.h"
#include "SDL2/SDL.h"
#include "Sound.h"
#include "Sprite.h"
#include "TileMap.h"
#include "Vec2.h"

State::State() : input(InputManager::GetInstance()) {}

std::weak_ptr<GameObject> State::AddObject(GameObject* go) {
    std::shared_ptr<GameObject> ptr(go);
    objectArray.emplace_back(ptr);
    if (started) ptr->Start();

    return ptr;
}

std::weak_ptr<GameObject> State::GetObjectPrt(GameObject* go) {
    std::weak_ptr<GameObject> wp;
    for (std::shared_ptr<GameObject>& obj : objectArray) {
        if (obj.get() == go) {
            wp = obj;
            break;
        }
    }

    return wp;
}

void State::StartArray() {
    if (started) return;

    //    for (auto obj : objectArray) obj->Start();
    for (size_t i = 0; i < objectArray.size(); i++) objectArray[i]->Start();

    started = true;
}

void State::UpdateArray(float dt) {
    // Update
    //    for (auto obj : objectArray) obj->Update(dt);
    for (size_t i = 0; i < objectArray.size(); i++) objectArray[i]->Update(dt);

    // Delete
    auto removeDead = [&](std::shared_ptr<GameObject> const& p) {
        return p->IsDead() && p->CanEnd();
    };
    objectArray.erase(
        std::remove_if(objectArray.begin(), objectArray.end(), removeDead),
        objectArray.end());

    // KeyPress
    if (input.KeyPress(SDL_SCANCODE_ESCAPE) || input.QuitRequested())
        quitRequested = true;
}

void State::RhythmUpdateArray() {
    for (auto obj : objectArray) obj->RhythmUpdate();
}

void State::RhythmResetArray() {
    for (auto obj : objectArray) obj->RhythmReset();
}

int PulseColor(float dtR, int combo) {
    dtR = (dtR > 0) ? 0 : -dtR;
    combo = (combo > 15) ? 15 : combo;
    dtR = dtR * 2 * (combo + 1);
    return (dtR > 255) ? 255 : dtR;
}

void State::RenderLight() const {
    SDL_Renderer* renderer = Game::GetInstance()->GetRenderer();
    static SDL_Texture* texTarget = SDL_CreateTexture(
        renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,
        Camera::screenSize.x, Camera::screenSize.y);

    // Rendering to texture (Lights to an intermediary texture)
    SDL_SetRenderTarget(renderer, texTarget);

    int color =
        50 + PulseColor(input.GetDeltaRhythm(), Game::GetInstance()->combo);
    SDL_SetRenderDrawColor(renderer, color, color, color * 0.8, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_ADD);
    for (auto obj : objectArray) {
        obj->RenderOrder(Common::Layer::LIGHT);
    }

    // Rendering the texture to screen (multiply light texture to screen)
    SDL_SetRenderTarget(renderer, NULL);

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_MOD);
    SDL_SetTextureBlendMode(texTarget, SDL_BLENDMODE_MOD);
    SDL_RenderCopy(renderer, texTarget, NULL, NULL);

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

void State::RenderArray() const {
    for (auto obj : objectArray) {
        obj->RenderOrder(Common::Layer::DEFAULT);
    }

    RenderLight();

    for (auto obj : objectArray) {
        obj->RenderOrder(Common::Layer::HUD);
    }
}
