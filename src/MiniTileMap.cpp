#include "MiniTileMap.h"

MiniTileMap::MiniTileMap(GameObject &associated, TileSet *tileSet,
                         TileMap *tileMap, Alan *alan)
    : Component(associated), tileMap(tileMap), tileSet(tileSet), alan(alan) {}

MiniTileMap::~MiniTileMap() {}

void MiniTileMap::RenderLayer(int initX, int initY) {}

/*
    Renderiza as camadas do mapa.
*/
void MiniTileMap::Render() {
    int x = associated.box.x;
    int y = associated.box.y;
    int valPos;
    Vec2 alanPos = alan->GetGridPosition();

    for (int posY = 0; posY < tileMap->GetHeight(); posY++) {
        for (int posX = 2; posX < tileMap->GetWidth() - 2; posX++) {
            // Coloca a marmota no minimapa
            if (alanPos.x == posX && alanPos.y == posY) {
                valPos = 4;
                // Faz a borda o minimapa
            } else if (tileMap->At(posX, posY) == 0) {
                valPos = 2;
                // Interior do minimapa
            } else {
                valPos = 0;
            }
            tileSet->RenderTile(valPos, x, y);

            x += tileSet->GetTileWidth();
        }
        x = associated.box.x;
        y += tileSet->GetTileHeight();
    }
}

void MiniTileMap::Update(float dt) {}

bool MiniTileMap::Is(std::string type) {
    return strcmp(type.c_str(), "MiniTileMap") == 0;
}
