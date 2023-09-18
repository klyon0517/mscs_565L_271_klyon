#include "windowDisplay.h"

void windowDisplay(
    RenderWindow& window,
    bool& paused,
    Sprite& spriteBackground,
    Text& messageText,
    Sprite& spriteGruntLine,
    Sprite& spriteBanshee) {

    window.clear();

    window.draw(spriteBackground);
    window.draw(spriteBanshee);
    window.draw(spriteGruntLine);

    if (paused) {

        window.draw(messageText);

    }

    window.display();

}