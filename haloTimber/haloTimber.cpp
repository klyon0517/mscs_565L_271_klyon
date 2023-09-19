/*  haloTimber

    * Course: Game Design & Programming I
    * Type: Independent Study
    * SEC: 565L 271
    * CRN: 13015
    * Instructor: Matthew Johnson
    * Software: Game #1 (Beginning C++ Game Programming, Horton, J.)
    * Filename: haloTimber.cpp
    * Author: Kerry Lyon
    * Created: September 17, 2023
    * Due: September 19, 2023

    * Main function for the haloTimber game.

*/

#include "playerInput.h"
#include "updateScene.h"
#include "windowDisplay.h"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

int main() {

    bool paused = true;
    bool bansheeActive = false;

    float bansheeSpeed = 0.0f;

    Clock clock;

    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Halo Timber", Style::Fullscreen);
    Vector2f targetSize(1920.0f, 1080.0f);

    /***************     TEXT     **************/
    Font font;
    font.loadFromFile("fonts/Halo.ttf");

    Text messageText;
    messageText.setFont(font);
    messageText.setString("Press Enter to Start");
    messageText.setCharacterSize(125);
    messageText.setFillColor(Color::White);
    messageText.setOutlineColor(Color::Black);
    messageText.setOutlineThickness(5);
    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin(
        textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f
    );
    messageText.setPosition(1920 / 2.0f, 250);



    /***************     TEXTURES     **************/
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/halo_bkgnd.jpg");

    Texture textureGruntLine;
    textureGruntLine.loadFromFile("graphics/grunt_line.png");

    Texture textureBanshee;
    textureBanshee.loadFromFile("graphics/banshee.png");



    /**************     SPRITES     **************/
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setScale(
        targetSize.x / spriteBackground.getLocalBounds().width,
        targetSize.y / spriteBackground.getLocalBounds().height);
    spriteBackground.setPosition(0, 0);
    
    Sprite spriteGruntLine;
    spriteGruntLine.setTexture(textureGruntLine);
    spriteGruntLine.setPosition(500, 500);

    Sprite spriteBanshees[3];
    srand(time(0));

    for (int i = 0; i < 3; i++) {

        float randomScale = ((float)rand()) / (RAND_MAX / (0.35 - 0.15));
        //float randomScale = ((float)(rand() % 100000000) + 1) / 100000001;
        randomScale = roundf(randomScale * 100) / 100;

        int height = rand() % 200 + 200;

        spriteBanshees[i].setTexture(textureBanshee);
        spriteBanshees[i].scale(randomScale, randomScale);
        spriteBanshees[i].setPosition(-120, height);

    }



    while (window.isOpen()) {

        playerInput(
            window,
            paused);

        updateScene(
            clock,
            paused,
            bansheeActive,
            bansheeSpeed,
            spriteBanshees);

        windowDisplay(
            window,
            paused,
            spriteBackground,
            messageText,
            spriteGruntLine,
            spriteBanshees);
               
    }

    return 0;

}