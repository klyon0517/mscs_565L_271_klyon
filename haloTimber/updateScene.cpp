#include "updateScene.h"

void updateScene(
    Clock& clock,
    bool& paused,
    bool& bansheeActive,
    float& bansheeSpeed,
    Sprite& spriteBanshee) {

    if (!paused) {

        // Measure time
        Time dt = clock.restart();

        // Setup the Banshee
        if (!bansheeActive) {

            // How fast is the Banshee
            srand((int)time(0));
            bansheeSpeed = (rand() % 200) + 200;

            // How high is the Banshee
            srand((int)time(0) * 10);
            float height = (rand() % 200) + 100;
            spriteBanshee.setPosition(2000, height);
            bansheeActive = true;

        }
        else {

            // Move the Banshee
            spriteBanshee.setPosition(
                spriteBanshee.getPosition().x -
                (bansheeSpeed * dt.asSeconds()),
                spriteBanshee.getPosition().y);

            // Has the Banshee reached the left side of the screen
            if (spriteBanshee.getPosition().x < -100) {

                // Setup as a brand new Banshee next frame
                bansheeActive = false;

            }

        }

    }

}