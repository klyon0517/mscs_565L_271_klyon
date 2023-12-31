/*  Pong

    * Course: Game Design & Programming I
    * Type: Independent Study
    * SEC: 565L 271
    * CRN: 13015
    * Instructor: Matthew Johnson
    * Software: Game #2 (Beginning C++ Game Programming, Horton, J.)
    * Filename: Pong.cpp
    * Author: Kerry Lyon
    * Created: September 19, 2023
    * Due: October 5, 2023

    * Main function for the Pong game.

*/

#include "Bat.h"
#include "Ball.h"
#include "PlayerInput.h"
#include "UpdateScene.h"
#include "DrawWindow.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main() {

    // VideoMode vm(1920, 1080);
    // RenderWindow window(vm, "Pong", Style::Fullscreen);
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    RenderWindow window(VideoMode(resolution.x, resolution.y), "Pong", Style::Fullscreen);
    View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));
    View hudView(sf::FloatRect(0, 0, resolution.x, resolution.y));

    int score = 0;
    int lives = 3;

    Bat bat(1920 / 2, 1080 - 20);
    Ball ball(1920 / 2, 0);

    Text hud;
    Font font;
    font.loadFromFile("fonts/DS-DIGIT.TTF");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setPosition(20, 20);

    Clock clock;

    while (window.isOpen()) {

        playerInput(
            window,
            bat);

        // Update Scene
        updateScene(
            window,
            clock,
            bat,
            ball,
            score,
            lives,
            hud);

        // Draw Window
        drawWindow(
            window,
            bat,
            ball,
            mainView,
            hudView,
            hud);
    }

    return 0;

}