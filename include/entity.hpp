#pragma once
#include <iostream>
#include <set>
#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite
{
    friend class GameManager;
    static std::set<Entity *> entities;

private:
    std::string name;
    std::string tag;
    bool active;
    std::set<Entity *> collidedEntity;
    sf::Texture texture;

public:

protected:
    virtual void Start();
    virtual void Event(const sf::Event &);
    virtual void Update(float);
    virtual void OnCollisionEnter(Entity *);
    virtual void OnCollisionStay(Entity *);
    virtual void OnCollisionExit(Entity *);

public:
    Entity();
    virtual ~Entity();
    void Destroy();
    void setActive(const bool &b);
    void setTexture(const std::string &);
    void setTag(const std::string &);
    bool isActive();
    std::string getName();
    std::string getTag();
    sf::Texture getTexture();
};