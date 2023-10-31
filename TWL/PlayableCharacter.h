#pragma once
#include <SFML/Graphics.hpp>

class PlayableCharacter
{
protected:
    // Of course we will need a sprite
    sf::Sprite m_Sprite;

    // How long does a jump last?
    float m_JumpDuration;

    // Is the character currently
    // jumping or falling?
    bool m_IsJumping;
    bool m_IsFalling;

    // Which direction is the character
    // currently moving in?
    bool m_LeftPressed;
    bool m_RightPressed;

    // How long has this jump lasted
    // so far?
    float m_TimeThisJump;

    // Has the player just initiated a jump
    bool m_JustJumped = false;
    
private:
    // What is the gravity
    float m_Gravity;

    // How fast is the character
    float m_Speed = 400;

    // Where is the player
    sf::Vector2f m_Position;

    // Where are the characters body parts
    sf::FloatRect m_Feet;
    sf::FloatRect m_Head;
    sf::FloatRect m_Right;
    sf::FloatRect m_Left;

    // And a texture
    sf::Texture m_Texture;

public:
    void spawn(sf::Vector2f startPosition, float gravity);

    // This is a pure virtual function
    bool virtual handleInput() = 0;

    // This class is now abstract and
    // cannot be instantiated
    
    // Where is the player
    sf::FloatRect getPosition();

    // A rectangle representing the position
    // of different parts of the sprite
    sf::FloatRect getFeet();
    sf::FloatRect getHead();
    sf::FloatRect getRight();
    sf::FloatRect getLeft();

    sf::Sprite getSprite();

    // Make the character stand firm
    void stopFalling(float position);
    void stopRight(float position);
    void stopLeft(float position);
    void stopJump();

    // Where is the center of the character
    sf::Vector2f getCenter();

    // We will call this function
    // once every frame
    void update(float elapsedTime);
};