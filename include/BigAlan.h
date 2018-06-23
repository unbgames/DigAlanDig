#ifndef BIGALAN_H
#define BIGALAN_H
#include "Component.h"
#include "Sprite.h"

class BigAlan : public Component {
  public:
    enum BAState { TRASH = 0, DECENT, GOOD, STARTER };

    explicit BigAlan(GameObject& associated) : Component(associated) {}

    void Update(float dt);
    void RhythmUpdate() {
        associated.box.y += offset;
        offset = -offset;
    }
    void Render(Common::Layer layer) const {}

  private:
    Sprite::SpriteState state{"assets/img/mood1.png", 1, 1, -1};
    BAState currentState = BAState::STARTER;
    int offset = 0;
};

#endif  // BIGALAN_H
