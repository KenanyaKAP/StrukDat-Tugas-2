#pragma once
#include <SFML/Graphics.hpp>

#include "entity.hpp"

class Bullet : public Entity
{
private:
    
public:
    sf::Vector2f dir = sf::Vector2f(0, -1);
    float angle = 0;
    void Start() override;
    void Update(float) override;
    void OnCollisionEnter(Entity *) override;
};