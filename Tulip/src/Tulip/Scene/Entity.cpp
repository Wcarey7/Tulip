#include "tulippch.h"
#include "Tulip/Scene/Entity.h"


namespace Tulip
{
    Entity::Entity(entt::entity handle, Scene* scene)
        : m_EntityHandle(handle), m_Scene(scene)
    {
    }
}