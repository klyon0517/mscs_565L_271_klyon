/*  Timber

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
#include "PlayerInput.h"
#include "UpdateScene.h"
#include "DrawWindow.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main() {

    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Pong", Style::Fullscreen);
    int score = 0;
    int lives = 3;

    Bat bat(1920 / 2, 1080 - 20);

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
            clock,
            bat,
            score,
            lives,
            hud);

        // Draw Window
        drawWindow(
            window,
            bat,
            hud);
    }

    return 0;

}