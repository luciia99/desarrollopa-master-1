#pragma once
#include <vector>
#include <string>
#include "Level.h"

class SceneManager {
private:
    std::vector<Level*> levels;
    int currentIndex;
public:
    SceneManager() : currentIndex(-1) {}
    ~SceneManager() {
        for (Level* l : levels) {
            delete l; 
        }
        levels.clear();
    }
    void AddLevel(Level* l) { levels.push_back(l); if (currentIndex < 0) currentIndex = 0; }
    Level* GetCurrentLevel() const { if (currentIndex >= 0 && currentIndex < (int)levels.size()) return levels[currentIndex]; return nullptr; }
    void NextLevel() { if (currentIndex + 1 < (int)levels.size()) currentIndex++; }
    void SetCurrentIndex(int i) { if (i >= 0 && i < (int)levels.size()) currentIndex = i; }
    int GetCurrentIndex() const { return currentIndex; }
    size_t Count() const { return levels.size(); }

    void UpdateCurrent(const float& time) {
        Level* l = GetCurrentLevel();
        if (l) l->Update(time);
    }

    Level* GetCurrent() const { return GetCurrentLevel(); }
};
