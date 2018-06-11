#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <algorithm>
#include <memory>
#include <vector>
#include "Common.h"
#include "Component.h"
#include "Rect.h"

class Component;

class GameObject {
  public:
    explicit GameObject(unsigned int layer = Common::Layer::DEFAULT)
        : layer(layer), isDead(false) {}
    ~GameObject();

    void Update(float dt);
    void RhythmUpdate();
    void RhythmReset();

    void RenderOrder(Common::Layer layer) const;

    bool CanEnd() const;

    bool IsDead() const { return isDead; }
    void RequestDelete() { isDead = true; }
    void AddComponent(Component *cpt);
    void RemoveComponent(Component *cpt);

    void Start();
    void CopyPosition(const GameObject &go);

    double AngleRad() const { return angleDeg * M_PI / 180; }

    template <class T>
    T GetComponent() const {
        for (Component *component : components)
            if (T t = dynamic_cast<T>(component)) return t;

        return nullptr;
    }

    Rect box;
    bool worldReference = true;
    bool fromPlayer = false;
    bool started = false;
    double angleDeg = 0;
    unsigned int layer;

  private:
    std::vector<Component *> components;
    bool isDead;
};

#endif  // GAMEOBJECT_H
