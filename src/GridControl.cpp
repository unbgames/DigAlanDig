#include "GridControl.h"
#include "Alan.h"

GridControl *GridControl::_instance = nullptr;

GridControl *GridControl::GetInstance() {
    if (!_instance) _instance = new GridControl();
    return _instance;
}

int GridControl::TestPath(Vec2 target, bool isAlan) {
    if (target.x >= tileMap->GetWidth() || target.y >= tileMap->GetHeight()) {
        return WhatsThere::NONE;
    }

    if (isAlan) {
        int block = tileMap->At(target.x, target.y, tileMap->Layers::BLOCOS);
        if (block == 2) {
            return WhatsThere::FREE;

        } else if (int enemy = tileMap->At(target.x, target.y,
                                           tileMap->Layers::INIMIGOS)) {
            std::cout << "ENEMY " << enemy << std::endl;
            return WhatsThere::ENEMY;
        } else if (block > 2) {
            if (block > 3)
                return WhatsThere::ROCK_STRONG;
            else
                return WhatsThere::ROCK_WEAK;
        }
        return WhatsThere::NONE;
    }

    if (alan.lock()) {
        if (target == alan.lock()->GetComponent<Alan *>()->GetGridPosition())
            return WhatsThere::ALAN;

    } else if (tileMap->At(target.x, target.y, tileMap->Layers::BLOCOS) == 2) {
        if (tileMap->At(target.x, target.y + 1, tileMap->Layers::BLOCOS) == 2) {
            return WhatsThere::FREE_FALL;
        }

        return WhatsThere::FREE;

    } else if (tileMap->At(target.x, target.y, tileMap->Layers::BLOCOS) > 2) {
        return WhatsThere::ROCK_STRONG;
    }

    return WhatsThere::NONE;
}