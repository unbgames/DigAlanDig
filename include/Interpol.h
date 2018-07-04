#ifndef INTERPOL_H
#define INTERPOL_H

#include <iostream>
#include <string>
#include "Component.h"
#include "Vec2.h"

class Interpol : public Component {
  public:
    explicit Interpol(GameObject &associated);

    void Update(float dt);
    void RhythmUpdate() {}
    void RhythmReset() {}
    void Render(Common::Layer layer) const {}
    void Start() {}

    void IsHit(Vec2 target) {
        alanPos = target;
        isHit = true;
    }

    bool IsMovementDone() { return movementDone; }

  private:
    Vec2 alanPos;
    bool movementDone = true;
    bool isHit = false;
    Vec2 speed;
};

#endif  // INTERPOL_H
