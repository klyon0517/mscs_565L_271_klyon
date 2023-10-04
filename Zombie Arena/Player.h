#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
    const float START_SPEED = 200;
    const float START_HEALTH = 100;

    // Where is the player
    sf::Vector2f m_Position;

    // Player sprite
    sf::Sprite m_Sprite;

    // Add a texture
    sf::Texture m_Texture;

    // Screen resolution
    sf::Vector2f m_Resolution;

    // Current arena
    sf::IntRect m_Arena;

    // Size of arena tile
    int m_TileSize;

    // Player movement & speed
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_LeftPressed;
    bool m_RightPressed;

    // Player health
    int m_Health;

    // Maximum player health
    int m_MaxHealth;

    // When was the player last hit
    sf::Time m_LastHit;

    // Speed in pixels per second
    float m_Speed;

public:
    Player();

    void spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize);

    // Call at the end of every game
    void resetPlayerStats();

    // Handle player getting hit by a zombie
    bool hit(sf::Time timeHit);

    // How long ago was the player last hit
    sf::Time getLastHitTime();

    // Player location
    sf::FloatRect getPosition();

    // Center of player
    sf::Vector2f getCenter();

    // Angle of player
    float getRotation();

    // Send sprite copy to main function
    sf::Sprite getSprite();

    // Player movement
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    // Stop specific player movement
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();

    // Call this function every frame
    void update(float elapsedTime, sf::Vector2i mousePosition);

    // Player speed boost
    void upgradeSpeed();

    // Player health increase
    void upgradeHealth();

    // Increase max player health level
    void increaseHealthLevel(int amount);

    // Current player health
    int getHealth();
};
