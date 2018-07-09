#ifndef ALANITEMCOUNT_H
#define ALANITEMCOUNT_H
#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_TTF
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include <iostream>
#include <queue>
#include <string>
#include "Component.h"
#include "Game.h"
#include "InputManager.h"
#include "Sprite.h"

class AlanItemCount : public Component {
  public:
    enum ItemType { GOLD = 1, DIAMOND, PETROLEUM };

    AlanItemCount(GameObject& associated);

    ~AlanItemCount() {
        itemCount.clear();
        itemCountItem.clear();
    }

    void Update(float dt) {
        for (auto item : itemCount) {
            if (item.second == 0) {
            }
        }
    }
    void RhythmUpdate() {}
    void RhythmReset() {}
    void Render(Common::Layer layer) const;
    void ItemCollected(int itemType) {
        if (itemCount[itemType] > 0)
            itemCountItem[itemType]->GetComponent<Sprite*>()->SetFrame(
                --itemCount[itemType]);
    }

  private:
    std::unordered_map<int, GameObject*> itemCountItem;
    std::unordered_map<int, int> itemCount;
};

class Item : public Component {
  public:
    Item(GameObject& associated, Vec2 newCenter, Vec2 newNumberCenter)
        : Component(associated),
          center(newCenter),
          numberCenter(newNumberCenter) {
        bg = new Sprite(associated, "assets/hud/ovocinza.png");
    }

    ~Item() { delete bg; }
    void Update(float dt) {}
    void RhythmUpdate() {}
    void RhythmReset() {}
    void Render(Common::Layer layer) const {}

    Sprite* bg;
    Vec2 center, numberCenter;
    int spriteCount = 1;
};

#endif  // ALANITEMCOUNT_H
