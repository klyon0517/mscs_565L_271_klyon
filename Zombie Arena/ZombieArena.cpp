/*  Zombie Arena

    * Course: Game Design & Programming I
    * Type: Independent Study
    * SEC: 565L 271
    * CRN: 13015
    * Instructor: Matthew Johnson
    * Software: Game #3 (Beginning C++ Game Programming, Horton, J.)
    * Filename: ZombieArena.cpp
    * Author: Kerry Lyon
    * Created: October 1, 2023
    * Due: October 31, 2023

    * Main function for the Zombie Arena game.

*/

#include <SFML/Audio.hpp>
#include "Bullet.h"
#include "DrawScene.h"
#include <fstream>
#include "GameState.h"
#include "Pickup.h"
#include "Player.h"
// #include "PlayerInput.h"
#include <sstream>
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

	// Create a couple of pickups
	Pickup healthPickup(1);
	Pickup ammoPickup(2);

	// About the game
	int score = 0;
	int hiScore = 0;

	// For the home / game over screen
	Sprite spriteGameOver;
	Texture textureGameOver =
		TextureHolder::GetTexture("graphics/background.png");
	spriteGameOver.setTexture(textureGameOver);
	spriteGameOver.setPosition(0, 0);

	// Create a view for the HUD
	View hudView(FloatRect(0, 0, resolution.x, resolution.y));

	// Create a sprite for the ammo icon
	Sprite spriteAmmoIcon;
	Texture	textureAmmoIcon =
		TextureHolder::GetTexture("graphics/ammo_icon.png");
	spriteAmmoIcon.setTexture(textureAmmoIcon);
	spriteAmmoIcon.setPosition(20, 980);

	// Load the font
	Font font;
	font.loadFromFile("fonts/zombiecontrol.ttf");

	// Paused
	Text pausedText;
	pausedText.setFont(font);
	pausedText.setCharacterSize(155);
	pausedText.setFillColor(Color::White);
	pausedText.setPosition(400, 400);
	pausedText.setString("Press Enter \nto continue");

	// Game over
	Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(125);
	gameOverText.setFillColor(Color::White);
	gameOverText.setPosition(250, 850);
	gameOverText.setString("Press Enter to play");

	// Leveling up
	Text levelUpText;
	levelUpText.setFont(font);
	levelUpText.setCharacterSize(80);
	levelUpText.setFillColor(Color::White);
	levelUpText.setPosition(150, 250);
	std::stringstream levelUpStream;
	levelUpStream <<
		"1 - Increased rate of fire" <<
		"\n2 - Increased clip size (next reload)" <<
		"\n3 - Increased max health" <<
		"\n4 - Increased run speed" <<
		"\n5 - More and better health pickups" <<
		"\n6 - More and better ammo pickups";
	levelUpText.setString(levelUpStream.str());

	// Ammo
	Text ammoText;
	ammoText.setFont(font);
	ammoText.setCharacterSize(55);
	ammoText.setFillColor(Color::White);
	ammoText.setPosition(200, 980);

	// Score
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(55);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(20, 0);

	// Load the high score from a text file
	std::ifstream inputFile("gamedata/scores.txt");
	if (inputFile.is_open())
	{
		// >> reads the data
		inputFile >> hiScore;
		inputFile.close();
	}

	// HiScore
	Text hiScoreText;
	hiScoreText.setFont(font);
	hiScoreText.setCharacterSize(55);
	hiScoreText.setFillColor(Color::White);
	hiScoreText.setPosition(1400, 0);
	std::stringstream s;
	s << "High Score: " << hiScore;
	hiScoreText.setString(s.str());

	// Zombies remaining
	Text zombiesRemainingText;
	zombiesRemainingText.setFont(font);
	zombiesRemainingText.setCharacterSize(55);
	zombiesRemainingText.setFillColor(Color::White);
	zombiesRemainingText.setPosition(1500, 980);
	zombiesRemainingText.setString("Zombies: 100");

	// Wave number
	int wave = 0;
	Text waveNumberText;
	waveNumberText.setFont(font);
	waveNumberText.setCharacterSize(55);
	waveNumberText.setFillColor(Color::White);
	waveNumberText.setPosition(1250, 980);
	waveNumberText.setString("Wave: 0");

	// Health bar
	RectangleShape healthBar;
	healthBar.setFillColor(Color::Red);
	healthBar.setPosition(450, 980);

	// When did we last update the HUD?
	int framesSinceLastHUDUpdate = 0;

	// How often (in frames) shoudl we update the HUD
	int fpsMeasurementFrameInterval = 1000;

	// Prepare the hit sound
	SoundBuffer hitBuffer;
	hitBuffer.loadFromFile("sound/hit.wav");
	Sound hit;
	hit.setBuffer(hitBuffer);

	// Prepare the splat sound
	SoundBuffer splatBuffer;
	splatBuffer.loadFromFile("sound/splat.wav");
	Sound splat;
	splat.setBuffer(splatBuffer);

	// Prepare the shoot sound
	SoundBuffer shootBuffer;
	shootBuffer.loadFromFile("sound/shoot.wav");
	Sound shoot;
	shoot.setBuffer(shootBuffer);

	// Prepare the reload sound
	SoundBuffer reloadBuffer;
	reloadBuffer.loadFromFile("sound/reload.wav");
	Sound reload;
	reload.setBuffer(reloadBuffer);

	// Prepare the failed sound
	SoundBuffer reloadFailedBuffer;
	reloadFailedBuffer.loadFromFile("sound/reload_failed.wav");
	Sound reloadFailed;
	reloadFailed.setBuffer(reloadFailedBuffer);

	// Prepare the powerup sound
	SoundBuffer powerupBuffer;
	powerupBuffer.loadFromFile("sound/powerup.wav");
	Sound powerup;
	powerup.setBuffer(powerupBuffer);

	// Prepare the pickup sound
	SoundBuffer pickupBuffer;
	pickupBuffer.loadFromFile("sound/pickup.wav");
	Sound pickup;
	pickup.setBuffer(pickupBuffer);

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
			mouseWorldPosition,
			healthPickup,
			ammoPickup,
			wave,
			powerup,
			score,
			reload,
			reloadFailed,
			shoot
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
					wave = 0;
					score = 0;

					// Prepare the gun and ammo for next game
					currentBullet = 0;
					bulletsSpare = 24;
					bulletsInClip = 6;
					clipSize = 6;
					fireRate = 1;
					
					// Reset the player's stats
					player.resetPlayerStats();
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
							reload.play();
						}
						else if (bulletsSpare > 0)
						{
							// Only a few bullets left
							bulletsInClip = bulletsSpare;
							bulletsSpare = 0;
							reload.play();
						}
						else
						{
							// More later
							reloadFailed.play();
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
					shoot.play();
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
				// Increase fire rate
				fireRate++; 
				state = State::PLAYING;
			}

			if (event.key.code == Keyboard::Num2)
			{
				// Increase clip size
				clipSize += clipSize;
				state = State::PLAYING;
			}

			if (event.key.code == Keyboard::Num3)
			{
				// Increase health
				player.upgradeHealth();
				state = State::PLAYING;
			}

			if (event.key.code == Keyboard::Num4)
			{
				// Increase speed
				player.upgradeSpeed();
				state = State::PLAYING;
			}

			if (event.key.code == Keyboard::Num5)
			{
				// Upgrade health pickup
				healthPickup.upgrade();
				state = State::PLAYING;
			}

			if (event.key.code == Keyboard::Num6)
			{
				// Upgrade ammo pickup
				ammoPickup.upgrade();
				state = State::PLAYING;
			}

			if (state == State::PLAYING)
			{
				// Increase the wave number
				wave++;

				// Prepare the level
				// We will modify the next two lines later
				arena.width = 500 * wave;
				arena.height = 500 * wave;
				arena.left = 0;
				arena.top = 0;

				// Pass the vertex array by reference
				// to the createBackground function
				int tileSize = createBackground(background, arena);

				// Spawn the player in the middle of the arena
				player.spawn(arena, resolution, tileSize);

				// Configure the pickups
				healthPickup.setArena(arena);
				ammoPickup.setArena(arena);

				// Create a horde of zombies
				numZombies = 5 * wave;

				// Delete the previously allocated memory (if it exists)
				delete[] zombies;
				zombies = createHorde(numZombies, arena);
				numZombiesAlive = numZombies;

				// Play the powerup sound
				powerup.play();

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
			spriteCrosshair,
			healthPickup,
			ammoPickup,
			score,
			hiScore,
			numZombiesAlive,
			bulletsInClip,
			bulletsSpare,
			wave,
			healthBar,
			framesSinceLastHUDUpdate,
			fpsMeasurementFrameInterval,
			ammoText,
			scoreText,
			hiScoreText,
			zombiesRemainingText,
			waveNumberText,
			hit,
			pickup,
			reload,
			splat
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
			spriteCrosshair,
			healthPickup,
			ammoPickup,
			hudView,
			spriteAmmoIcon,
			spriteGameOver,
			healthBar,
			ammoText,
			scoreText,
			hiScoreText,
			zombiesRemainingText,
			waveNumberText,
			levelUpText,
			pausedText,
			gameOverText
        );
    }

    // Delete the previously allocated memory if it exists
    delete[] zombies;

    return 0;
}