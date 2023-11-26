#include "GameOverUIPanel.h"
#include "GameScreen.h"

using namespace sf;

bool GameScreen::m_GameOver;

GameOverUIPanel::GameOverUIPanel(Vector2i res) :
    UIPanel(
        res,
        (res.x / 10) * 3,
        res.y / 2, // 50% of resolution from top
        (res.x / 10) * 3, // 1/3 width of resolution
        res.y / 6, // as tall as 1/6 resolution
        50, 255, 255, 255 // a, r, g, b
    )
{
    m_ButtonWidth = res.x / 20;
    m_ButtonHeight = res.y / 20;
    m_ButtonPadding = res.x / 100;

    m_Text.setFillColor(Color(0, 255, 0, 255)); // green
    m_Text.setString("Game Over");

    m_Font.loadFromFile("fonts/Roboto-Bold.ttf");
    m_Text.setFont(m_Font);
    m_Text.setPosition(
        Vector2f(
            m_ButtonPadding,
            (m_ButtonPadding * 2) + m_ButtonHeight
        )
    );
    m_Text.setCharacterSize(60);

    initialiseButtons();
}

void GameOverUIPanel::initialiseButtons()
{
    addButton(
        m_ButtonPadding,
        m_ButtonPadding,
        m_ButtonWidth,
        m_ButtonHeight,
        0,
        255,
        0,
        "Play"
    );

    addButton(
        m_ButtonWidth + (m_ButtonPadding * 2),
        m_ButtonPadding,
        m_ButtonWidth,
        m_ButtonHeight,
        255,
        0,
        0,
        "Home"
    );
}

void GameOverUIPanel::draw(RenderWindow& window)
{
    if (GameScreen::m_GameOver)
    {
        show();
        UIPanel::draw(window);
        window.draw(m_Text);
    }
    else
    {
        hide();
    }
}
