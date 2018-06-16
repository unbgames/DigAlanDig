#include "MiniTileMap.h"
#include <algorithm>
#include "Alan.h"
#include "Camera.h"
#include "Game.h"

MiniTileMap::MiniTileMap(GameObject &associated, TileSet *tileSet,
                         TileMap *tileMap, std::weak_ptr<GameObject> alan)
    : Component(associated), tileMap(tileMap), tileSet(tileSet), alan(alan) {}

MiniTileMap::~MiniTileMap() {}

/*
    Renderiza as camadas do mapa.
*/
void MiniTileMap::Render(Common::Layer layer) const {
    if (!alan.lock()) return;

    int x = associated.box.x;
    int y = associated.box.y;
    int valPos;

    Vec2 alanPos = alan.lock()->GetGridPosition();
    int yMin =
        Camera::pos.y / Game::GetInstance()->GetCurrentState().GetGridSize();

    for (int posY = yMin; posY < tileMap->GetHeight(); posY++) {
        for (int posX = 0; posX < tileMap->GetWidth(); posX++) {
            // Coloca a marmota no minimapa
            valPos = tileMap->At(posX, posY);
            if (alanPos.x == posX && alanPos.y == posY) {
                valPos = 5;
                // Faz a borda o minimapa
            } else if (posY >
                       alan.lock()->GetComponent<Alan *>()->GetMaxPosition() +
                           7) {
                valPos = 1;
            }
            tileSet->RenderTile(valPos, x, y);

            x += tileSet->GetTileWidth();
        }
        x = associated.box.x;
        y += tileSet->GetTileHeight();
    }
}
