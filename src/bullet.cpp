#include <iostream>
#include <SFML/Graphics.hpp>
#include "bullet.hpp"

void Bullet::Start()
{
    setTexture("sprites/bullet.png");
    std::cout << "B" << std::endl;
}

void Bullet::Update(float deltaTime)
{
    move(dir * 1000.f * deltaTime);

    if (getPosition().x > 1280)
        Destroy();
    if (getPosition().y > 720)
        Destroy();
    if (getPosition().x < 0)
        Destroy();
    if (getPosition().y < 0)
        Destroy();
}

void Bullet::OnCollisionEnter(Entity *other)
{
    if (other->getTag() == "stone" && isActive() && other->isActive())
    {
        setActive(false);
        other->setActive(false);
    }
}