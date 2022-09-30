#pragma once

#include "entity.hpp"

class Stone : public Entity
{
private:
    sf::Vector2f vel;
public:
    void Start() override;
    // void Event(const sf::Event &) override;
    void Update(float) override;
    void OnCollisionEnter(Entity *) override;
    // void OnCollisionStay(Entity *) override;
    // void OnCollisionExit(Entity *) override;
};