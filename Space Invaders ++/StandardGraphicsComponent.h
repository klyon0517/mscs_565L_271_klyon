#pragma once
#include "Component.h"
#include "GraphicsComponent.h"
#include <string>

class Component;

class StandardGraphicsComponent : public GraphicsComponent
{
private:
    sf::Sprite m_Sprite;
    std::string m_SpecificType = "standard";

public:
    // from Component base class
    std::string Component::getSpecificType()
    {
        return m_SpecificType;
    }

    void Component::start(
        GameObjectSharer* gos,
        GameObject* self
    ){}

    // from GraphicsComponent
    void draw(
        sf::RenderWindow& window,
        std::shared_ptr<TransformComponent> t
    ) override;

    void initializeGraphics(
        std::string bitmapName,
        sf::Vector2f objectSize
    ) override;
};