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

    Item(float speed, const nu::Transform& transform) :
        Actor{ transform },
        m_speed{ speed }
    {
    }

    Item(float speed, const nu::Transform& transform, const nu::Model& model) :
        Actor{ transform, model },
        m_speed{ speed }
    {
    }

    void Update(float dt) override;
    void OnCollision(Actor* other) override;

private:
    float m_speed = 1200.0f;

};