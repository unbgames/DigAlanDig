#include "StageState.h"
#define INCLUDE_SDL
#include "SDL_include.h"

#include <stdio.h>
#include "Alan.h"
#include "AlanAnimation.h"
#include "BigAlan.h"
#include "Camera.h"
#include "EnemySpawn.h"
#include "Game.h"
#include "HudMeter.h"
#include "Interpol.h"
#include "Light.h"
#include "MiniTileMap.h"
#include "Parallax.h"
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
    Camera::offset.Set(-(Camera::screenSize.x - 600 - 120), 0);
    input.title = false;

    GameObject *gm =
        new GameObject(Common::Layer::DEFAULT | Common::Layer::LIGHT);
    objectArray.emplace_back(gm);
    tileMap = new TileMap(*gm, "assets/map/manager.json", true);
    gm->AddComponent(tileMap);

    Game::GetInstance()->GetGridControl()->SetTileMap(tileMap);

    // Alan
    GameObject *alanGO = new GameObject();
    Vec2 gp(3, 0);
    alanGO->box.x = (gp.x * GetGridSize()) - GetGridSize() / 2;
    alanGO->box.y = (gp.y * GetGridSize()) - GetGridSize() / 2;
    alanGO->gridPosition = gp;
    objectArray.emplace_back(alanGO);

    Game::GetInstance()->GetGridControl()->SetAlan(GetObjectPrt(alanGO));

        alanGO->AddComponent(
        new Sprite(*alanGO, "assets/img/alan/idle.png", 2, 0.2));

    Alan *lilAlan = new Alan(*alanGO, GetGridSize());
    alanGO->AddComponent(lilAlan);

    Interpol *alanMov = new Interpol(*alanGO);
    alanGO->AddComponent(alanMov);

    AlanAnimation *alanAnimation = new AlanAnimation(*alanGO);
    alanGO->AddComponent(alanAnimation);

    GameObject *alanL = new GameObject(Common::Layer::LIGHT);
    objectArray.emplace_back(alanL);
    alanL->AddComponent(new Light(*alanL, GetObjectPrt(alanGO)));

    Camera::Follow(alanGO);

    GameObject *esGO = new GameObject();
    esGO->AddComponent(new EnemySpawn(*esGO, tileMap));
    objectArray.emplace_back(esGO);

    // MiniMap
    GameObject *MiniMapTile = new GameObject(Common::Layer::HUD);
    MiniMapTile->box.pos = {1024 - 6 * 15, 200};
    TileSet *minitileSet = new TileSet("assets/map/miniground.json");

    MiniTileMap *miniTilemap = new MiniTileMap(*MiniMapTile, minitileSet,
                                               tileMap, GetObjectPrt(alanGO));
    MiniMapTile->AddComponent(miniTilemap);
    objectArray.emplace_back(MiniMapTile);

    // Big-Alan
    GameObject *bigAlan = new GameObject(Common::Layer::HUD);
    objectArray.emplace_back(bigAlan);
    bigAlan->AddComponent(new Sprite(*bigAlan, "assets/img/mooda.png", 2, -1));
    bigAlan->AddComponent(new BigAlan(*bigAlan));
    bigAlan->worldReference = false;
    bigAlan->box.pos = {0, 460};

    // HUD
    GameObject *backG = new GameObject(Common::Layer::BG);
    backG->worldReference = false;
    objectArray.emplace_back(backG);
    backG->AddComponent(new bgCircularY(*backG, "assets/img/bg.png"));
    backG->AddComponent(new Parallax(*backG, 0.5));
    backG->box.pos = {304, 0};

    GameObject *meterHeart = new GameObject(Common::Layer::HUD);
    objectArray.emplace_back(meterHeart);
    meterHeart->worldReference = false;
    meterHeart->box.pos = {20, 26};
    bigAlan->AddComponent(new HudMeter(*meterHeart, "assets/hud/barravida.png",
                                       "assets/hud/coracao.png"));

    GameObject *meterLight = new GameObject(Common::Layer::HUD);
    objectArray.emplace_back(meterLight);
    meterLight->worldReference = false;
    meterLight->box.pos = {176, 26};
    bigAlan->AddComponent(new HudMeter(*meterLight, "assets/hud/barraluz.png",
                                       "assets/hud/raio.png"));

    music.Open("assets/audio/marmota.ogg");
    count = 0;
    halfBeatCounter = 0;
    Mix_SetPostMix(noEffect, NULL);
}

void StageState::Start() {
    if (!started) LoadAssets();

    StartArray();
}

void StageState::Update(float dt) {
    Camera::Update(dt);

    if (beat) {
        beat = false;
        static constexpr float bpm = 120;
        static const int beatTime = (60 * 1000) / bpm;
        static const int halfBeatTime = beatTime / 2;

        if (halfBeatCounter == 0) Game::GetInstance()->StartBeatTime();

        Game::GetInstance()->UpdateBeatTime(halfBeatCounter * halfBeatTime);
        halfBeatCounter++;
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
