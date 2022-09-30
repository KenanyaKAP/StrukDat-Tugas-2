#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "mainEntity.hpp"
#include "bullet.hpp"

#define M_PI 3.14159265358979323846

void MainEntity::Start()
{
    setTexture("sprites/plane_anim.png");
    tSize = sf::Vector2f(getTexture().getSize().x/4, getTexture().getSize().y);
    dir = sf::Vector2f(0, -1);
    setTextureRect(sf::IntRect(0, 0, tSize.x, tSize.y));
    setOrigin(tSize.x/2, tSize.y/2);
    vel = 100;
    angle = 0;
    setScale(0.7, 0.7);
}

void MainEntity::Event(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::Space)
            Fire();
}

void MainEntity::Update(float deltaTime)
{
    time += deltaTime;
    stud = (int)(time * 10) % 4;

    vel -= 500 * deltaTime;
    if (vel < 0)
        vel = 0;
    if (vel > 500)
        vel = 500;

    move(dir * deltaTime * vel);

    if (hit)
    {
        switch (stud)
        {
        case 0:
            setColor(sf::Color::Red);
            setScale(0.6, 0.6);
            break;
        case 1:
            setColor(sf::Color::White);
            setScale(0.7, 0.7);
            break;
        case 2:
            setColor(sf::Color::Red);
            setScale(0.6, 0.6);
            break;
        case 3:
            setColor(sf::Color::White);
            setScale(0.7, 0.7);
            break;
        }
        if (time > rec + 1)
        {
            hit = false;
            setColor(sf::Color::White);
            setScale(0.7, 0.7);
        }
    }

    switch (stud)
    {
    case 0:
        setTextureRect(sf::IntRect(0, 0, tSize.x, tSize.y));
        break;
    case 1:
        setTextureRect(sf::IntRect(tSize.x * 1, 0, tSize.x, tSize.y));
        break;
    case 2:
        setTextureRect(sf::IntRect(tSize.x * 2, 0, tSize.x, tSize.y));
        break;
    case 3:
        setTextureRect(sf::IntRect(tSize.x * 3, 0, tSize.x, tSize.y));
        break;
    }

    if (getPosition().x > 1280)
        setPosition(sf::Vector2f(getPosition().x - 1280, getPosition().y));
    if (getPosition().y > 720)
        setPosition(sf::Vector2f(getPosition().x, getPosition().y - 720));
    if (getPosition().x < 0)
        setPosition(sf::Vector2f(getPosition().x + 1280, getPosition().y));
    if (getPosition().y < 0)
        setPosition(sf::Vector2f(getPosition().x, getPosition().y + 720));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        vel += 1000 * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        dir = Rotate(dir, 100 * deltaTime);
        rotate(100 * deltaTime);
        angle += 100 * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        dir = Rotate(dir, -100 * deltaTime);
        rotate(-100 * deltaTime);
        angle -= 100 * deltaTime;
    }
}

sf::Vector2f MainEntity::Rotate(sf::Vector2f v, float f)
{
    sf::Vector2f temp;
    temp.x = (cosf(f * (M_PI / 180)) * v.x + (-sinf(f * (M_PI / 180))) * v.y);
    temp.y = (cosf(f * (M_PI / 180)) * v.y + sinf(f * (M_PI / 180)) * v.x);

    return temp;
}

void MainEntity::OnCollisionEnter(Entity *other)
{
    if (other->isActive() && other->getTag() == "stone")
    {
        other->setActive(false);
        hit = true;
        rec = time;
    }
}

void MainEntity::Fire()
{
    Bullet *bul = new Bullet();
    bul->setPosition(getPosition());
    bul->setTag("bullet");
    bul->dir = dir;
    bul->angle = angle;
    bul->setTexture("sprites/bullet.png");
    bul->setScale(0.03, 0.03);
    bul->setRotation(angle);
}