#pragma once
#include "Particle.h"
#include <SFML/Graphics.hpp>

class ParticleSystem : public sf::Drawable
{
private:
    std::vector<Particle> m_Particles;
    sf::VertexArray m_Vertices;
    float m_Duration;
    bool m_IsRunning = false;

public:
    virtual void draw(
        sf::RenderTarget& target,
        sf::RenderStates states) const override;
    void init(int count);
    void emitParticles(sf::Vector2f position);
    void update(float elapsed);
    bool running();
};