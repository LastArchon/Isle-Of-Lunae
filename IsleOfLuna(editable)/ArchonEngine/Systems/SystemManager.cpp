#include "SystemManager.h"
#include "InputSystem.h"
#include "Window.h"

namespace core
{
	SystemManager* SystemManager::m_instance = nullptr;

	SystemManager::SystemManager()
	{
		systems.push_back(new InputSystem());
		//systems.push_back(new Window());
	}

	SystemManager::~SystemManager()
	{
	}

	bool SystemManager::init()
	{
		for (System* s : systems)
		{
			if (!s->init())
				return false;
		}

		return true;
	}

	void SystemManager::update()
	{
		for (System* s : systems)
		{
			s->update();
		}
	}

	void SystemManager::draw() const
	{
		for (System* s : systems)
		{
			s->draw();
		}
	}

	bool SystemManager::shutdown()
	{
		for (System* s : systems)
		{
			if (!s->shutdown())
				return false;

			delete s;
			s = nullptr;
		}

		systems.clear();

		return true;
	}
}