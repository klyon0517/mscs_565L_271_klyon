#pragma once
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include "Pickup.h"
#include "Player.h"
#include "Zombie.h"

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
    sf::Vector2f&,
    Pickup&,
    Pickup&,
    int&,
    sf::Sound,
    int&,
    sf::Sound,
    sf::Sound,
    sf::Sound
);
