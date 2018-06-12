#ifndef PARALLAX_H
#define PARALLAX_H
#include "Camera.h"
#include "Component.h"

class Parallax : public Component {
  public:
    Parallax(GameObject& associated, float factor = 1)
        : Component(associated), factor(factor) {}

    void Update(float dt) { associated.box.pos.y = -Camera::pos.y * factor; }
    void RhythmUpdate() {}
    void Render(Common::Layer layer) const {}

  private:
    float factor;
};

class bgCircularY : public Component {
  public:
    bgCircularY(GameObject& associated, const std::string& file)
        : Component(associated) {
        Open(file);
    }

    void Open(const std::string& file);
    void Update(float dt) {}
    void RhythmUpdate() {}
    void Render(Common::Layer layer) const;

  private:
    std::shared_ptr<SDL_Texture> texture = nullptr;
    int width = 0, height = 0;
};
#endif  // PARALLAX_H
