#pragma once
#include <SFML/Graphics.hpp>

class Zombie
{
private:
    // How fast is each zombie type?
    const float BLOATER_SPEED = 40;
    const float CHASER_SPEED = 60;
    const float CRAWLER_SPEED = 20;

    // How tough is each zombie type?
    const float BLOATER_HEALTH = 5;
    const float CHASER_HEALTH = 1;
    const float CRAWLER_HEALTH = 3;

    // Make each zombie vary its speed slightly
    const int MAX_VARIANCE = 30;
    const int OFFSET = 101 - MAX_VARIANCE;

    // Where is the zombie?
    sf::Vector2f m_Position;

    // A sprite for the zombie
    sf::Sprite m_Sprite;

    // How fast can this one run / crawl?
    float m_Speed;

    // How much health does the zombie have?
    float m_Health;

    // Is it still alive?
    bool m_Alive;
public:
    // Handle when a bullet hits a zombie
    bool hit();

    // Find out if the zombie is alive
    bool isAlive();

    // Spawn a new zombie
    void spawn(
        float startX,
        float startY,
        int type,
        int seed);

    // Return a rectanble that is a position
    // in the world
    sf::FloatRect getPosition();

    // Get a copy of the sprite to draw
    sf::Sprite getSprite();

    // Update the zombie each frame
    void update(
        float elapsedTime,
        sf::Vector2f playerLocation);
};