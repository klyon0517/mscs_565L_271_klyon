#include <SFML/Audio.hpp>
#include "SoundManager.h"

using namespace sf;

SoundManager::SoundManager()
{
    // Load the sound into the buffers
    m_FireBuffer.loadFromFile("sound/fire1.wav");
    m_FallInFireBuffer.loadFromFile("sound/fallinfire.wav");
    m_FallInWaterBuffer.loadFromFile("sound/fallinwater.wav");
    m_JumpBuffer.loadFromFile("sound/jump.wav");
    m_ReachGoalBuffer.loadFromFile("sound/reachgoal.wav");

    // Associate the sounds with the buffers
    m_Fire1Sound.setBuffer(m_FireBuffer);
    m_Fire2Sound.setBuffer(m_FireBuffer);
    m_Fire3Sound.setBuffer(m_FireBuffer);
    m_FallInFireSound.setBuffer(m_FallInFireBuffer);
    m_FallInWaterSound.setBuffer(m_FallInWaterBuffer);
    m_JumpSound.setBuffer(m_JumpBuffer);
    m_ReachGoalSound.setBuffer(m_ReachGoalBuffer);

    // When the player is 150 px away, full sound
    float minDistance = 150;

    // The sound reduces steadily as the player moves away
    float attenuation = 15;

    // set all the attenuation levels
    m_Fire1Sound.setAttenuation(attenuation);
    m_Fire2Sound.setAttenuation(attenuation);
    m_Fire3Sound.setAttenuation(attenuation);

    // set all the minimum distance levels
    m_Fire1Sound.setMinDistance(minDistance);
    m_Fire2Sound.setMinDistance(minDistance);
    m_Fire3Sound.setMinDistance(minDistance);

    // loop all the fire sounds when they are played
    m_Fire1Sound.setLoop(true);
    m_Fire2Sound.setLoop(true);
    m_Fire3Sound.setLoop(true);
}

void SoundManager::playFire(
    Vector2f emitterLocation, Vector2f listenerLocation)
{
    // Where is the listener? Thomas
    Listener::setPosition(
        listenerLocation.x, listenerLocation.y, 0.0f);

    switch (m_NextSound)
    {
    case 1:
        // Locate / move the source of the sound
        m_Fire1Sound.setPosition(
            emitterLocation.x, emitterLocation.y, 0.0f);

        if (m_Fire1Sound.getStatus() == Sound::Status::Stopped)
        {
            // Play the sound if it's not already
            m_Fire1Sound.play();
        }

        break;

    case 2:
        // Locate / move the source of the sound
        m_Fire2Sound.setPosition(
            emitterLocation.x, emitterLocation.y, 0.0f);

        if (m_Fire2Sound.getStatus() == Sound::Status::Stopped)
        {
            // Play the sound if it's not already
            m_Fire2Sound.play();
        }

        break;

    case 3:
        // Locate / move the source of the sound
        m_Fire3Sound.setPosition(
            emitterLocation.x, emitterLocation.y, 0.0f);

        if (m_Fire3Sound.getStatus() == Sound::Status::Stopped)
        {
            // Play the sound if it's not already
            m_Fire3Sound.play();
        }

        break;

    }

    // Increment to the next fire sound
    m_NextSound++;

    // Go back to 1 when the 3rd sound has started
    if (m_NextSound > 3)
    {
        m_NextSound = 1;
    }
}

void SoundManager::playFallInFire()
{
    m_FallInFireSound.setRelativeToListener(true);
    m_FallInFireSound.play();
}

void SoundManager::playFallInWater()
{
    m_FallInWaterSound.setRelativeToListener(true);
    m_FallInWaterSound.play();
}

void SoundManager::playJump()
{
    m_JumpSound.setRelativeToListener(true);
    m_JumpSound.play();
}

void SoundManager::playReachGoal()
{
    m_ReachGoalSound.setRelativeToListener(true);
    m_ReachGoalSound.play();
}