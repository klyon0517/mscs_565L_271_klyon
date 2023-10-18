#pragma once
#include "Bullet.h"
#include "GameState.h"
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
    sf::Sprite&
);
