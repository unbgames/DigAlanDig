#include "GridControl.h"
#include "Alan.h"
#include "Enemy.h"

GridControl *GridControl::_instance = nullptr;

GridControl *GridControl::GetInstance() {
    if (!_instance) _instance = new GridControl();
    return _instance;
}

int GridControl::TestPath(Vec2 target, bool isAlan) {
    if ((target.x >= tileMap->GetWidth() || target.x < 0) ||
        (target.y >= tileMap->GetHeight() || target.y < 0)) {
        return WhatsThere::NONE;
    }

    int block = tileMap->At(target.x, target.y, tileMap->Layers::BLOCOS);

    if (isAlan) {
        if (VerifyEnemy(target)) {
            return WhatsThere::ENEMY;
        } else if (!block) {
            return WhatsThere::FREE;

        } else if (block) {
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
    }

    if (!block) {
        return WhatsThere::FREE;

    } else if (block) {
        return WhatsThere::ROCK_STRONG;
    }

    return WhatsThere::NONE;
}

bool GridControl::VerifyEnemy(Vec2 target) {
    for (auto enemy : enemies) {
        if (enemy->GetComponent<Enemy *>()->GetGridPosition() == target &&
            enemy->GetComponent<Enemy *>()->GetState() == Enemy::State::IDLE_S)
            return true;
    }

    return false;
}
