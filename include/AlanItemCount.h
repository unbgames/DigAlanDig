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
    enum ItemType { HEART = 0, METAL, DIAMOND, PETROLEUM };

    AlanItemCount(GameObject& associated);

    ~AlanItemCount() {}
    void Update(float dt) {}
    void RhythmUpdate() {}
    void RhythmReset() {}
    void Render(Common::Layer layer) const {}
    void ItemCollected(ItemType itemType) {
        itemCountItem[itemType]->GetComponent<Sprite*>()->SetFrame(
            ++itemCount[itemType]);
    }

  private:
    std::unordered_map<int, GameObject*> itemCountItem;
    std::unordered_map<int, int> itemCount;
};

class Item : public Component {
  public:
    Item(GameObject& associated) : Component(associated) {}
    void Update(float dt) {}
    void RhythmUpdate() {}
    void RhythmReset() {}
    void Render(Common::Layer layer) const {}

    int spriteCount = 1;
};

#endif  // ALANITEMCOUNT_H
