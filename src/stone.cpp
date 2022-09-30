#include <iostream>
#include <SFML/Graphics.hpp>

#include "stone.hpp"

void Stone::Start()
{
    setTag("stone");
    setTexture("sprites/stone.png");
    setTextureRect(sf::IntRect(rand()%8 * getTexture().getSize().x/8, rand()%8 * getTexture().getSize().x/8, getTexture().getSize().x/8, getTexture().getSize().x/8));
    setOrigin(getTexture().getSize().x/16, getTexture().getSize().x/16);
    setPosition(rand()%1280, rand()%720);

    vel = sf::Vector2f(((rand() % 2 == 0) ? 1 : -1) * (rand()%100 + 10), ((rand() % 2 == 0) ? 1 : -1) * (rand()%100 + 10));
}

void Stone::Update(float deltaTime)
{
    move(vel * deltaTime);

    if (getPosition().x > 1280)
        setPosition(sf::Vector2f(getPosition().x - 1280, getPosition().y));
    if (getPosition().y > 720)
        setPosition(sf::Vector2f(getPosition().x, getPosition().y - 720));
    if (getPosition().x < 0)
        setPosition(sf::Vector2f(getPosition().x + 1280, getPosition().y));
    if (getPosition().y < 0)
        setPosition(sf::Vector2f(getPosition().x, getPosition().y + 720));
}

void Stone::OnCollisionEnter(Entity *other)
{
    
}