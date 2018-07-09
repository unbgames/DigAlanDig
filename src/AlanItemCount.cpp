#include "AlanItemCount.h"
#include "Common.h"

AlanItemCount::AlanItemCount(GameObject& associated) : Component(associated) {
    itemCount.emplace(ItemType::METAL, 0);
    itemCountItem.emplace(ItemType::METAL, new GameObject(Common::Layer::HUD));
    itemCountItem[ItemType::METAL]->box.x = 906;
    itemCountItem[ItemType::METAL]->box.y = 100;
    itemCountItem[ItemType::METAL]->worldReference = false;
    Sprite* sprite = new Sprite(*itemCountItem[ItemType::METAL],
                                "assets/hud/numbers.png", 10, -2);
    itemCountItem[ItemType::METAL]->AddComponent(sprite);
    itemCountItem[ItemType::METAL]->AddComponent(
        new Item(*itemCountItem[ItemType::METAL]));

    itemCount.emplace(ItemType::DIAMOND, 0);
    itemCountItem.emplace(ItemType::DIAMOND,
                          new GameObject(Common::Layer::HUD));
    itemCountItem[ItemType::DIAMOND]->box.x = 906;
    itemCountItem[ItemType::DIAMOND]->box.y = 238;
    itemCountItem[ItemType::DIAMOND]->worldReference = false;
    sprite = new Sprite(*itemCountItem[ItemType::DIAMOND],
                        "assets/hud/numbers.png", 10, -2);
    itemCountItem[ItemType::DIAMOND]->AddComponent(sprite);
    itemCountItem[ItemType::DIAMOND]->AddComponent(
        new Item(*itemCountItem[ItemType::DIAMOND]));

    itemCount.emplace(ItemType::PETROLEUM, 0);
    itemCountItem.emplace(ItemType::PETROLEUM,
                          new GameObject(Common::Layer::HUD));
    itemCountItem[ItemType::PETROLEUM]->box.x = 906;
    itemCountItem[ItemType::PETROLEUM]->box.y = 395;
    itemCountItem[ItemType::PETROLEUM]->worldReference = false;
    sprite = new Sprite(*itemCountItem[ItemType::PETROLEUM],
                        "assets/hud/numbers.png", 10, -2);
    itemCountItem[ItemType::PETROLEUM]->AddComponent(sprite);
    itemCountItem[ItemType::PETROLEUM]->AddComponent(
        new Item(*itemCountItem[ItemType::PETROLEUM]));
}

void AlanItemCount::Render(Common::Layer layer) const {
    for (auto item : itemCountItem) {
        item.second->GetComponent<Item*>()->bg->Render(layer);
        item.second->RenderOrder(layer);
    }
}