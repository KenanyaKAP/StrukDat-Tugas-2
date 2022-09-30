#include <iostream>
#include <set>
#include <SFML/Graphics.hpp>

#include "entity.hpp"

void Entity::Start()
{

}

void Entity::Event(const sf::Event &)
{

}

void Entity::Update(float)
{

}

void Entity::OnCollisionEnter(Entity *)
{

}

void Entity::OnCollisionStay(Entity *)
{

}

void Entity::OnCollisionExit(Entity *)
{

}

Entity::Entity()
{
    Entity::entities.insert(this);
    this->name = "entity_" + std::to_string(Entity::entities.size());

    active = false;
}

Entity::~Entity()
{

}

void Entity::Destroy()
{
    Entity::entities.erase(this);
    delete this;
}

void Entity::setActive(const bool &b)
{
    this->active = b;
}

void Entity::setTexture(const std::string &filename)
{
    this->active = true;
    this->texture.loadFromFile(filename);
    sf::Sprite::setTexture(this->texture);
}

void Entity::setTag(const std::string &tag)
{
    this->tag = tag;
}

bool Entity::isActive()
{
    return this->active;
}

std::string Entity::getName()
{
    return this->name;
}

std::string Entity::getTag()
{
    return this->tag;
}

sf::Texture Entity::getTexture()
{
    return this->texture;
}