#include <sstream>
#include <SFML/Graphics.hpp>
#include "drawScene.h"

// Make code easier to type with "using namespace"
using namespace sf;

/*************** Draw the scene ***************/

void drawScene(
    RenderWindow window,
    bool paused,
    Sprite spriteBackground,
    Sprite spriteCloud1,
    Sprite spriteCloud2,
    Sprite spriteCloud3,
    Sprite spriteTree,
    Sprite spriteBee,
    RectangleShape timebar,
    Text scoreText,
    Text messageText) {

    // Clear everything from the last frame
    window.clear();

    // Draw our game scene here
    window.draw(spriteBackground);
    window.draw(spriteCloud1);
    window.draw(spriteCloud2);
    window.draw(spriteCloud3);
    window.draw(spriteTree);
    window.draw(spriteBee);

    // Draw timebar
    window.draw(timebar);

    // Draw score
    window.draw(scoreText);

    if (paused) {

        // Draw message
        window.draw(messageText);

    }

    // Show everything we just drew
    window.display();

}