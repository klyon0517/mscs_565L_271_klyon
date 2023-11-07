#include "Thomas.h"
#include "TextureHolder.h"

using namespace sf;

Thomas::Thomas()
{
    // Associate a texture with the sprite
    m_Sprite =
        Sprite(TextureHolder::GetTexture("graphics/thomas.png"));
    m_JumpDuration = .45;
}

// A virtual function
bool Thomas::handleInput()
{
    m_JustJumped = false;

    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        // start a jump if not already jumping
        // but only if standing on a block
        // not falling
        if (!m_IsJumping && !m_IsFalling)
        {
            m_IsJumping = true;
            m_TimeThisJump = 0;
            m_JustJumped = true;
        }
    }
    else
    {
        m_IsJumping = false;
        m_IsFalling = false;
    }

    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        m_LeftPressed = true;
    }
    else
    {
        m_LeftPressed = false;
    }

    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        m_RightPressed = true;
    }
    else
    {
        m_RightPressed = false;
    }

    return m_JustJumped;
}