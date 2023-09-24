#include "DrawWindow.h"

void drawWindow(
    RenderWindow& window,
    Bat& bat,
    Text& hud) {

    window.clear();
    window.draw(hud);
    window.draw(bat.getShape());
    window.display();

}