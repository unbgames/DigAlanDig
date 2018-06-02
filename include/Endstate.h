#ifndef ENDSTATE_H
#define ENDSTATE_H
#include "State.h"

class EndState : public State {
  public:
    EndState();
    void LoadAssets();
    void Update(float dt);
    void RhythmUpdate() {}
    void Render() const;
    void Start();
    void Pause() {}
    void Resume() {}
};

#endif  // ENDSTATE_H
