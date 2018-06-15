#include "GridControl.h"

GridControl *GridControl::_instance = nullptr;

GridControl &GridControl::GetInstance(TileMap *tileMap) {
    if (!_instance) _instance = new GridControl(tileMap);
    return *_instance;
}