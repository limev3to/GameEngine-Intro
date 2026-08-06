#include "Player.h"
#include "Bullet.h"
#include "Assets.h"
#include "SpaceGame.h"

#include "Renderer.h"
#include "Engine.h"
#include <iostream>

void Player::Update(float dt) {
    // movement
    float thrust = 0.0f;
    if (nu::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = m_speed;
    if (nu::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = -m_speed;

    float rotate = 0.0f;
    if (nu::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -180.0f;
    if (nu::Engine::Get().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = +180.0f;

    SetRotation(m_transform.rotation + rotate * dt);

    nu::Vector2 forward{ 1, 0 };
    nu::Vector2 velocity = forward.Rotate(m_transform.rotation * nu::DegToRad) * thrust;
    AddVelocity(velocity * dt);

    // particle system
    nu::Particle particle;
    particle.position = m_transform.position;
    particle.color = { 1.0f, 1.0f, 1.0f };
    particle.lifespan = nu::RandomFloat(0.5f, 1.5f);
    particle.velocity = { nu::RandomFloat(-100.0f, 30.0f), nu::RandomFloat(-200.0f, 200.0f) };

    nu::Engine::Get().GetPS().AddParticle(particle);

    isBuffed -= dt;

    // fire
    if (nu::Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_SPACE)) {

        if (isBuffed <= 0) {
            BulletDesc desc;
            desc.name = "Bullet";
            desc.tag = "PlayerBullet";
            desc.model = assets::bulletModel;
            desc.transform = m_transform;
            desc.speed = 1000.0f;
            desc.lifespan = 2.0f;

            Bullet* bullet = new Bullet{ desc };
            m_scene->AddActor(std::move(std::make_unique<Bullet>(desc)));
            nu::Engine::Get().GetAudio().PlaySound("laser");
        } else {
            BulletDesc desc;
            desc.name = "Bullet";
            desc.tag = "PlayerBullet";
            desc.model = assets::bulletModel;
            desc.transform = m_transform;
            desc.speed = 3000.0f;
            desc.lifespan = 3.5f;

            Bullet* bullet = new Bullet{ desc };
            m_scene->AddActor(std::move(std::make_unique<Bullet>(desc)));
            nu::Engine::Get().GetAudio().PlaySound("laser");
        }
    }


    Actor::Update(dt);
}

void Player::OnCollision(Actor* other) {
    if (other->GetTag() == "Enemy") {
        SetDestroyed();
        nu::Engine::Get().GetAudio().PlaySound("explosion");
        ((SpaceGame*)m_scene->GetGame())->OnPlayerDead();
    }

    if (other->GetTag() == "Item") {
        other->SetDestroyed();
        SetBuffed(5.0f);
        nu::Engine::Get().GetAudio().PlaySound("itemPickup");
        ((SpaceGame*)m_scene->GetGame())->AddPoints(150);
    }
}