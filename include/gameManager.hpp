#pragma once
#include <SFML/Graphics.hpp>

#include "mainEntity.hpp"

class GameManager
{
private:
    MainEntity *mainEntity;

public:
    GameManager();
    ~GameManager();
    void Start();
    void Event(const sf::Event &);
    void Update(const float &);
    void Draw(sf::RenderWindow &);
};