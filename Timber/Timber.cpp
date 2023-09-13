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

// Make code easier to type with "using namespace"
using namespace sf;

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

    // Load graphics into the textures
    textureBackground.loadFromFile("graphics/background.png");
    textureTree.loadFromFile("graphics/tree.png");
    textureBee.loadFromFile("graphics/bee.png");
    textureCloud.loadFromFile("graphics/cloud.png");

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

    while (window.isOpen()) {

        /*************** Handle the player's input ***************/

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {

            window.close();

        }

        // Start the game
        if (Keyboard::isKeyPressed(Keyboard::Enter)) {

            paused = false;

        }

        /*************** Update the scene ***************/

        if (!paused) {

            // Measure time
            Time dt = clock.restart();

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

                // Move the bee
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

        } // End if(!paused)

        /*************** Draw the scene ***************/
        
        // Clear everything from the last frame
        window.clear();

        // Draw our game scene here
        window.draw(spriteBackground);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        window.draw(spriteTree);
        window.draw(spriteBee);

        // Draw score
        window.draw(scoreText);

        if (paused) {

            // Draw message
            window.draw(messageText);

        }

        // Show everything we just drew
        window.display();

    }
    
    return 0;

}