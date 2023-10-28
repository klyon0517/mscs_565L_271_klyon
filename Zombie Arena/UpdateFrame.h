#pragma once
#include "Bullet.h"
#include "GameState.h"
#include "Pickup.h"
#include "Player.h"
#include <sstream>
#include "Zombie.h"
#include <SFML/Graphics.hpp>

void updateFrame
(
    sf::RenderWindow&,
    sf::View&,
    State&,
    sf::Clock&,
    sf::Time&,
    sf::Vector2f&,
    sf::Vector2i&,
    Player&,
    int,
    Zombie*&,
    Bullet[],
    sf::Sprite&,
    Pickup&,
    Pickup&,
    int&,
    int&,
    int&,
    int,
    int&,
    int&,
    sf::RectangleShape&,
    int&,
    int&,
    sf::Text&,
    sf::Text&,
    sf::Text&,
    sf::Text&,
    sf::Text&
);