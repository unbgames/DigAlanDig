#ifndef INTERPOL_H
#define INTERPOL_H

#include <iostream>
#include <string>
#include "Component.h"
#include "Vec2.h"

class Interpol : public Component {
  public:
    Interpol(GameObject &associated);

    void Update(float dt);
    void RhythmUpdate() {}
    void RhythmReset() {}
    void Render(Common::Layer layer) const {}
    void Start() {}

    bool AttPosition(Vec2 newPos);

  private:
    Vec2 speed;
};

#endif  // INTERPOL_H