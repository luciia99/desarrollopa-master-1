#pragma once
#include "Entity.h"

class Item : public Entity {
private:
    int value;
public:
    Item() : Entity(), value(1) {}
    void SetValue(int v) { value = v; }
    int GetValue() const { return value; }

    virtual void Update(const float& time, const Vector3D& gravity) override {
        Entity::Update(time, gravity);
    }
    virtual void Render() override {}
    virtual Solid* Clone() override { return new Item(*this); }
    virtual ~Item() {}
};
