#include "TitleState.h"
#define INCLUDE_SDL
#include "SDL_include.h"

#include <stdio.h>
#include "Camera.h"
#include "Game.h"
#include "Sound.h"
#include "Sprite.h"
#include "StageState.h"
#include "Text.h"
#include "TileMap.h"
#include "Vec2.h"

TitleState::TitleState() {}

void TitleState::LoadAssets() {
    GameObject* gm = new GameObject(Common::Layer::HUD);
    gm->worldReference = false;
    objectArray.emplace_back(gm);
    gm->AddComponent(new Sprite(*gm, "assets/img/titleAlan.png"));

    gm = new GameObject(Common::Layer::HUD);
    Sprite* sprite = new Sprite(*gm, "assets/img/title.png");
    gm->box.SetCenter(Camera::Center().x, Camera::Center().y - 100);
    gm->worldReference = false;
    objectArray.emplace_back(gm);
    gm->AddComponent(sprite);

    gm = new GameObject(Common::Layer::HUD);
    sprite = new Sprite(*gm, "assets/img/pressSpace.png");
    gm->box.SetCenter(Camera::Center().x, Camera::Center().y + 150);
    gm->worldReference = false;
    gm->pressSpace = true;
    objectArray.emplace_back(gm);
    gm->AddComponent(sprite);
    Game::GetInstance()->StartBeatTime();

    music.Open("assets/audio/menu.ogg");
}

void TitleState::Start() {
    if (!started) LoadAssets();

    StartArray();
}

void TitleState::Update(float dt) {
    if (input.ActionPress(input.ENTER))
        Game::GetInstance()->Push(new StageState());
    UpdateArray(dt);
}

void TitleState::Render() const { RenderArray(); }

void TitleState::RhythmUpdate() {
    if (!musicPlaying) {
        music.Play();
        musicPlaying = true;
    }
    RhythmUpdateArray();
    input.pressSpaceTitle = !input.pressSpaceTitle;
}
