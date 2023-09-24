#include "PlayerInput.h"

void playerInput(
    RenderWindow& window,
    Bat& bat) {

    Event event;

    while (window.pollEvent(event)) {

        if (event.type == Event::Closed) {

            // Quit the game when window is closed
            window.close();

        }

    }

    // Handle player quitting
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {

        window.close();

    }

    // Handle pressing and releasing of the arrow keys
    if (Keyboard::isKeyPressed(Keyboard::Right)) {

        bat.moveRight();

    }
    else {

        bat.stopRight();

    }

    if (Keyboard::isKeyPressed(Keyboard::Left)) {

        bat.moveLeft();

    }
    else {

        bat.stopLeft();

    }

}