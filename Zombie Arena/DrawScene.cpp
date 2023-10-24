#include "DrawScene.h"
using namespace sf;

void drawScene
(
    RenderWindow& window,
    View& mainView,
    State& state,
    Player& player,
    VertexArray& background,
    Texture& textureBackground,
    int numZombies,
    Zombie*& zombies,
    Bullet bullets[],
    Sprite& spriteCrosshair,
    Pickup& healthPickup,
    Pickup& ammoPickup
)
{
    if (state == State::PLAYING)
    {
        window.clear();

        // set the mainView to be displayed in the window
        window.setView(mainView);

        // Draw the background
        window.draw(background, &textureBackground);
        
        // Draw the zombies
        for (int i = 0; i < numZombies; i++)
        {
            window.draw(zombies[i].getSprite());
        }

        // Draw the bullets
        for (int i = 0; i < 100; i++)
        {
            if (bullets[i].isInFlight())
            {
                window.draw(bullets[i].getShape());
            }
        }

        // Draw the player
        window.draw(player.getSprite());

        // Draw the pickups, if currently spawned
        if (ammoPickup.isSpawned())
        {
            window.draw(ammoPickup.getSprite());
        }

        if (healthPickup.isSpawned())
        {
            window.draw(healthPickup.getSprite());
        }

        // Draw the crosshair
        window.draw(spriteCrosshair);
    }

    if (state == State::LEVELING_UP)
    {

    }

    if (state == State::PAUSED)
    {

    }

    if (state == State::GAME_OVER)
    {

    }

    window.display();
}