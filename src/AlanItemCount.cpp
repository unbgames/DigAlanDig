#include "AlanItemCount.h"
#include "Common.h"

AlanItemCount::AlanItemCount(GameObject& associated) : Component(associated) {
    itemCount.emplace(ItemType::HEART, 0);
    itemCountItem.emplace(ItemType::HEART, new GameObject(Common::Layer::HUD));
    itemCountItem[ItemType::HEART]->box.x = Camera::screenSize.x / 2;
    itemCountItem[ItemType::HEART]->box.y = Camera::screenSize.y / 2;
    Sprite* sprite = new Sprite(*itemCountItem[ItemType::HEART],
                                "assets/hud/numbers.png", 10, -2);
    itemCountItem[ItemType::HEART]->AddComponent(sprite);
    itemCountItem[ItemType::HEART]->AddComponent(
        new Item(*itemCountItem[ItemType::HEART]));

    itemCount[ItemType::METAL] = 0;
    itemCountItem[ItemType::METAL] = new GameObject(Common::Layer::HUD);
    sprite = new Sprite(*itemCountItem[ItemType::METAL],
                        "assets/hud/numbers.png", 10, -2);
    itemCountItem[ItemType::METAL]->AddComponent(sprite);
    itemCountItem[ItemType::METAL]->AddComponent(
        new Item(*itemCountItem[ItemType::METAL]));

    itemCount[ItemType::DIAMOND] = 0;
    itemCountItem[ItemType::DIAMOND] = new GameObject(Common::Layer::HUD);
    sprite = new Sprite(*itemCountItem[ItemType::DIAMOND],
                        "assets/hud/numbers.png", 10, -2);
    itemCountItem[ItemType::DIAMOND]->AddComponent(sprite);
    itemCountItem[ItemType::DIAMOND]->AddComponent(
        new Item(*itemCountItem[ItemType::DIAMOND]));

    itemCount[ItemType::PETROLEUM] = 0;
    itemCountItem[ItemType::PETROLEUM] = new GameObject(Common::Layer::HUD);
    sprite = new Sprite(*itemCountItem[ItemType::PETROLEUM],
                        "assets/hud/numbers.png", 10, -2);
    itemCountItem[ItemType::PETROLEUM]->AddComponent(sprite);
    itemCountItem[ItemType::PETROLEUM]->AddComponent(
        new Item(*itemCountItem[ItemType::PETROLEUM]));
}