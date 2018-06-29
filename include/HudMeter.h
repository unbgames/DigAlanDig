#ifndef HUDMETER_H
#define HUDMETER_H
#include <iostream>
#include "Component.h"
#include "Sprite.h"

class HudMeter : public Component {
  public:
    HudMeter(GameObject& associated, const std::string& bgFile,
             const std::string& meterFile);
    ~HudMeter();

    void Update(float dt) {}

    void RhythmUpdate() { hp = (hp >= 7) ? 0 : hp + 1; }
    void Render(Common::Layer layer) const;

    void setLevel(int level);

  private:
    Sprite *bg, *meter;
    Rect boxbg;
    Vec2 offset1;
    Vec2 offset2;

    int hp = 0;

    void setMeter(int i) const;
};

#endif  // HUDMETER_H
