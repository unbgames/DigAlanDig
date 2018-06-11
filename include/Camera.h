#ifndef CAMERA_H
#define CAMERA_H
#include "GameObject.h"
#include "Vec2.h"

class Camera {
  public:
    static void Follow(GameObject* newFocus);
    static void Unfollow();
    static void Update(float dt);
    static Vec2 Center();
    static void Shake(int intensity = 4, float duration = 0.1);

    static Vec2 pos, speed, screenSize, offset;

  private:
    static GameObject* focus;
    static Vec2 shake;
    static int shakeIntensity;
    static float shakeDuration;
};

#endif  // CAMERA_H
