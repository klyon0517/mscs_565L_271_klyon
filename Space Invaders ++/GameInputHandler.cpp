#include "GameInputHandler.h"
#include "GameScreen.h"
#include "SoundEngine.h"

using namespace sf;

void GameInputHandler::initialize()
{

}

void GameInputHandler::handleGamepad()
{

}

void GameInputHandler::handleKeyPressed(
    Event& event,
    RenderWindow& window
)
{
    // Handle key presses
    if (event.key.code == Keyboard::Escape)
    {
        SoundEngine::playClick();
        getPointerToScreenManagerRemoteControl()->
            SwitchScreens("Select");
    }
}

void GameInputHandler::handleKeyReleased(
    Event& event,
    RenderWindow& window
)
{

}