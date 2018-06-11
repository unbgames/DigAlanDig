#ifndef TILESET_H
#define TILESET_H
#include <memory>
#define INCLUDE_SDL
#include "SDL_include.h"

#include <string>

class TileSet {
  public:
    TileSet(const std::string& file);

    void RenderTile(unsigned index, float x, float y) const;
    int GetTileWidth() const { return tileWidth; }
    int GetTileHeight() const { return tileHeight; }

  private:
    std::shared_ptr<SDL_Texture> tileSet = nullptr;

    int rows = 0, columns = 0;
    int tileWidth = 100, tileHeight = 100;
};

#endif  // TILESET_H
