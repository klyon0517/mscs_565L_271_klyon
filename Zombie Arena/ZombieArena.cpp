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

#include "Bullet.h"
#include "DrawScene.h"
#include "GameState.h"
#include "Player.h"
// #include "PlayerInput.h"
#include "TextureHolder.h"
#include "UpdateFrame.h"
#include "ZombieArena.h"
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{    
    // Here is the one instance of TextureHolder
    TextureHolder holder;

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

    // Create the background
    VertexArray background;

    // Load the background textures
    // Texture textureBackground;
    // textureBackground.loadFromFile("graphics/background_sheet.png");
	Texture textureBackground =
		TextureHolder::GetTexture("graphics/background_sheet.png");

    // Prepare for a horde of zombies
    int numZombies = 0;
    int numZombiesAlive = 0;
    Zombie* zombies = nullptr;

	// 100 bullets should do
	Bullet bullets[100];
	int currentBullet = 0;
	int bulletsSpare = 24;
	int bulletsInClip = 6;
	int clipSize = 6;
	float fireRate = 1;

	// When was the fire button last pressed?
	Time lastPressed;

	// Hide the mouse pointer and replace it with a crosshair
	window.setMouseCursorVisible(true);

	Sprite spriteCrosshair;
	Texture textureCrosshair =
		TextureHolder::GetTexture("graphics/crosshair.png");
	spriteCrosshair.setTexture(textureCrosshair);
	spriteCrosshair.setOrigin(25, 25);

    // Main game loop
    while (window.isOpen())
    {
        ///// Handle Input /////
        /* playerInput
        (
            window,
			gameTimeTotal,
            state,
            clock,
            player,
            arena,
            resolution,
            background,
            numZombies,
            numZombiesAlive,
			zombies,
			bullets,
			currentBullet,
			bulletsSpare,
			bulletsInClip,
			clipSize,
			fireRate,
			lastPressed,
			mouseWorldPosition
        ); */

		/*
		************
		Handle input
		************
		*/

		// Handle events
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
		}// End event polling


		 // Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Handle controls while playing
		if (state == State::PLAYING)
		{
			// Handle the pressing and releasing of the WASD keys
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player.moveUp();
			}
			else
			{
				player.stopUp();
			}

			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player.moveDown();
			}
			else
			{
				player.stopDown();
			}

			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player.moveLeft();
			}
			else
			{
				player.stopLeft();
			}

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player.moveRight();
			}
			else
			{
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
		}// End WASD while playing

		 // Handle the levelling up state
		if (state == State::LEVELING_UP)
		{
			// Handle the player levelling up
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
				// Prepare thelevel
				// We will modify the next two lines later
				arena.width = 500;
				arena.height = 500;
				arena.left = 0;
				arena.top = 0;

				// Pass the vertex array by reference
				// to the createBackground function
				int tileSize = createBackground(background, arena);

				// Spawn the player in the middle of the arena
				player.spawn(arena, resolution, tileSize);

				// Create a horde of zombies
				numZombies = 10;

				// Delete the previously allocated memory (if it exists)
				delete[] zombies;
				zombies = createHorde(numZombies, arena);
				numZombiesAlive = numZombies;

				// Reset the clock so there isn't a frame jump
				clock.restart();
			}
		}// End levelling up

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
            player,
            numZombies,
            zombies,
			bullets,
			spriteCrosshair
        );

        ///// Draw Scene /////
        drawScene
        (
            window,
            mainView,
            state,
            player,
            background,
            textureBackground,
            numZombies,
            zombies,
			bullets,
			spriteCrosshair
        );
    }

    // Delete the previously allocated memory if it exists
    // delete[] zombies;

    return 0;
}