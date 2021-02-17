#pragma once

#include "Scene.h"

#include "entt.hpp"

namespace kp
{
	class Entity
	{
	public:
		Entity() = default;
		Entity(entt::entity handle, Scene* scene);
		Entity(const Entity& other) = default;

		template<typename T, typename... Args>
		T& AddComponent(Args&&... args)
		{
			KP_CORE_ASSERT(!HasComponemt<T>(), "Entiry already has component");
			return m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)... );
		}

		template<typename T>
		T& GetComponent()
		{
			KP_CORE_ASSERT(HasComponemt<T>(), "Entity does not have component!");
			return m_Scene->m_Registry.get<T>(m_EntityHandle);
		}

		template<typename T>
		bool HasComponemt()
		{
			return m_Scene->m_Registry.has<T>(m_EntityHandle);
		}

		template<typename T>
		void RemoveComponent()
		{
			KP_CORE_ASSERT(HasComponemt<T>(), "Entity does not have component!");
			return m_Scene->m_Registry.remove<T>(m_EntityHandle);
		}

		operator bool() const { return m_EntityHandle != entt::null; }

	private:
		entt::entity m_EntityHandle{ entt::null };
		Scene* m_Scene = nullptr;
	};

}

