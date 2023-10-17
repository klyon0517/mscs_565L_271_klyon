#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
    // Where is the bullet?
    sf::Vector2f m_Position;

    // What each bullet looks like
    sf::RectangleShape m_BulletShape;

    // Is the bullet currenlty whizzing thru the air?
    bool m_InFlight = false;

    // How fast does a bullet travel?
    float m_BulletSpeed = 1000;

    // What fraction of 1 pixel does the bullet travel,
    // horizontally and vertically each frame?
    // These values will be derived from m_BulletSpeed
    float m_BulletDistanceX;
    float m_BulletDistanceY;

    // Some boundaries so the bullet doesn't fly forever
    float m_MaxX;
    float m_MinX;
    float m_MaxY;
    float m_MinY;

public:
    // The constructor
    Bullet();

    // Stop the bullet
    void stop();

    // Return the value of m_InFlight
    bool isInFlight();

    // Launch a new bullet
    void shoot(
        float startX,
        float startY,
        float targetX,
        float targetY);

    // Tell the calling code where the
    // bullet is in the world
    sf::FloatRect getPosition();

    // Return the actual shape (for drawing)
    sf::RectangleShape getShape();

    // Update the bullet each frame
    void update(float elapsedTime);
};
