#include "UpdateScene.h"
#include <iostream>

void updateScene(
    RenderWindow& window,
    Clock& clock,
    Bat& bat,
    Ball& ball,
    int& score,
    int& lives,
    Text& hud) {
        
    // Measure time
    Time dt = clock.restart();
    bat.update(dt);
    ball.update(dt);

    // Update HUD
    std::stringstream ss;
    ss << "Score: " << score << "   Lives: " << lives;
    hud.setString(ss.str());

    // Ball hitting the bottom
    if (ball.getPosition().top > window.getSize().y) {

        // Reverse ball direction
        ball.reboundBottom();

        // Remove a life
        lives--;

        // Check for zero lives
        if (lives < 1) {

            // reset score
            score = 0;

            // reset lives
            lives = 3;

        }

    }

    // Ball hitting the top
    if (ball.getPosition().top < 0) {

        ball.reboundBatOrTop();

        std::cout << "top bounce \n\n";

        // Add a score point
        score++;

    }

    // Ball hitting the sides
    if (ball.getPosition().left < 0 ||
        ball.getPosition().left + ball.getPosition().width > window.getSize().x) {

        ball.reboundSides();

        std::cout << "side bounce \n\n";

    }

    // Ball hitting the bat
    if (ball.getPosition().intersects(bat.getPosition())) {

        // hit detected reverse the ball
        ball.reboundBatOrTop();

        std::cout << "bat bounce \n\n";

        // Add a score point
        // score++;
    }

}