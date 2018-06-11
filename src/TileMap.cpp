#include "TileMap.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include "Camera.h"
#include "Common.h"
#include "json.hpp"

using json = nlohmann::json;

TileMap::~TileMap() {}

void TileMap::TileMapGenerator() { return; }

void TileMap::Load(const std::string &file) {
    char *data = Common::file_read(file.c_str());
    if (data == nullptr) exit(0);

    json test = json::parse(data, data + strlen(data));
    free(data);
    // test.
    width = test.at("width");
    height = test.at("height");
    depth = test.at("layers").size();

    for (int i = 0; i < depth; i++)
        tileMat.push_back(test.at("layers").at(i).at("data"));
}

inline int inRange(int value, int min, int max) {
    return (value < min) ? min : ((value > max) ? max : value);
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY) const {
    int w = tileSet->GetTileWidth();
    int h = tileSet->GetTileHeight();

    // Optimization, for only drawing what is on screen
    int cinit = cameraX / w;
    int cmax = cinit + ceil(Camera::screenSize.x / (double)w) + 1;
    cinit = inRange(cinit, 0, width);
    cmax = inRange(cmax, 0, width);

    int linit = cameraY / h;
    int lmax = linit + ceil(Camera::screenSize.y / (double)h) + 1;
    linit = inRange(linit, 0, height);
    lmax = inRange(lmax, 0, height);

    for (int line = linit; line < lmax; ++line)
        for (int col = cinit; col < cmax; ++col)
            tileSet->RenderTile(tileMat[layer][line * width + col],
                                col * w - cameraX, line * h - cameraY);
}

int TileMap::At(int x, int y, int z) const {
    bool valid = (x >= 0) && (x < width) && (y >= 0) && (y < height) &&
                 (z >= 0) && (z < depth);
    return (valid) ? tileMat[z][y * width + x] : 1;
}

void TileMap::Render() const {
    for (int i = 0; i < depth; ++i)
        RenderLayer(i, Camera::pos.x, Camera::pos.y);
}

void TileMap::GetDamageGround(int damage, Vec2 posDamage) {
    int valPos = At(posDamage.x, posDamage.y);
    if (valPos == 1) return;

    if (--tileMat[groundLayer][(int)(posDamage.y * width + posDamage.x)] < 2)
        tileMat[groundLayer][(int)(posDamage.y * width + posDamage.x)] = 2;
    // tileSet->RenderTile(valPos - 1, posDamage.x, posDamage.y);
}
