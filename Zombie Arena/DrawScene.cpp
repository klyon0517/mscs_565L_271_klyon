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
    Pickup& ammoPickup,
    View& hudView,
    Sprite& spriteAmmoIcon,
    Sprite& spriteGameOver,
    RectangleShape& healthBar,
    Text& ammoText,
    Text& scoreText,
    Text& hiScoreText,
    Text& zombiesRemainingText,
    Text& waveNumberText,
    Text& levelUpText,
    Text& pausedText,
    Text& gameOverText
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

        // Switch to the HUD view
        window.setView(hudView);

        // Draw all the HUD elements
        window.draw(spriteAmmoIcon);
        window.draw(ammoText);
        window.draw(scoreText);
        window.draw(hiScoreText);
        window.draw(healthBar);
        window.draw(waveNumberText);
        window.draw(zombiesRemainingText);
    }

    if (state == State::LEVELING_UP)
    {
        window.draw(spriteGameOver);
        window.draw(levelUpText);
    }

    if (state == State::PAUSED)
    {
        window.draw(pausedText);
    }

    if (state == State::GAME_OVER)
    {
        window.draw(spriteGameOver);
        window.draw(gameOverText);
        window.draw(scoreText);
        window.draw(hiScoreText);
    }

    window.display();
}