#include "MiniTileMap.h"

MiniTileMap::MiniTileMap(GameObject &associated, TileSet *tileSet,
                         TileMap *tileMap, Alan *alan)
    : Component(associated), tileMap(tileMap), tileSet(tileSet), alan(alan) {}

MiniTileMap::~MiniTileMap() {}

void MiniTileMap::RenderLayer(int initX, int initY) {}

/*
    Renderiza as camadas do mapa.
*/
void MiniTileMap::Render() const {
    int x = associated.box.x;
    int y = associated.box.y;
    int valPos;
    Vec2 alanPos = alan->GetGridPosition();

    for (int posY = -1; posY < tileMap->GetHeight() + 1; posY++) {
        for (int posX = -1; posX < tileMap->GetWidth() + 1; posX++) {
            // Coloca a marmota no minimapa
            valPos = tileMap->At(posX, posY);
            if (alanPos.x == posX && alanPos.y == posY) {
                valPos = 5;
                // Faz a borda o minimapa
            }
            tileSet->RenderTile(valPos, x, y);

            x += tileSet->GetTileWidth();
        }
        x = associated.box.x;
        y += tileSet->GetTileHeight();
    }
}
