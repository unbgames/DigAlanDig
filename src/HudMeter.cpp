#include "HudMeter.h"

HudMeter::HudMeter(GameObject& associated, const std::string& bgFile,
                   const std::string& meterFile)
    : Component(associated) {
    bg = new Sprite(associated, bgFile);
    boxbg = associated.box;

    meter = new Sprite(associated, meterFile, 3, 1e9);
    Rect meterBox = associated.box;

    int margin = 50 - meterBox.w;
    Rect internalBox = boxbg;
    internalBox.w -= 2 * margin;

    offset1.y = (boxbg.h - meterBox.h) / 2.0;
    offset1.x = margin;

    offset2 = {(internalBox.w - associated.box.w) / 2, 0};
}

HudMeter::~HudMeter() {
    delete bg;
    delete meter;
}

void HudMeter::Render(Common::Layer layer) const {
    associated.box = boxbg;
    bg->Render(layer);

    associated.box += offset1;

    for (int i = 0; i < 3; i++) {
        setMeter(i);
        meter->Render(layer);
        associated.box += offset2;
    }
}

void HudMeter::setMeter(int i) const {
    int tmp = hp - i * 2;
    if (tmp >= 2)
        meter->SetFrame(2);
    else if (tmp == 1)
        meter->SetFrame(1);
    else
        meter->SetFrame(0);
}
