#include "AlanItemCount.h"
#include "Common.h"

AlanItemCount::AlanItemCount(GameObject& associated) : Component(associated) {
    itemCount.emplace(ItemType::GOLD, rand() % 5);
    itemCountItem.emplace(ItemType::GOLD, new GameObject(Common::Layer::HUD));
    itemCountItem[ItemType::GOLD]->box.x = 950;
    itemCountItem[ItemType::GOLD]->box.y = 115;
    itemCountItem[ItemType::GOLD]->worldReference = false;
    Sprite* sprite = new Sprite(*itemCountItem[ItemType::GOLD],
                                "assets/hud/numbers.png", 10, -2);
    itemCountItem[ItemType::GOLD]->AddComponent(sprite);
    itemCountItem[ItemType::GOLD]->AddComponent(
        new Item(*itemCountItem[ItemType::GOLD],
                 itemCountItem[ItemType::GOLD]->box.Center(),
                 Vec2(itemCountItem[ItemType::GOLD]->box.Center().x + 20,
                      itemCountItem[ItemType::GOLD]->box.Center().y + 5)));
    std::cout << "GOLD COUNT = " << itemCount[ItemType::GOLD] << std::endl;
    sprite->SetFrame(itemCount[ItemType::GOLD]);

    itemCount.emplace(ItemType::DIAMOND, rand() % 5 + 4);
    itemCountItem.emplace(ItemType::DIAMOND,
                          new GameObject(Common::Layer::HUD));
    itemCountItem[ItemType::DIAMOND]->box.x = 950;
    itemCountItem[ItemType::DIAMOND]->box.y = 263;
    itemCountItem[ItemType::DIAMOND]->worldReference = false;
    sprite = new Sprite(*itemCountItem[ItemType::DIAMOND],
                        "assets/hud/numbers.png", 10, -2);
    itemCountItem[ItemType::DIAMOND]->AddComponent(sprite);
    itemCountItem[ItemType::DIAMOND]->AddComponent(
        new Item(*itemCountItem[ItemType::DIAMOND],
                 itemCountItem[ItemType::DIAMOND]->box.Center(),
                 Vec2(itemCountItem[ItemType::DIAMOND]->box.Center().x + 20,
                      itemCountItem[ItemType::DIAMOND]->box.Center().y + 5)));
    sprite->SetFrame(itemCount[ItemType::DIAMOND]);

    itemCount.emplace(ItemType::PETROLEUM, rand() % 5 + 4);
    itemCountItem.emplace(ItemType::PETROLEUM,
                          new GameObject(Common::Layer::HUD));
    itemCountItem[ItemType::PETROLEUM]->box.x = 950;
    itemCountItem[ItemType::PETROLEUM]->box.y = 415;
    itemCountItem[ItemType::PETROLEUM]->worldReference = false;
    sprite = new Sprite(*itemCountItem[ItemType::PETROLEUM],
                        "assets/hud/numbers.png", 10, -2);
    itemCountItem[ItemType::PETROLEUM]->AddComponent(sprite);
    itemCountItem[ItemType::PETROLEUM]->AddComponent(
        new Item(*itemCountItem[ItemType::PETROLEUM],
                 itemCountItem[ItemType::PETROLEUM]->box.Center(),
                 Vec2(itemCountItem[ItemType::PETROLEUM]->box.Center().x + 20,
                      itemCountItem[ItemType::PETROLEUM]->box.Center().y + 5)));
    sprite->SetFrame(itemCount[ItemType::PETROLEUM]);
}

void AlanItemCount::Render(Common::Layer layer) const {
    for (auto item : itemCountItem) {
        item.second->box.SetCenter(item.second->GetComponent<Item*>()->center);
        item.second->GetComponent<Item*>()->bg->Render(layer);
        item.second->box.SetCenter(
            item.second->GetComponent<Item*>()->numberCenter);
        item.second->RenderOrder(layer);
    }
}