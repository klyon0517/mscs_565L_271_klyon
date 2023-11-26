#pragma once
#include "UIPanel.h"

class GameOverUIPanel : public UIPanel
{
private:
    void initialiseButtons();
    
public:
    GameOverUIPanel(sf::Vector2i res);
    virtual void draw(sf::RenderWindow& window);
};