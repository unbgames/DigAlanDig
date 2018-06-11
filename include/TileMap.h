#ifndef TILEMAP_H
#define TILEMAP_H
#include <string>
#include "Component.h"
#include "TileSet.h"

class TileMap : public Component {
  public:
    TileMap(GameObject& associated, const std::string& file)
        : Component(associated) {
        Load(file);
    }
    ~TileMap();

    void Load(const std::string& file);
    void SetTileSet(TileSet* tileSet) { this->tileSet = tileSet; }
    int At(int x, int y, int z = 0) const;

    void Update(float dt) {}
    void RhythmUpdate() {}
    void Render(Common::Layer layer) const;

    void RenderLayer(int layer, int cameraX = 0, int cameraY = 0) const;

    int GetWidth() const { return width; }
    int GetHeight() const { return height; }
    int GetDepth() const { return depth; }

    void GetDamageGround(int damage, Vec2 posDamage);

  private:
    std::vector<std::vector<int>> tileMat;
    TileSet* tileSet;
    int width, height, depth;
    const int groundLayer = 0;
};

#endif  // TILEMAP_H
