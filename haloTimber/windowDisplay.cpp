#include "windowDisplay.h"

void windowDisplay(
    RenderWindow& window,
    bool& paused,
    Sprite& spriteBackground,
    Text& messageText,
    Sprite& spriteGruntLine,
    Sprite spriteBanshees[3]) {

    window.clear();

    window.draw(spriteBackground);

    for (int i = 0; i < 3; i++) {

        window.draw(spriteBanshees[i]);

    }

    window.draw(spriteGruntLine);

    if (paused) {

        window.draw(messageText);

    }

    window.display();

}