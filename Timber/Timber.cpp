/*  Timber

    * Course: Game Design & Programming I
    * Type: Independent Study
    * SEC: 565L 271
    * CRN: 13015
    * Instructor: Matthew Johnson
    * Software: Game #1 (Beginning C++ Game Programming, Horton, J.)
    * Filename: Timber.cpp
    * Author: Kerry Lyon
    * Created: September 2, 2023
    * Due: September 19, 2023

    * Main function for the Timber game.

*/

// Include important libraries here
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
// #include "drawScene.h"

// Make code easier to type with "using namespace"
using namespace sf;

// Forward Declaration (function prototype)
/* void drawScene(
    RenderWindow&,
    Sprite&); */
void updateBranches(int seed);
const int NUM_BRANCHES = 6;
Sprite branches[NUM_BRANCHES];

// Where is the player branch? left or right
enum class side {LEFT, RIGHT, NONE};
side branchPositions[NUM_BRANCHES];

//This is where our game starts from
int main() {

    bool beeActive = false;
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;
    bool paused = true;

    int number = (rand() % 100);
    int score = 0;

    float beeSpeed = 0.0f;
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    Clock clock;
    Font font;
    Text messageText;
    Text scoreText;
    
    // Create a video mode object
    VideoMode vm(1920, 1080);

    // Create and open a window for the game
    RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

    // Create textures to hold graphics on the GPU
    Texture textureBackground;
    Texture textureTree;
    Texture textureBee;
    Texture textureCloud;
    Texture textureBranch;

    // Load graphics into the textures
    textureBackground.loadFromFile("graphics/background.png");
    textureTree.loadFromFile("graphics/tree.png");
    textureBee.loadFromFile("graphics/bee.png");
    textureCloud.loadFromFile("graphics/cloud.png");
    textureBranch.loadFromFile("graphics/branch.png");

    // Create sprites
    Sprite spriteBackground;
    Sprite spriteTree;
    Sprite spriteBee;
    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;

    // Attach the textures to the sprites
    spriteBackground.setTexture(textureBackground);
    spriteTree.setTexture(textureTree);
    spriteBee.setTexture(textureBee);
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);

    // Set the sprites position
    spriteBackground.setPosition(0, 0);
    spriteTree.setPosition(810, 0);
    spriteBee.setPosition(0, 800);
    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 250);
    spriteCloud3.setPosition(0, 500);

    // Set the font
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    // Apply font
    messageText.setFont(font);
    scoreText.setFont(font);

    // Set text characteristics
    // Message
    messageText.setString("Press Enter to Start");
    scoreText.setString("Score = 0");
    // Size
    messageText.setCharacterSize(75);
    scoreText.setCharacterSize(100);
    // Color
    messageText.setFillColor(Color::White);
    scoreText.setFillColor(Color::White);
    // Position
    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin(
        textRect.left +
        textRect.width / 2.0f,
        textRect.top + 
        textRect.height / 2.0f
    );
    messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
    scoreText.setPosition(20, 20);

    // Prepare 6 branches
    for (int i = 0; i < NUM_BRANCHES; i++) {

        branches[i].setTexture(textureBranch);
        branches[i].setPosition(-2000, -2000);
        branches[i].setOrigin(220, 20);

    }

    // Time bar
    RectangleShape timebar;
    float timeBarStartWidth = 400;
    float timeBarHeight = 80;
    timebar.setSize(
        Vector2f(timeBarStartWidth, timeBarHeight)
    );
    timebar.setFillColor(Color::Red);
    timebar.setPosition(
        (1920 / 2) - timeBarStartWidth / 2, 980
    );
    Time gameTimeTotal;
    float timeRemaining = 6.0f;
    float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

    /* updateBranches(1);
    updateBranches(2);
    updateBranches(3);
    updateBranches(4);
    updateBranches(5); */

    // Prepare the player
    Texture texturePlayer;
    texturePlayer.loadFromFile("graphics/player.png");

    Sprite spritePlayer;
    spritePlayer.setTexture(texturePlayer);
    spritePlayer.setPosition(580, 720);
    // Start on the left side
    side playerSide = side::LEFT;
    // Gravestone
    Texture textureRIP;
    textureRIP.loadFromFile("graphics/rip.png");
    Sprite spriteRIP;
    spriteRIP.setTexture(textureRIP);
    spriteRIP.setPosition(600, 860);
    // Axe
    Texture textureAxe;
    textureAxe.loadFromFile("graphics/axe.png");
    Sprite spriteAxe;
    spriteAxe.setTexture(textureAxe);
    spriteAxe.setPosition(700, 830);
    // Line up axe with tree
    const float AXE_POSITION_LEFT = 700;
    const float AXE_POSITION_RIGHT = 1075;
    // Prepare flying log
    Texture textureLog;
    textureLog.loadFromFile("graphics/log.png");
    Sprite spriteLog;
    spriteLog.setTexture(textureLog);
    spriteLog.setPosition(810, 720);
    // Other log variables
    bool logActive = false;
    float logSpeedX = 1000;
    float logSpeedY = -1500;
    // Control player input
    bool acceptInput = false;

    // Sounds
    SoundBuffer chopBuffer;
    chopBuffer.loadFromFile("sound/chop.wav");
    Sound chop;
    chop.setBuffer(chopBuffer);

    SoundBuffer deathBuffer;
    deathBuffer.loadFromFile("sound/death.wav");
    Sound death;
    death.setBuffer(deathBuffer);

    SoundBuffer ootBuffer;
    ootBuffer.loadFromFile("sound/out_of_time.wav");
    Sound outOfTime;
    outOfTime.setBuffer(ootBuffer);

    while (window.isOpen()) {

        /*************** Handle the player's input ***************/

        Event event;
        
        while (window.pollEvent(event)) {

            if (event.type == Event::KeyReleased && !paused) {

                // Listen for key press
                acceptInput = true;

                // hide axe
                spriteAxe.setPosition(2000, spriteAxe.getPosition().y);

            }

        }

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {

            window.close();

        }

        // Start the game
        if (Keyboard::isKeyPressed(Keyboard::Enter)) {

            paused = false;

            // Reset the time and score
            timeRemaining = 6;
            score = 0;

            // Make branches disappear - start with 2nd position
            for (int i = 1; i < NUM_BRANCHES; i++) {

                branchPositions[i] = side::NONE;

            }

            // Hide gravestone
            spriteRIP.setPosition(675, 2000);
            // Set player position
            spritePlayer.setPosition(580, 720);
            acceptInput = true;

        }

        // Accept player input for the character
        if (acceptInput) {

            // Right cursor key
            if (Keyboard::isKeyPressed(Keyboard::Right)) {

                // Make sure player is on right
                playerSide = side::RIGHT;

                score++;

                // Add to the amount of time remaining
                timeRemaining += (2 / score) + .15;

                spriteAxe.setPosition(AXE_POSITION_RIGHT, spriteAxe.getPosition().y);
                spritePlayer.setPosition(1200, 720);

                // Update branches
                updateBranches(score);

                // Set log flying to left
                spriteLog.setPosition(810, 720);
                logSpeedX = -5000;
                logActive = true;
                acceptInput = false;

                // Play chop sound
                chop.play();

            }

            // Left cursor key
            if (Keyboard::isKeyPressed(Keyboard::Left)) {

                // Make sure player is on right
                playerSide = side::LEFT;

                score++;

                // Add to the amount of time remaining
                timeRemaining += (2 / score) + .15;

                spriteAxe.setPosition(AXE_POSITION_LEFT, spriteAxe.getPosition().y);
                spritePlayer.setPosition(580, 720);

                // Update branches
                updateBranches(score);

                // Set log flying to right
                spriteLog.setPosition(810, 720);
                logSpeedX = 5000;
                logActive = true;
                acceptInput = false;

                // Play chop sound
                chop.play();

            }

        }

        /*************** Update the scene ***************/

        if (!paused) {

            // Measure time
            Time dt = clock.restart();

            // Subtract from the amount of time remaining
            timeRemaining -= dt.asSeconds();
            
            // Size up the time bar
            timebar.setSize(
                Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight)
            );

            if (timeRemaining <= 0.0f) {

                // Pause the game
                paused = true;

                // Change the player message
                messageText.setString("Out of Time!");

                // Reposition text based on new size
                FloatRect textRect = messageText.getLocalBounds();
                messageText.setOrigin(
                    textRect.left +
                    textRect.width / 2.0f,
                    textRect.top +
                    textRect.height / 2.0f
                );
                messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

                // Play out of time sound
                outOfTime.play();

            }

            // Setup the bee
            if (!beeActive) {

                // How fast is the bee
                srand((int)time(0));
                beeSpeed = (rand() % 200) + 200;

                // How high is the bee
                srand((int)time(0) * 10);
                float height = (rand() % 500) + 500;
                spriteBee.setPosition(2000, height);
                beeActive = true;

            }
            else {

                // Move the bee
                spriteBee.setPosition(
                    spriteBee.getPosition().x -
                    (beeSpeed * dt.asSeconds()),
                    spriteBee.getPosition().y);

                // Has the bee reached the left side of the screen
                if (spriteBee.getPosition().x < -100) {

                    // Setup as a brand new bee next frame
                    beeActive = false;

                }

            }

            // Setup cloud1
            if (!cloud1Active) {

                // How fast is the cloud
                srand((int)time(0) * 10);
                cloud1Speed = (rand() % 200);

                // How high is the cloud
                srand((int)time(0) * 10);
                float height = (rand() % 150);
                spriteCloud1.setPosition(-200, height);
                cloud1Active = true;

            }
            else {

                // Move cloud1
                spriteCloud1.setPosition(
                    spriteCloud1.getPosition().x +
                    (cloud1Speed * dt.asSeconds()),
                    spriteCloud1.getPosition().y);

                // Has the bee reached the right side of the screen
                if (spriteCloud1.getPosition().x > 1920) {

                    // Setup as a brand new cloud next frame
                    cloud1Active = false;

                }

            }

            // Setup cloud2
            if (!cloud2Active) {

                // How fast is the cloud
                srand((int)time(0) * 20);
                cloud2Speed = (rand() % 200);

                // How high is the cloud
                srand((int)time(0) * 20);
                float height = (rand() % 300) - 150;
                spriteCloud2.setPosition(-200, height);
                cloud2Active = true;

            }
            else {

                // Move the bee
                spriteCloud2.setPosition(
                    spriteCloud2.getPosition().x +
                    (cloud2Speed * dt.asSeconds()),
                    spriteCloud2.getPosition().y);

                // Has the bee reached the right side of the screen
                if (spriteCloud2.getPosition().x > 1920) {

                    // Setup as a brand new cloud next frame
                    cloud2Active = false;

                }

            }

            // Setup cloud3
            if (!cloud3Active) {

                // How fast is the cloud
                srand((int)time(0) * 30);
                cloud3Speed = (rand() % 200);

                // How high is the cloud
                srand((int)time(0) * 30);
                float height = (rand() % 450) - 150;
                spriteCloud3.setPosition(-200, height);
                cloud3Active = true;

            }
            else {

                // Move the bee
                spriteCloud3.setPosition(
                    spriteCloud3.getPosition().x +
                    (cloud3Speed * dt.asSeconds()),
                    spriteCloud3.getPosition().y);

                // Has the bee reached the right side of the screen
                if (spriteCloud3.getPosition().x > 1920) {

                    // Setup as a brand new cloud next frame
                    cloud3Active = false;

                }

            }

            // Update score
            std::stringstream ss;
            ss << "Score = " << score;
            scoreText.setString(ss.str());

            // Update branch sprites
            for (int i = 0; i < NUM_BRANCHES; i++) {

                float height = i * 150;

                if (branchPositions[i] == side::LEFT) {

                    // Move sprite to left side
                    branches[i].setPosition(610, height);
                    // Flip sprite
                    branches[i].setRotation(180);

                }
                else if (branchPositions[i] == side::RIGHT) {

                    // Move sprite to right side
                    branches[i].setPosition(1330, height);
                    // Flip sprite
                    branches[i].setRotation(0);

                }
                else {

                    // Hide branch
                    branches[i].setPosition(3000, height);

                }

            }

            // Update flying log
            if (logActive) {

                spriteLog.setPosition(
                    spriteLog.getPosition().x +
                    (logSpeedX * dt.asSeconds()),
                    spriteLog.getPosition().y +
                    (logSpeedY * dt.asSeconds())
                );

                // Has the log reached the right hand edge?
                if (spriteLog.getPosition().x < -100 ||
                    spriteLog.getPosition().x > 2000) {

                    // Set up for new log next frame
                    logActive = false;
                    spriteLog.setPosition(810, 720);

                }

            }

            // Has the player been squished by a branch?
            if (branchPositions[5] == playerSide) {

                // death
                paused = true;
                acceptInput = false;

                // draw gravestone
                spriteRIP.setPosition(525, 760);
                // hide player
                spritePlayer.setPosition(2000, 660);
                // change message text
                messageText.setString("SQUISHED!!");
                // center on screen
                FloatRect textRect = messageText.getLocalBounds();
                messageText.setOrigin(
                    textRect.left +
                    textRect.width / 2.0f,
                    textRect.top +
                    textRect.height / 2.0f);
                messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

                // play death sound
                death.play();

            }

        } // End if(!paused)

        /*************** Draw the scene ***************/
        
        // Clear everything from the last frame
        window.clear();

        // Draw our game scene here
        window.draw(spriteBackground);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        for (int i = 0; i < NUM_BRANCHES; i++) {

            window.draw(branches[i]);

        }

        window.draw(spriteTree);
        window.draw(spritePlayer);
        window.draw(spriteAxe);
        window.draw(spriteLog);
        window.draw(spriteRIP);
        window.draw(spriteBee);

        // Draw timebar
        window.draw(timebar);

        // Draw score
        window.draw(scoreText);

        if (paused) {

            // Draw message
            window.draw(messageText);

        }

        // Show everything we just drew
        window.display();

        /* drawScene(
            window,
            paused,
            spriteBackground,
            spriteCloud1,
            spriteCloud2,
            spriteCloud3,
            spriteTree,
            spriteBee,
            timebar,
            scoreText,
            messageText); */

    }
    
    return 0;

}

// Function definition

void updateBranches(int seed) {

    // Move all branches down one place
    for (int j = NUM_BRANCHES - 1; j > 0; j--) {

        branchPositions[j] = branchPositions[j - 1];

        // Spawn a new branch at the top
        srand((int)time(0) + seed);
        int r = (rand() % 5);

        switch (r) {

        case 0:

            branchPositions[0] = side::LEFT;
            break;

        case 1:

            branchPositions[0] = side::RIGHT;
            break;

        default:

            branchPositions[0] = side::NONE;
            break;

        }

    }

}


/*************** Draw the scene ***************/
/* void drawScene(
    RenderWindow& window,
    Sprite& spriteBee) {

    // Clear everything from the last frame
    window.clear();

    // Draw our game scene here
    window.draw(spriteBackground);
    window.draw(spriteCloud1);
    window.draw(spriteCloud2);
    window.draw(spriteCloud3);
    window.draw(spriteTree);
    window.draw(spriteBee);

    // Draw timebar
    window.draw(timebar);

    // Draw score
    window.draw(scoreText);

    if (paused) {

        // Draw message
        window.draw(messageText);

    }

    // Show everything we just drew
    window.display();

} */