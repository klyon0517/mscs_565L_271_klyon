#include "BulletUpdateComponent.h"
#include "GameObjectFactoryPlayMode.h"
#include "InvaderUpdateComponent.h"
#include <iostream>
#include "PlayerUpdateComponent.h"
#include "RectColliderComponent.h"
#include "StandardGraphicsComponent.h"
#include "TransformComponent.h"

using namespace std;

void GameObjectFactoryPlayMode::buildGameObject(
    GameObjectBlueprint& bp,
    vector <GameObject>& gameObjects
)
{
    GameObject gameObject;
    gameObject.setTag(bp.getName());
    auto it = bp.getComponentList().begin();
    auto end = bp.getComponentList().end();

    for (it; it != end; ++it)
    {
        if (*it == "Transform")
        {
            gameObject.addComponent(
                make_shared<TransformComponent>(
                    bp.getWidth(),
                    bp.getHeight(),
                    sf::Vector2f(
                        bp.getLocationX(),
                        bp.getLocationY()
                    )
                )
            );
        }
        else if (*it == "Player Update")
        {
            gameObject.addComponent(
                make_shared<PlayerUpdateComponent>()
            );
        }
        else if (*it == "Invader Update")
        {
            gameObject.addComponent(
                make_shared<InvaderUpdateComponent>()
            );
        }
        else if (*it == "Bullet Update")
        {
            gameObject.addComponent(
                make_shared<BulletUpdateComponent>()
            );
        }
        else if (*it == "Standard Graphics")
        {
            shared_ptr<StandardGraphicsComponent> sgp =
                make_shared<StandardGraphicsComponent>();
            gameObject.addComponent(sgp);
            sgp->initializeGraphics(
                bp.getBitmapName(),
                sf::Vector2f(
                    bp.getWidth(),
                    bp.getHeight()
                )
            );
        }
    }

    if (bp.getEncompassingRectCollider())
    {
        shared_ptr<RectColliderComponent> rcc =
            make_shared<RectColliderComponent>(
                bp.getEncompassingRectColliderLabel()
            );
        gameObject.addComponent(rcc);
        rcc->setOrMoveCollider(
            bp.getLocationX(),
            bp.getLocationY(),
            bp.getWidth(),
            bp.getHeight()
        );
    }

    gameObjects.push_back(gameObject);
}