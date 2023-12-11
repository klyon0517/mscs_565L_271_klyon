#include "BulletUpdateComponent.h"
#include "WorldState.h"

using namespace sf;

void BulletUpdateComponent::spawnForPlayer(
    Vector2f spawnPosition
)
{
    m_MovingUp = true;
    m_BelongsToPlayer = true;
    m_IsSpawned = true;

    m_TC->getLocation().x = spawnPosition.x;

    // tweak the y location based on the bullet height
    // the x location is alrady centered on player
    m_TC->getLocation().y = spawnPosition.y - m_TC->getSize().y;

    // update the collider
    m_RCC->setOrMoveCollider(
        m_TC->getLocation().x,
        m_TC->getLocation().y,
        m_TC->getSize().x,
        m_TC->getSize().y
    );
}

void BulletUpdateComponent::spawnForInvader(
    Vector2f spawnPosition
)
{
    m_MovingUp = false;
    m_BelongsToPlayer = false;
    m_IsSpawned = true;

    srand((int)time(0));

    m_AlienBulletSpeedModifier = (
        ((rand() % m_ModifierRandomComponent)))
        + m_MinimumAdditionalModifier;
    m_TC->getLocation().x = spawnPosition.x;

    // tweak the bullet similar to player
    m_TC->getLocation().y = spawnPosition.y;

    // update collider
    m_RCC->setOrMoveCollider(
        m_TC->getLocation().x,
        m_TC->getLocation().y,
        m_TC->getSize().x,
        m_TC->getSize().y
    );
}

void BulletUpdateComponent::deSpawn()
{
    m_IsSpawned = false;
}

bool BulletUpdateComponent::isMovingUp()
{
    return m_MovingUp;
}

void BulletUpdateComponent::update(float fps)
{
    if (m_IsSpawned)
    {
        if (m_MovingUp)
        {
            m_TC->getLocation().y -= m_Speed * fps;
        }
        else
        {
            m_TC->getLocation().y +=
                m_Speed / m_AlienBulletSpeedModifier * fps;
        }

        if (m_TC->getLocation().y > WorldState::WORLD_HEIGHT ||
            m_TC->getLocation().y < -2)
        {
            deSpawn();
        }

        // update collider
        m_RCC->setOrMoveCollider(
            m_TC->getLocation().x,
            m_TC->getLocation().y,
            m_TC->getSize().x,
            m_TC->getSize().y
        );
    }
}