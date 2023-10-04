#pragma once
#include "GameState.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

void playerInput
(
    sf::RenderWindow&,
    State&,
    sf::Clock&,
    Player&,
    sf::IntRect&,
    sf::Vector2f&
);
