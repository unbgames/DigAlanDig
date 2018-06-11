#ifndef LIGHT_H
#define LIGHT_H
#include "Common.h"
#include "Component.h"
#include "Sprite.h"

class Light : public Component {
  public:
    Light(GameObject& associated, GameObject* follow)
        : Component(associated),
          follow(follow),
          sprite(new Sprite(associated, "assets/img/light.png")) {
        sprite->SetBlendMode(SDL_BLENDMODE_ADD);
        sprite->SetColor(255, 255, 255 * 0.8);
        SetSize(600);
    }

    ~Light() { delete sprite; }

    void Update(float dt) {
        associated.box.SetCenter(follow->box.Center());
        sprite->Update(dt);
    }

    void RhythmUpdate() {}
    void Render(Common::Layer layer) const { sprite->Render(layer); }

    void SetSize(int size) {
        sprite->SetScaleX((double)size / sprite->GetHeight());
    }

    int GetSize() { return sprite->GetScale().x * sprite->GetHeight(); }

  private:
    GameObject* follow;
    Sprite* sprite;
};

#endif  // LIGHT_H
