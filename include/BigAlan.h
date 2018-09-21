#ifndef BIGALAN_H
#define BIGALAN_H
#include "Component.h"
#include "Sprite.h"

class BigAlan : public Component {
  public:
    enum BAState { TRASH = 0, DECENT, GOOD, STARTER, MAXSTATE };

    explicit BigAlan(GameObject &associated) : Component(associated) {
        sprite = associated.GetComponent<Sprite *>();
        state[BAState::STARTER] = {"assets/img/mooda.png", 2, 2, -1};
        state[BAState::GOOD] = {"assets/img/mooda.png", 2, 2, -1};
        state[BAState::DECENT] = {"assets/img/mood2.png", 1, 1, 1};
        state[BAState::TRASH] = {"assets/img/mood3.png", 1, 1, 1};
    }

    void update(float dt);

    void rhythmUpdate()
    {
        associated.box.y += offset;
        offset = -offset;
    }
    
    void render(Common::Layer layer) const {}


  private:
    Sprite::SpriteState state[BAState::MAXSTATE];
    BAState current_state = BAState::STARTER;
    int offset = 0, old_combo = 0;
    Sprite *sprite;
};

class SpriteState {
  public:
    std::string file;
    int frame_count;
    int total_frame_count;
    float frame_time;
};
#endif  // BIGALAN_H
