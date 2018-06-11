#include "TileSet.h"
#include "Common.h"
#include "Game.h"

TileSet::TileSet(const std::string& file) {
    json j;
    Common::read_Json(j, file);

    std::string imgFile = j.at("image");
    imgFile.replace(imgFile.begin(), imgFile.begin() + 3, "assets/");
    tileSet_d = Resources::GetImage(imgFile);
    imgFile.replace(imgFile.end() - 4, imgFile.end() - 4, "_light");
    tileSet_l = Resources::GetImage(imgFile);
    SDL_SetTextureBlendMode(tileSet_l.get(), SDL_BLENDMODE_ADD);
    setTileSetDefault();

    tileHeight = j.at("tileheight");
    tileWidth = j.at("tilewidth");

    int width, height;
    SDL_QueryTexture(tileSet, nullptr, nullptr, &width, &height);
    columns = width / tileWidth;
    rows = height / tileHeight;

    if (width != j.at("imagewidth") || height != j.at("imageheight")) {
        std::cout << "Tileset mismatch" << std::endl;
        exit(EXIT_SUCCESS);
    }
}

void TileSet::RenderTile(unsigned index, float x, float y) const {
    if (index == 0) return;
    /*Tiled index starts at 1*/
    index--;
    if ((int)index >= (rows * columns)) {
        std::cerr << "Tile is out of range" << std::endl;
        exit(EXIT_SUCCESS);
    }

    SDL_Rect pos = {(int)x, (int)y, tileWidth, tileHeight};
    SDL_Rect clip = {tileWidth * ((int)index % columns),
                     tileHeight * ((int)index / columns), tileWidth,
                     tileHeight};

    SDL_RenderCopy(Game::GetInstance()->GetRenderer(), tileSet, &clip, &pos);
}
