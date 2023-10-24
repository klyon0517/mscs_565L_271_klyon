#include "PlayerInput.h"
#include "ZombieArena.h"
using namespace sf;

void playerInput
(
    RenderWindow& window,
    Time& gameTimeTotal,
    State& state,
    Clock& clock,
    Player& player,
    IntRect& arena,
    Vector2f& resolution,
    VertexArray& background,
    int numZombies,
    int numZombiesAlive,
    Zombie*& zombies,
    Bullet bullets[100],
    int currentBullet,
    int bulletsSpare,
    int bulletsInClip,
    int clipSize,
    float fireRate,
    Time& lastPressed,
    Vector2f& mouseWorldPosition,
    Pickup& healthPickup,
    Pickup& ammoPickup
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
                // Reloading
                if (event.key.code == Keyboard::R)
                {
                    if (bulletsSpare >= clipSize)
                    {
                        // Plenty of bullets. Reload.
                        bulletsInClip = clipSize;
                        bulletsSpare -= clipSize;
                    }
                    else if (bulletsSpare > 0)
                    {
                        // Only a few bullets left
                        bulletsInClip = bulletsSpare;
                        bulletsSpare = 0;
                    }
                    else
                    {
                        // More later
                    }
                }
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

        // Fire a bullet
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (gameTimeTotal.asMilliseconds() -
                lastPressed.asMilliseconds() >
                1000 / fireRate && bulletsInClip > 0)
            {
                // Pass the center of the player
                // and the center of the crosshair
                // to the shoot function
                bullets[currentBullet].shoot(
                    player.getCenter().x, player.getCenter().y,
                    mouseWorldPosition.x, mouseWorldPosition.y);

                currentBullet++;

                if (currentBullet > 99)
                {
                    currentBullet = 0;
                }

                lastPressed = gameTimeTotal;
                bulletsInClip--;
            }
        } // End fire a bullet
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

            // Pass the VA by reference
            int tileSize =
                createBackground(background, arena);

            // Don't need this anymore bc it's returned
            // from createBackground
            // int tileSize = 50;

            // Spawn the player in the middle of the arena
            player.spawn(arena, resolution, tileSize);

            // Configure the pickups
            healthPickup.setArena(arena);
            ammoPickup.setArena(arena);
            
            // Create a horde of zombies
            numZombies = 10;

            // Delete the previously allocated memory if it exists
            delete[] zombies;
            zombies = createHorde(numZombies, arena);
            numZombiesAlive = numZombies;

            // Reset the clock so there isn't a frame jump
            clock.restart();
        }
    } // End LEVELING_UP
}