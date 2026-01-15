#pragma once

class ScoreManager {
private:
    int score;
public:
    ScoreManager() : score(0) {}
    void Add(int v) { if (v > 0) score += v; }
    int GetScore() const { return score; }
    void Reset() { score = 0; }
};
