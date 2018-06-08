#ifndef TILESET_H
#define TILESET_H
#define INCLUDE_SDL
#include "SDL_include.h"

#include <string>

class TileSet {
  public:
    TileSet(int tileWidth, int tileHeight, const std::string& file);

    void RenderTile(unsigned index, float x, float y) const;
    int GetTileWidth() const { return tileWidth; }
    int GetTileHeight() const { return tileHeight; }

  private:
    SDL_Texture* tileSet;

    int rows, columns;
    const int tileWidth, tileHeight;
};

#endif  // TILESET_H
