#include "PlayerInput.h"
using namespace sf;

void playerInput
(
    RenderWindow& window,
    State& state,
    Clock& clock,
    Player& player,
    IntRect& arena,
    Vector2f& resolution
)
{   
    // Handle events by polling
    Event event;

    while (window.pollEvent(event))
    {
        if (event.type == Event::KeyPressed)
        {
            // Pause a game while playing
            if (event.key.code == Keyboard::Return &&
                state == State::PLAYING)
            {
                state = State::PAUSED;
            }

            // Restart while paused
            else if (event.key.code == Keyboard::Return &&
                state == State::PAUSED)
            {
                state = State::PLAYING;
                // Reset the clock so there isn't a frame jump
                clock.restart();
            }

            // Start a new game while in GAME_OVER state
            else if (event.key.code == Keyboard::Return &&
                state == State::GAME_OVER)
            {
                state = State::LEVELING_UP;
            }

            if (state == State::PLAYING)
            {

            }
        }
    } // End event polling

    // Handle the player quitting
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        window.close();
    }

    // Handle WASD while playing
    if (state == State::PLAYING)
    {
        // Handle pressing & releasing of WASD keys
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            player.moveUp();
        }
        else {
            player.stopUp();
        }

        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            player.moveDown();
        }
        else {
            player.stopDown();
        }

        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            player.moveLeft();
        }
        else {
            player.stopLeft();
        }

        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            player.moveRight();
        }
        else {
            player.stopRight();
        }
    } // End WASD while playing

    // Handle the LEVELING_UP state
    if (state == State::LEVELING_UP)
    {
        // Handle the player leveling up
        if (event.key.code == Keyboard::Num1)
        {
            state = State::PLAYING;
        }

        if (event.key.code == Keyboard::Num2)
        {
            state = State::PLAYING;
        }

        if (event.key.code == Keyboard::Num3)
        {
            state = State::PLAYING;
        }

        if (event.key.code == Keyboard::Num4)
        {
            state = State::PLAYING;
        }

        if (event.key.code == Keyboard::Num5)
        {
            state = State::PLAYING;
        }

        if (event.key.code == Keyboard::Num6)
        {
            state = State::PLAYING;
        }

        if (state == State::PLAYING)
        {
            // Prepare the level
            arena.width = 500;
            arena.height = 500;
            arena.left = 0;
            arena.top = 0;

            int tileSize = 50;

            // Spawn the player in the middle of the arena
            player.spawn(arena, resolution, tileSize);

            // Reset the clock so there isn't a frame jump
            clock.restart();
        }
    } // End LEVELING_UP
}