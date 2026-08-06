#pragma once
#include "Actor.h"

struct ItemDesc : public nu::ActorDesc {
    float speed;
};

class Item : public nu::Actor {
public:
    Item() = default;
    Item(const ItemDesc& ItemDesc) :
        Actor(ItemDesc),
        m_speed{ ItemDesc.speed }
    {
    }

    void Update(float dt) override;
    void OnCollision(Actor* other) override;

private:
    float m_speed = 1200.0f;

};