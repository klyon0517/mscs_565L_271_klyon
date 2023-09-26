#pragma once

#include "Bat.h"
#include "Ball.h"
#include <SFML/Graphics.hpp>
using namespace sf;

void updateScene(
    Clock&,
    Bat&,
    Ball&,
    int&,
    int&,
    Text&);