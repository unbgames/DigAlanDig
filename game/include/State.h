#ifndef STATE_H
#define STATE_H
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <vector>
#include "GameObject.h"
#include "InputManager.h"
#include "Music.h"
#include "TileMap.h"
#include "TileSet.h"

class State {
  public:
    State();
    virtual ~State() {
        music.Stop();
        objectArray.clear();
    }

    virtual void LoadAssets() = 0;
    virtual void Update(float dt) = 0;
    virtual void RhythmUpdate() = 0;
    virtual void RhythmReset() {}
    virtual void Render() const = 0;

    virtual void Start() = 0;
    virtual void Pause() = 0;
    virtual void Resume() = 0;

    void UpdateArray(float dt);
    void RhythmUpdateArray();
    void RhythmResetArray();
    void StartArray();
    void RenderArray() const;

    virtual std::weak_ptr<GameObject> AddObject(GameObject* go);
    virtual std::weak_ptr<GameObject> GetObjectPrt(GameObject* go);

    bool PopRequested() const { return popRequested; }
    bool QuitRequested() const { return quitRequested; }

    TileMap* tileMap = nullptr;

    Music* GetMusic() { return &music; }

    void StopMusic() { musicPlaying = false; }

    int GetGridSize() const { return gridSize; }

  protected:
    const int gridSize = 100;

    bool popRequested = false;
    bool quitRequested = false;
    bool started = false;

    std::vector<std::shared_ptr<GameObject>> objectArray;

    InputManager& input;
    Music music;
    bool musicPlaying = false;
    TileSet* tileSet = nullptr;

  private:
    void RenderLight() const;
};

#endif
