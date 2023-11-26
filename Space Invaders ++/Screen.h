#pragma once
#include "InputHandler.h"
#include "ScreenManagerRemoteControl.h"
#include <SFML/Graphics.hpp>
#include "UIPanel.h"
#include <vector>

class InputHandler;

class Screen
{
private:
    std::vector<std::shared_ptr<InputHandler>> m_InputHandlers;
    std::vector<std::unique_ptr<UIPanel>> m_Panels;

protected:
    void addPanel(
        std::unique_ptr<UIPanel> uip,
        ScreenManagerRemoteControl* smrc,
        std::shared_ptr<InputHandler> ih
    );

public:
    virtual void initialise();
    virtual void update(float fps);
    virtual void draw(sf::RenderWindow& window);
    void handleInput(sf::RenderWindow& window);
    sf::View m_View;
};
