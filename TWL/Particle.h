#pragma once
#include <SFML/Graphics.hpp>

class Particle
{
private:
    sf::Vector2f m_Position;
    sf::Vector2f m_Velocity;

public:
    Particle(sf::Vector2f direction);
    void update(float dt);
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
};