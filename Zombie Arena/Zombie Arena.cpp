/*  Zombie Arena

    * Course: Game Design & Programming I
    * Type: Independent Study
    * SEC: 565L 271
    * CRN: 13015
    * Instructor: Matthew Johnson
    * Software: Game #3 (Beginning C++ Game Programming, Horton, J.)
    * Filename: Zombie Arena.cpp
    * Author: Kerry Lyon
    * Created: October 1, 2023
    * Due: October 31, 2023

    * Main function for the Zombie Arena game.

*/

#include "DrawScene.h"
#include "GameState.h"
#include "Player.h"
#include "PlayerInput.h"
#include "UpdateFrame.h"
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{    
    // Start with the GAME_OVER state
    State state = State::GAME_OVER;

    // Get screen resolution & create an SFML window
    Vector2f resolution;
    resolution.x =
        VideoMode::getDesktopMode().width;
    resolution.y =
        VideoMode::getDesktopMode().height;
    RenderWindow window(
        VideoMode(resolution.x, resolution.y),
        "Zombie Arena",
        Style::Fullscreen);

    // Create an SFML view for the main section
    View mainView(FloatRect(0, 0, resolution.x, resolution.y));

    // Clock for timing everything
    Clock clock;
    // How long has the PLAYING state been active
    Time gameTimeTotal;

    // Mouse location in relation to world coordinates
    Vector2f mouseWorldPosition;
    
    // Mouse location in relation to screen coordinates
    Vector2i mouseScreenPosition;

    // Create an instance of the Player class
    Player player;

    // Arena boundaries
    IntRect arena;

    // Main game loop
    while (window.isOpen())
    {
        ///// Handle Input /////
        playerInput
        (
            window,
            state,
            clock,
            player,
            arena,
            resolution
        );

        ///// Update Frame /////
        updateFrame
        (
            window,
            mainView,
            state,
            clock,
            gameTimeTotal,
            mouseWorldPosition,
            mouseScreenPosition,
            player
        );

        ///// Draw Scene /////
        drawScene
        (
            window,
            mainView,
            state,
            player
        );
    }

    return 0;
}