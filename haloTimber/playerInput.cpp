#include "playerInput.h"

void playerInput(
    RenderWindow& window,
    bool& paused) {

    if (Keyboard::isKeyPressed(Keyboard::Escape)) {

        window.close();

    }

    // Start the game
    if (Keyboard::isKeyPressed(Keyboard::Enter)) {

        paused = false;

    }

}