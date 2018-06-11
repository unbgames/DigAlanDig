#include "MiniTileMap.h"
#include <algorithm>

MiniTileMap::MiniTileMap(GameObject &associated, TileSet *tileSet,
                         TileMap *tileMap, Alan *alan)
    : Component(associated), tileMap(tileMap), tileSet(tileSet), alan(alan) {}

MiniTileMap::~MiniTileMap() {}

void MiniTileMap::RenderLayer(int initX, int initY) {}

/*
    Renderiza as camadas do mapa.
*/
void MiniTileMap::Render(Common::Layer layer) const {
    int x = associated.box.x;
    int y = associated.box.y;
    int valPos;
    Vec2 alanPos = alan->GetGridPosition();

    for (int posY = 0; posY < tileMap->GetHeight(); posY++) {
        for (int posX = 0; posX < tileMap->GetWidth(); posX++) {
            // Coloca a marmota no minimapa
            valPos = tileMap->At(posX, posY);
            if (alanPos.x == posX && alanPos.y == posY) {
                valPos = 5;
                // Faz a borda o minimapa
            } else if (posY > std::max(alanPos.y + 4, 7.0)) {
                valPos = 4;
            }
            tileSet->RenderTile(valPos, x, y);

            x += tileSet->GetTileWidth();
        }
        x = associated.box.x;
        y += tileSet->GetTileHeight();
    }
}
