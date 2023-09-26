#include "DrawWindow.h"

void drawWindow(
    RenderWindow& window,
    Bat& bat,
    Ball& ball,
    Text& hud) {

    window.clear();
    window.draw(hud);
    window.draw(bat.getShape());
    window.draw(ball.getShape());
    window.display();

}