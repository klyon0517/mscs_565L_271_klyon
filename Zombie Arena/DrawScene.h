#pragma once
#include "Bullet.h"
#include "GameState.h"
#include "Pickup.h"
#include "Player.h"
#include "Zombie.h"
#include <SFML/Graphics.hpp>

void drawScene
(
    sf::RenderWindow&,
    sf::View&,
    State&,
    Player&,
    sf::VertexArray&,
    sf::Texture&,
    int,
    Zombie*&,
    Bullet[],
    sf::Sprite&,
    Pickup&,
    Pickup&,
    sf::View&,
    sf::Sprite&,
    sf::Sprite&,
    sf::RectangleShape&,
    sf::Text&,
    sf::Text&,
    sf::Text&,
    sf::Text&,
    sf::Text&,
    sf::Text&,
    sf::Text&,
    sf::Text&
);
