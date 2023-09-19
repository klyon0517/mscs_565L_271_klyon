#include "updateScene.h"

void updateScene(
    Clock& clock,
    bool& paused,
    bool& bansheeActive,
    float& bansheeSpeed,
    Sprite spriteBanshees[3]) {

    if (!paused) {

        // Measure time
        Time dt = clock.restart();

        // Setup the Banshee
        if (!bansheeActive) {
                                    
            for (int i = 0; i < 3; i++) {

                // How fast is the Banshee
                // srand((int)time(0));
                bansheeSpeed = rand() % 250 + 50;

                // How high is the Banshee
                // srand((int)time(0) * 10);
                float height = rand() % 300 + 100;
                spriteBanshees[i].setPosition(2000, height);

                bansheeActive = true;

            }

        }
        else {

            for (int i = 0; i < 3; i++) {

                // Move the Banshee
                spriteBanshees[i].setPosition(
                    spriteBanshees[i].getPosition().x -
                    (bansheeSpeed * dt.asSeconds()),
                    spriteBanshees[i].getPosition().y);

                // Has the Banshee reached the left side of the screen
                if (spriteBanshees[i].getPosition().x < -100) {

                    // Setup as a brand new Banshee next frame
                    bansheeActive = false;

                }

            }

        }

    }

}