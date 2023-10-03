#include "Player.h"
using namespace sf;

Player::Player(){

    m_Speed = START_SPEED;
    m_Health = START_HEALTH;
    m_MaxHealth = START_HEALTH;

    // Sprite Texture
    m_Texture.loadFromFile("graphics/player.png");
    m_Sprite.setTexture(m_Texture);
    // Set sprite origin to it's center
    // The player.png 50px x 50px
    m_Sprite.setOrigin(25, 25);

}

void Player::spawn(
    IntRect arena,
    Vector2f resolution,
    int tileSize) {

    m_Position.x = arena.width / 2;
    m_Position.y = arena.height / 2;
    // Copy arena details to m_arena
    m_Arena.left = arena.left;
    m_Arena.width = arena.width;
    m_Arena.top = arena.top;
    m_Arena.height = arena.height;
    // Tile size
    m_TileSize = tileSize;
    // Resolution
    m_Resolution.x = resolution.x;
    m_Resolution.y = resolution.y;

}

void Player::resetPlayerStats() {

    m_Speed = START_SPEED;
    m_Health = START_HEALTH;
    m_MaxHealth = START_HEALTH;

}

bool Player::hit(Time timeHit) {

    if (timeHit.asMilliseconds()
        - m_LastHit.asMilliseconds() > 200) {

        m_LastHit = timeHit;
        m_Health -= 10;
        return true;

    }
    else {

        return false;

    }

}

Time Player::getLastHitTime() {

    return m_LastHit;

}