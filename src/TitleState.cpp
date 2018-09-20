#define INCLUDE_SDL
#include <stdio.h>
#include "TitleState.h"
#include "SDL_include.h"
#include "Camera.h"
#include "Game.h"
#include "Parallax.h"
#include "Sound.h"
#include "Sprite.h"
#include "StageState.h"
#include "TileMap.h"
#include "Vec2.h"
#define POSITION_X_SPACE 0
#define POSITION_Y_SPACE 0
#define SPACE_VELOCITY 2
#define POSITION_X_CLOUD 0
#define POSITION_Y_CLOUD 4300
#define POSITION_X_CLOUD_2 0
#define POSITION_Y_CLOUD_2 3500
#define CLOUD_2_VELOCITY 2
#define POSITION_X_CLOUD_3 0
#define POSITION_Y_CLOUD_3 5000
#define CLOUD_3_VELOCITY 3
#define MENU_SCREEN "assets/img/HUD_e_menus/menu_principal/Tela_menu.png"
#define SPACE_SCREEN "assets/img/HUD_e_menus/menu_principal/Espaço_Profundo.png"
#define CLOUD_1 "assets/img/HUD_e_menus/menu_principal/nuvem_1.png"
#define CLOUD_2 "assets/img/HUD_e_menus/menu_principal/nuvem_2.png"
#define CLOUD_3 "assets/img/HUD_e_menus/menu_principal/nuvem_3.png"
#define TITLE_MENU "assets/img/title.png"
#define TITLE_PRESS_SPACE "assets/img/pressSpace.png"
#define SPACESHIP_MENU "assets/img/marmozord_fly.png"
#define AUDIO_MENU "assets/audio/menu.ogg"


TitleState::TitleState() {}

void TitleState::LoadAssets() 
{

    GameObject* initial_layout = new GameObject(Common::Layer::BG);
    initial_layout->worldReference = false;
    objectArray.emplace_back(initial_layout);
    initial_layout->AddComponent(
        new Sprite(*initial_layout, MENU_SCREEN));

    initial_layout = new GameObject(Common::Layer::BG);
    initial_layout->box.x = POSITION_X_SPACE;
    initial_layout->box.y = POSITION_Y_SPACE;
    initial_layout->worldReference = false;
    objectArray.emplace_back(initial_layout);
    initial_layout->AddComponent(new ParallaxX(*initial_layout, SPACE_VELOCITY));
    initial_layout->AddComponent(new bgCircularX(
        *initial_layout, SPACE_SCREEN));

    initial_layout = new GameObject(Common::Layer::BG);
    initial_layout->box.x = POSITION_X_CLOUD;
    initial_layout->box.y = POSITION_Y_CLOUD;
    initial_layout->worldReference = false;
    objectArray.emplace_back(initial_layout);
    initial_layout->AddComponent(new ParallaxX(*initial_layout));
    initial_layout->AddComponent(new bgCircularX(
        *initial_layout, CLOUD_1));

    initial_layout = new GameObject(Common::Layer::BG);
    initial_layout->box.x = POSITION_X_CLOUD_2;
    initial_layout->box.y = POSITION_Y_CLOUD_2;
    initial_layout->worldReference = false;
    objectArray.emplace_back(initial_layout);
    initial_layout->AddComponent(new ParallaxX(*initial_layout, CLOUD_2_VELOCITY));
    initial_layout->AddComponent(new bgCircularX(
        *initial_layout, CLOUD_2));

    initial_layout = new GameObject(Common::Layer::BG);
    initial_layout->box.x = POSITION_X_CLOUD_3;
    initial_layout->box.y = POSITION_Y_CLOUD_3;
    initial_layout->worldReference = false;
    objectArray.emplace_back(initial_layout);
    initial_layout->AddComponent(new ParallaxX(*initial_layout, CLOUD_3_VELOCITY));
    initial_layout->AddComponent(new bgCircularX(
        *initial_layout, CLOUD_3));

    initial_layout = new GameObject(Common::Layer::HUD);
    Sprite* sprite = new Sprite(*initial_layout, TITLE_MENU);
    const float scale_x_title = 0.45;
    const double position_x_title = Camera::Center().x / 2;
    const double position_y_title = Camera::Center().y - 50;
    sprite->SetScaleX(scale_x_title);
    initial_layout->box.SetCenter(position_x_title, position_y_title);
    initial_layout->worldReference = false;
    objectArray.emplace_back(initial_layout);
    initial_layout->AddComponent(sprite);

    initial_layout = new GameObject(Common::Layer::HUD);
    sprite = new Sprite(*initial_layout, TITLE_PRESS_SPACE);
    const float scale_x_press_space = 0.9;
    const double position_x_press_space = Camera::Center().x;
    const double position_y_press_space = Camera::Center().y + 300;
    sprite->SetScaleX(scale_x_press_space);
    initial_layout->box.SetCenter(position_x_press_space, position_y_press_space);
    initial_layout->worldReference = false;
    initial_layout->blink = true;
    objectArray.emplace_back(initial_layout);
    initial_layout->AddComponent(sprite);
    
    initial_layout = new GameObject(Common::Layer::HUD);
    sprite = new Sprite(*initial_layout, SPACESHIP_MENU, 2, -1);
    const float scale_x_spaceship = 1.4;
    const double position_x_spaceship = Camera::Center().x + 200;
    const double position_y_spaceship = Camera::Center().y;
    sprite->SetScaleX(scale_x_spaceship);
    initial_layout->box.SetCenter(position_x_spaceship, position_y_spaceship);
    initial_layout->setRect(initial_layout->box);
    initial_layout->worldReference = false;
    initial_layout->move = true;
    objectArray.emplace_back(initial_layout);
    initial_layout->AddComponent(sprite);

    Game::GetInstance()->StartBeatTime();

    music.Open(AUDIO_MENU);

}


void TitleState::Start() 
{
    if (!started) LoadAssets();

    StartArray();
}

void TitleState::Update(float dt) 
{
    input.title = true;
    if (input.ActionPress(input.ENTER))
        Game::GetInstance()->Push(new StageState());
    UpdateArray(dt);
}

void TitleState::Render() const { RenderArray(); }

void TitleState::RhythmUpdate() 
{
    if (!musicPlaying) 
    {
        music.Play();
        musicPlaying = true;
    }

    RhythmUpdateArray();
    input.shouldShow = !input.shouldShow;
}
