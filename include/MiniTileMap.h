#ifndef MINITILEMAP
#define MINITILEMAP
#define INCLUDE_SDL_IMAGE
#include <iostream>
#include <string>
#include <vector>
#include "Alan.h"
#include "Component.h"
#include "SDL_include.h"
#include "TileMap.h"
#include "TileSet.h"

class MiniTileMap : public Component {
  public:
    MiniTileMap(GameObject &associated, TileSet *tileSet, TileMap *tileMap,
                Alan *alan);

    ~MiniTileMap();

    void RenderLayer(int posX, int posY);

    void Update(float dt) {}
    void RhythmUpdate() {}
    void Render() const;
    bool Is(const std::string &type) const {
        return !type.compare("MiniTileMap");
    }

  private:
    TileMap *tileMap;
    TileSet *tileSet;
    Alan *alan;
};

#endif  // MINITILEMAP
