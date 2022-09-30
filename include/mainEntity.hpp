#pragma once

#include "entity.hpp"

class MainEntity : public Entity
{
private:
    sf::Vector2f tSize;
    sf::Vector2f dir;
    float angle;
    float vel;
    float time;
    float rec;
    bool hit;
    int stud = 0;

    sf::Vector2f Rotate(sf::Vector2f, float);
    void Fire();
public:
    void Start() override;
    void Event(const sf::Event &) override;
    void Update(float) override;
    void OnCollisionEnter(Entity *) override;
    // void OnCollisionStay(Entity *) override;
    // void OnCollisionExit(Entity *) override;
};