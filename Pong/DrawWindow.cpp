#include "DrawWindow.h"

void drawWindow(
    RenderWindow& window,
    Bat& bat,
    Ball& ball,
    View& mainView,
    View& hudView,
    Text& hud) {

    window.clear();
    window.setView(mainView);
    window.draw(bat.getShape());
    window.draw(ball.getShape());

    window.setView(hudView);
    window.draw(hud);

    window.display();

}