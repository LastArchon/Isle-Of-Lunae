#pragma once
#ifndef _SYSTEMMANAGER_H
#define _SYSTEMMANAGER_H
#include "..\Managers\Manager.h"
#include "System.h"
#include <vector>

namespace core
{
	/*

	template<class T>
	class Singleton
	{

		static T* GetInstance();
	}
	*/

	//std::vector<System*> systems;
	class SystemManager : public Manager
	{
		std::vector<System*> systems;
		SystemManager();

		static SystemManager* m_instance;
	public:
		~SystemManager();

		static SystemManager* GetInstance()
		{
			if (m_instance == nullptr)
			{
				m_instance = new SystemManager();
			}

			return m_instance;
		}

		// TODO: CREATE ANOTHER VERSION THAT USES TEMPLATES GetSystem<InputSystem>()
		System* GetSystem(SystemType t)
		{
			for (System* s : systems)
			{
				if (s->type == t)
					return s;
			}
			return nullptr;
		}

		bool init();
		void update();
		void draw() const;
		bool shutdown();
	};
}

#endif // !_SYSTEMMANAGER_H
