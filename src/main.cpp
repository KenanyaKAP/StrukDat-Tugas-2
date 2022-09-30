#include <iostream>
#include <set>
#include <SFML/Graphics.hpp>

#include "gameManager.hpp"
#include "entity.hpp"

std::set<Entity*> Entity::entities = std::set<Entity*>();

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    GameManager GameManager;
    GameManager.Start();

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.text.unicode == sf::Keyboard::Escape)
                    window.close();
            default:
                break;
            }

            GameManager.Event(event);
        }

        GameManager.Update(clock.restart().asSeconds());

        window.clear();
        GameManager.Draw(window);
        window.display();
    }

    return 0;
}