#ifndef LIGHT_H
#define LIGHT_H
#include "Common.h"
#include "Component.h"
#include "Sprite.h"

class Light : public Component {
  public:
    Light(GameObject& associated)
        : Component(associated),
          box(associated.box),
          sprite(new Sprite(associated, "assets/img/light.png")) {
        sprite->SetBlendMode(SDL_BLENDMODE_ADD);
        associated.box = box;
    }
    void Open(const std::string& file);

    ~Light() { delete sprite; };

    void Update(float dt) { sprite->Update(dt); }

    void RhythmUpdate() {}
    void Render() const {}
    bool Is(const std::string& type) const { return !type.compare("Light"); }

    void RenderOrder(Common::Layer layer) const {
        if (layer == Common::Layer::LIGHT) {
            box = associated.box;
            associated.box.size = {400, 400};
            associated.box.SetCenter(box.Center());
            sprite->Render();
            associated.box = box;
        }
    }

  private:
    mutable Rect box;
    Sprite* sprite;
};

#endif  // LIGHT_H
