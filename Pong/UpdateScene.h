#pragma once

#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <SFML/Graphics.hpp>
using namespace sf;

void updateScene(
    RenderWindow&,
    Clock&,
    Bat&,
    Ball&,
    int&,
    int&,
    Text&);