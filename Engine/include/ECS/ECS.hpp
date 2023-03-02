#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

namespace DontLaugh
{
	class Component;

	class Entity;

	class System;

	constexpr std::size_t maxComponents = 32;

	using ComponentID = std::size_t;
	using ComponentBitSet = std::bitset<maxComponents>;
	using ComponentArray = std::array<Component*, maxComponents>;

	inline ComponentID GetComponentTypeID()
	{
		static ComponentID lastID = 0;
		return ++lastID;
	}

	template<typename T>
	inline ComponentID GetComponentTypeID() noexcept
	{
		static ComponentID typeID = GetComponentTypeID();
		return typeID;
	}

	class Component
	{
	public:
		virtual void Init() { }

		virtual void Update() { }

		virtual void Render() { }

		virtual ~Component() = default;

		inline void SetOwner(Entity* entity) { m_Owner = entity; }

	protected:
		template<typename T>
		inline T* GetOwnerComponent()
		{
			static_assert(std::is_base_of<Component, T>::value, "T must be subclass of Component");
			return &(m_Owner->GetComponent<T>());
		}

	protected:
		Entity* m_Owner;
	};

	class Entity
	{
	public:
		inline void Update() const
		{
			for (auto& com: m_Components)
				com->Update();
		}

		inline void Draw() const
		{
			for (auto& com: m_Components)
				com->Render();
		}

		inline bool IsActive() const { return m_Active; }

		inline void Destroy() { m_Active = false; }

		template<typename T>
		inline bool HasComponent() const
		{
			return m_ComponentBitSet[GetComponentTypeID<T>()];
		}

		template<typename T, typename... TArgs>
		T& AddComponent(TArgs&& ...args)
		{
			T* comp { new T(std::forward<TArgs>(args)...) };
			comp->SetOwner(this);

			std::unique_ptr<Component> uPtr { comp };
			m_Components.emplace_back(std::move(uPtr));

			const ComponentID id = GetComponentTypeID<T>();
			m_ComponentArray[id] = comp;
			m_ComponentBitSet[id] = true;

			comp->Init();
			return *comp;
		}

		template<typename T>
		inline T& GetComponent() const
		{
			Component* ptr = m_ComponentArray[GetComponentTypeID<T>()];
			return *static_cast<T*>(ptr);
		}

	private:
		bool m_Active { true };

		std::vector<std::unique_ptr<Component>> m_Components;
		ComponentArray m_ComponentArray;
		ComponentBitSet m_ComponentBitSet;
	};

	class EcsManager
	{
	public:
		~EcsManager()
		{
			for (auto& en: m_Entities)
				en.release();
		}

		void Update()
		{
			for (auto& en: m_Entities)
				en->Update();
		}

		void Render()
		{
			for (auto& en: m_Entities)
				en->Draw();
		}

		void Refresh()
		{
			m_Entities.erase(
				std::remove_if(
					m_Entities.begin(), m_Entities.end(),
					[](const std::unique_ptr<Entity>& entity)
					{
						return !entity->IsActive();
					}
				),
				std::end(m_Entities)
			);
		}

		Entity* AddEntity()
		{
			auto* en = new Entity();
			std::unique_ptr<Entity> uPtr { en };
			m_Entities.emplace_back(std::move(uPtr));
			return en;
		}

	private:
		std::vector<std::unique_ptr<Entity>> m_Entities;
	};
}
