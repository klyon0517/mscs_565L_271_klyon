#pragma once
#include "GameState.h"
#include "Player.h"
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
    Zombie*&
);