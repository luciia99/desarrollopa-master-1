#pragma once
#include "Scene.h"
#include <string>

class Level {
private:
    Scene* scene;
    std::string name;
    bool completed;
    bool failed;
public:
    Level(const std::string& n, Scene* s) : scene(s), name(n), completed(false), failed(false) {}
    Scene* GetScene() const { return scene; }
    const std::string& GetName() const { return name; }

    void SetCompleted(bool v) { completed = v; }
    bool IsCompleted() const { return completed; }

    void SetFailed(bool v) { failed = v; }
    bool IsFailed() const { return failed; }

    // Actualiza la escena 
    void Update(const float& time) {
        if (scene) scene->Update(time);
    }
};
