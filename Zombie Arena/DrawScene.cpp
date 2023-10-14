#include "DrawScene.h"
using namespace sf;

void drawScene
(
    RenderWindow& window,
    View& mainView,
    State& state,
    Player& player,
    VertexArray& background,
    Texture& textureBackground
)
{
    if (state == State::PLAYING)
    {
        window.clear();

        // set the mainView to be displayed in the window
        window.setView(mainView);

        // Draw the background
        window.draw(background, &textureBackground);
        
        // Draw the player
        window.draw(player.getSprite());
    }

    if (state == State::LEVELING_UP)
    {

    }

    if (state == State::PAUSED)
    {

    }

    if (state == State::GAME_OVER)
    {

    }

    window.display();
}