#include "GameObject.h"
#include "Sound.h"

bool GameObject::CanEnd() const { return true; }

GameObject::~GameObject() {
    for (Component* component : components) delete (component);

    components.clear();
}

void GameObject::Update(float dt) {
    for (Component* component : components) component->Update(dt);
}

void GameObject::RhythmUpdate() {
    for (Component* component : components) component->RhythmUpdate();
}

void GameObject::RhythmReset() {
    for (Component* component : components) component->RhythmReset();
}

void GameObject::RenderOrder(Common::Layer layer) const {
    if (this->layer != layer) return;

    for (Component* component : components) component->Render();
}

void GameObject::NotifyCollision(std::shared_ptr<GameObject> other) {
    for (Component* component : components) component->NotifyCollision(other);
}

void GameObject::RemoveComponent(Component* cpt) {
    components.erase(std::remove(components.begin(), components.end(), cpt),
                     components.end());
}

void GameObject::AddComponent(Component* cpt) { components.emplace_back(cpt); }

void GameObject::CopyPosition(const GameObject& go) {
    box = go.box;
    worldReference = go.worldReference;
    fromPlayer = go.fromPlayer;
    angleDeg = go.angleDeg;
}

void GameObject::Start() {
    if (started) return;
    for (auto c : components) c->Start();

    started = true;
}
