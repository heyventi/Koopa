#include "kppch.h"
#include "Entity.h"

namespace kp
{
	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{

	}
}
