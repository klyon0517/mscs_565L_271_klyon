#include "GameOverInputHandler.h"
#include <iostream>
#include "SoundEngine.h"
#include "WorldState.h"

using namespace sf;
using namespace std;

void GameOverInputHandler::handleKeyPressed(
    Event& event,
    RenderWindow& window
)
{
    if (event.key.code == Keyboard::Escape)
    {
        SoundEngine::playClick();
        getPointerToScreenManagerRemoteControl()->
            SwitchScreens("Select");
    }
}

void GameOverInputHandler::handleLeftClick(
    string& buttonInteractedWith,
    RenderWindow& window
)
{
    if (buttonInteractedWith == "Play")
    {
        SoundEngine::playClick();
        WorldState::WAVE_NUMBER = 0;
        getPointerToScreenManagerRemoteControl()->
            loadLevelInPlayMode("level1");
    }
    else if (buttonInteractedWith == "Home")
    {
        SoundEngine::playClick();
        getPointerToScreenManagerRemoteControl()->
            SwitchScreens("Select");
    }
}