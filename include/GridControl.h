#ifndef GRIDCONTROL_H
#define GRIDCONTROL_H

#include <iostream>
#include <string>
#include <vector>
#include "TileMap.h"
#include "Vec2.h"

class GridControl {
  public:
    ~GridControl() {}

    static GridControl &GetInstance() { return *_instance; }
    static GridControl &GetInstance(TileMap *tileMap);

    void SetAlanPos(Vec2 *alanPos) { alanPosition = alanPos; }

  private:
    Vec2 *alanPosition;
    std::vector<Vec2 *> enemyPosition;
    std::vector<Vec2 *> itemPosition;
    TileMap *tileMap;
    static GridControl *_instance;

    GridControl(TileMap *tileMap) : tileMap(tileMap) {}
};

#endif  // GRIDCONTROL_H