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
  private:
    TileMap *tileMap;
    TileSet *tileSet;
    Alan *alan;
    int mapWidth;
    int mapHeight;

  public:
    MiniTileMap(GameObject &associated, TileSet *tileSet, TileMap *tileMap,
                Alan *alan);

    ~MiniTileMap();

    void RenderLayer(int posX, int posY);

    void Render();

    void Update(float dt);

    bool Is(std::string type);
};

#endif  // MINITILEMAP
