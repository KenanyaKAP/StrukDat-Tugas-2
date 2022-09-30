#include <iostream>
#include <set>
#include <SFML/Graphics.hpp>

#include "gameManager.hpp"
#include "entity.hpp"
#include "mainEntity.hpp"
#include "stone.hpp"

GameManager::GameManager()
{
    
}

GameManager::~GameManager()
{
    for (Entity *e : Entity::entities)
    {
        std::cout << e << std::endl;
        delete e;
    }
}

void GameManager::Start()
{
    this->mainEntity = new MainEntity();
    new Stone();
    new Stone();
    new Stone();
    new Stone();
    new Stone();
    new Stone();
    
    for (Entity *e : Entity::entities)
    {
        e->Start();
    }
}

void GameManager::Event(const sf::Event &event)
{
    for (Entity *e : Entity::entities)
    {
        e->Event(event);
    }
}

void GameManager::Update(const float &deltaTime)
{
    for (Entity *e1 : Entity::entities)
    {
        for (Entity *e2 : Entity::entities)
        {
            if (e1 != e2)
            {
                if (e1->getGlobalBounds().intersects(e2->getGlobalBounds()))
                {
                    if (e1->collidedEntity.find(e2) == e1->collidedEntity.end())
                    {
                        e1->OnCollisionEnter(e2);
                        e1->collidedEntity.insert(e2);
                    }
                    e1->OnCollisionStay(e2);
                }
                else
                {
                    if (e1->collidedEntity.find(e2) != e1->collidedEntity.end())
                    {
                        e1->OnCollisionExit(e2);
                        e1->collidedEntity.erase(e2);
                    }
                }
            }
        }

        e1->Update(deltaTime);
    }
}

void GameManager::Draw(sf::RenderWindow &window)
{
    for (Entity *e : Entity::entities)
    {
        if (e->active)
        {
            window.draw(*e);
        }
    }
}