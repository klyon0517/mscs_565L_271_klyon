#include "UpdateScene.h"
#include <sstream>

void updateScene(
    Clock& clock,
    Bat& bat,
    int& score,
    int& lives,
    Text& hud) {
        
    // Measure time
    Time dt = clock.restart();
    bat.update(dt);

    // Update HUD
    std::stringstream ss;
    ss << "Score: " << score << " Lives: " << lives;
    hud.setString(ss.str());

}