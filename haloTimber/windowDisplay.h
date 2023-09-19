#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef WINDOWDISPLAY_H_
#define WINDOWDISPLAY_H_

void windowDisplay(
    RenderWindow& window,
    bool& paused,
    Sprite& spriteBackground,
    Text& messageText,
    Sprite& spriteGruntLine,
    Sprite (&spriteBanshees)[3]);

#endif
