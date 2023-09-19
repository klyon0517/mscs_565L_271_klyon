#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef UPDATESCENE_H_
#define UPDATESCENE_H_

void updateScene(
    Clock& clock,
    bool& paused,
    bool& bansheeActive,
    float& bansheeSpeed,
    Sprite (&spriteBanshees)[3]);

#endif

