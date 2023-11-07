#include "Engine.h"

using namespace sf;

void Engine::input()
{
    Event event;

    while (m_Window.pollEvent(event))
    {
        if (event.type == Event::KeyPressed)
        {
            // Handle the player quitting
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                m_Window.close();
            }

            // Handle the player starting the game
            if (Keyboard::isKeyPressed(Keyboard::Return))
            {
                m_Playing = true;
            }

            // Switch between Thomas and Bob
            if (Keyboard::isKeyPressed(Keyboard::Q))
            {
                m_Character1 = !m_Character1;
            }

            // Switch between fullscreen and splitscreen
            if (Keyboard::isKeyPressed(Keyboard::E))
            {
                m_SplitScreen = !m_SplitScreen;
            }
        }
    }

    // Handle Thomas input
    if (m_Thomas.handleInput())
    {
        // play a jump sound
    }

    // Handle Bob input
    if (m_Bob.handleInput())
    {
        // play a jump sound
    }
}