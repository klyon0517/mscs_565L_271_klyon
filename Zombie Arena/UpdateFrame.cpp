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
    Player& player,
    int numZombies,
    Zombie*& zombies,
    Bullet bullets[],
    Sprite& spriteCrosshair,
    Pickup& healthPickup,
    Pickup& ammoPickup,
    int& score,
    int& hiScore,
    int& numZombiesAlive,
    int& bulletsSpare
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
        
        // Set the crosshair to the mouse world location
        spriteCrosshair.setPosition(mouseWorldPosition);

        // Update the player
        player.update(dtAsSeconds, Mouse::getPosition());

        // Make of a note of the player's new position
        Vector2f playerPosition(player.getCenter());

        // Make the view center around the player
        mainView.setCenter(player.getCenter());

        // Loop through each zombie and update them
        for (int i = 0; i < numZombies; i++)
        {
            if (zombies[i].isAlive())
            {
                zombies[i].update(
                    dt.asSeconds(), playerPosition);
            }
        }

        // Update any bullets that are in-flight
        for (int i = 0; i < 100; i++)
        {
            if (bullets[i].isInFlight())
            {
                bullets[i].update(dtAsSeconds);
            }
        }

        // Update the pickups
        healthPickup.update(dtAsSeconds);
        ammoPickup.update(dtAsSeconds);

        // Collision detection
        // Have any zombies been shot?
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < numZombies; j++)
            {
                if (bullets[i].isInFlight() &&
                    zombies[j].isAlive())
                {
                    if (bullets[i].getPosition().intersects
                    (zombies[j].getPosition()))
                    {
                        // Stop the bullet
                        bullets[i].stop();

                        // Register the hit and see if it will kill
                        if (zombies[j].hit())
                        {
                            // Not just a hit but a kill too
                            score += 10;

                            if (score >= hiScore)
                            {
                                hiScore = score;
                            }

                            numZombiesAlive--;

                            // When all the zombies are dead (again)
                            if (numZombiesAlive == 0)
                            {
                                state = State::LEVELING_UP;
                            }
                        }
                    }
                }
            }
        } // End zombie being shot

        // Have any zombies touched the player
        for (int i = 0; i < numZombies; i++)
        {
            if (player.getPosition().intersects
            (zombies[i].getPosition()) &&
                zombies[i].isAlive())
            {
                if (player.hit(gameTimeTotal))
                {

                }

                if (player.getHealth() <= 0)
                {
                    state = State::GAME_OVER;
                }
            }
        } // End player touched

        // Has the player touched a health pickup
        if (player.getPosition().intersects
        (healthPickup.getPosition()) &&
            healthPickup.isSpawned())
        {
            player.increaseHealthLevel(healthPickup.gotIt());
        }

        // Has the player touched an ammo pickup
        if (player.getPosition().intersects
        (ammoPickup.getPosition()) &&
            ammoPickup.isSpawned())
        {
            bulletsSpare += ammoPickup.gotIt();
        }
    }
}