#ifndef GRIDCONTROL_H
#define GRIDCONTROL_H

#include <iostream>
#include <string>
#include <vector>
#include "Component.h"
#include "TileMap.h"
#include "Vec2.h"

class GridControl {
  public:
    static GridControl *GetInstance();

    void SetAlan(std::weak_ptr<GameObject> alan) { this->alan = alan; }
    void SetTileMap(TileMap *tileMap) { this->tileMap = tileMap; }
    int TestPath(Vec2 target, bool isAlan);

    std::weak_ptr<GameObject> GetAlan() { return alan; }

    enum WhatsThere {
        NONE = 0,
        FREE,
        FREE_FALL,
        ENEMY,
        ALAN,
        ROCK_WEAK,
        ROCK_STRONG
    };

  private:
    std::weak_ptr<GameObject> alan;
    TileMap *tileMap;
    static GridControl *_instance;

    GridControl() {}
};
#endif  // GRIDCONTROL_H