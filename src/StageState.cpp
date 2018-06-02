#include "StageState.h"
#include <stdio.h>
#include "Alan.h"
#include "Alien.h"
#include "BigAlan.h"
#include "Camera.h"
#include "Collider.h"
#include "Collision.h"
#include "Endstate.h"
#include "Face.h"
#include "Game.h"
#include "Light.h"
#include "MiniTileMap.h"
#include "PenguinBody.h"
#include "SDL2/SDL.h"
#include "Sprite.h"
#include "Vec2.h"

StageState::StageState() {}

int StageState::count = 0;
int StageState::timeRhythm = 0;
bool StageState::beat = false;

void StageState::noEffect(void *udata, Uint8 *stream, int len) {
    static constexpr float bitPBeat = 44100 * (120 / 60);
    static constexpr float halfBitPBeat = bitPBeat / 2;

    count += len;
    if (count >= halfBitPBeat) {
        beat = true;
        count -= halfBitPBeat;
        timeRhythm = SDL_GetTicks();
    }
}

void StageState::LoadAssets() {
    Camera::pos.Set(-(Camera::screenSize.x - 600) / 2, 0);

    GameObject *gm = new GameObject();
    objectArray.emplace_back(gm);
    tileSet =
        new TileSet(100, 100, "assets/img/GroundhogAlanBackgroundSample.png");
    tileMap = new TileMap(*gm, "assets/map/tileMapGroundhog.txt", tileSet);
    gm->AddComponent(tileMap);

    GameObject *alan = new GameObject();
    objectArray.emplace_back(alan);
    alan->AddComponent(new Sprite(*alan, "assets/img/GroundhogAlan.png", 6));
    Vec2 gp(3, 0);
    Alan *lilAlan = new Alan(*alan, gp, 100, 100);
    alan->AddComponent(lilAlan);
    alan->box.pos = gp * 100;
    alan->AddComponent(new Light(*alan));

    Camera::Follow(alan);

    GameObject *MiniMapTile = new GameObject();
    MiniMapTile->box.pos = {858, 84};
    TileSet *minitileSet =
        new TileSet(20, 20, "assets/img/GroundhogAlanMap.png");

    MiniTileMap *miniTilemap =
        new MiniTileMap(*MiniMapTile, minitileSet, tileMap, lilAlan);
    MiniMapTile->AddComponent(miniTilemap);
    objectArray.emplace_back(MiniMapTile);

    GameObject *bigAlan = new GameObject();
    objectArray.emplace_back(bigAlan);
    bigAlan->AddComponent(new Sprite(*bigAlan, "assets/img/alan.png"));
    bigAlan->AddComponent(new BigAlan(*bigAlan));
    bigAlan->worldReference = false;
    bigAlan->box.pos = {-5, 510};

    music.Open("assets/audio/marmota.ogg");
    Mix_SetPostMix(noEffect, NULL);
}

void StageState::Start() {
    if (!started) LoadAssets();

    StartArray();
}

void StageState::Update(float dt) {
    Camera::Update(dt);

    if (beat) {
        Game::GetInstance()->UpdateBeatTime(timeRhythm);
    }
    UpdateArray(dt);
}

void StageState::RhythmUpdate() {
    if (!musicPlaying) {
        music.Play();
        musicPlaying = true;
    }
    RhythmUpdateArray();
}

void StageState::RhythmReset() { RhythmResetArray(); }

void StageState::Render() const { RenderArray(); }
