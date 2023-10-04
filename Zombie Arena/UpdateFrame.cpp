#include "UpdateFrame.h"
using namespace sf;

void updateFrame
(
    RenderWindow& window,
    View& mainView,
    State& state,
    Clock& clock,
    Time& gameTimeTotal,
    Vector2f& mouseWorldPosition,
    Vector2i& mouseScreenPosition,
    Player& player
)
{
    if (state == State::PLAYING)
    {
        // Update the delta time
        Time dt = clock.restart();

        // Update the total game time
        gameTimeTotal += dt;

        // Make a decimal fraction of 1 from the delta time
        float dtAsSeconds = dt.asSeconds();

        // Where is the mouse pointer
        mouseScreenPosition = Mouse::getPosition();

        // Convert mouse position to world coordinates of mainView
        mouseWorldPosition =
            window.mapPixelToCoords(Mouse::getPosition(), mainView);

        // Update the player
        player.update(dtAsSeconds, Mouse::getPosition());

        // Make of a note of the player's new position
        Vector2f playerPosition(player.getCenter());

        // Make the view center around the player
        mainView.setCenter(player.getCenter());
    }
}