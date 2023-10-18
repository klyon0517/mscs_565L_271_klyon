#pragma once
#include "Bullet.h"
#include "GameState.h"
#include "Player.h"
#include "Zombie.h"
#include <SFML/Graphics.hpp>

void playerInput
(
    sf::RenderWindow&,
    sf::Time&,
    State&,
    sf::Clock&,
    Player&,
    sf::IntRect&,
    sf::Vector2f&,
    sf::VertexArray&,
    int,
    int,
    Zombie*&,
    Bullet [100],
    int,
    int,
    int,
    int,
    float,
    sf::Time&,
    sf::Vector2f&
);
