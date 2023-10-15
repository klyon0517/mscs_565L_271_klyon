#pragma once
#include "Zombie.h"
#include <SFML/Graphics.hpp>

int createBackground(
    sf::VertexArray&,
    sf::IntRect&);

Zombie* createHorde(
    int numZombies,
    sf::IntRect arena);
