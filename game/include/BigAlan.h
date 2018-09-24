#ifndef BIGALAN_H
#define BIGALAN_H
#include "Component.h"
#include "Sprite.h"
#include "config.h"

class BigAlan : public Component {
  public:
    enum BAState { TRASH = 0, DECENT, GOOD, STARTER, MAXSTATE };

    explicit BigAlan(GameObject &associated) : Component(associated) {
        sprite = associated.GetComponent<Sprite *>();
        state[BAState::STARTER] = {ASSETS_PATH("/img/mooda.png"), 2, 2, -1};
        state[BAState::GOOD] = {ASSETS_PATH("/img/mooda.png"), 2, 2, -1};
        state[BAState::DECENT] = {ASSETS_PATH("/img/mood2.png"), 1, 1, 1};
        state[BAState::TRASH] = {ASSETS_PATH("/img/mood3.png"), 1, 1, 1};
    }

    void Update(float dt);
    void RhythmUpdate() {
        associated.box.y += offset;
        offset = -offset;
    }
    void Render(Common::Layer layer) const {}


  private:
    Sprite::SpriteState state[BAState::MAXSTATE];
    BAState currentState = BAState::STARTER;
    int offset = 0, oldCombo = 0;
    Sprite *sprite;
};

class SpriteState {
  public:
    std::string file;
    int frameCount;
    int totalFrameCount;
    float frameTime;
};
#endif  // BIGALAN_H
