#include "ArchonEngine.h"

#include <iostream>
#include <cassert>


using namespace core;


	std::unique_ptr<ArchonEngine> ArchonEngine::engineInstance = nullptr;

	ArchonEngine::ArchonEngine() :  window(), isRunning(false), fps(120)
	{
		managers.push_back(SystemManager::GetInstance());
		
	}


	ArchonEngine::~ArchonEngine()
	{
		for (Manager *m : managers)
		{
			delete m;
			m = nullptr;
		}
		window.OnDestroy();
		isRunning = false;
		managers.clear();
	}
	ArchonEngine* ArchonEngine::GetInstance()
	{
		if (engineInstance.get() == nullptr)
		{
			engineInstance.reset(new ArchonEngine);
		}
		return engineInstance.get(); 
	}
	void ArchonEngine::SetScene(class Scene* s) {

		currentScene = s;

	}
	bool ArchonEngine::Init()
	{
		
		Debug::Log(MessageType::TYPE_INFO, "Initializing the window and first scene", __FILE__, __LINE__);

		window.setWindowSize(1024, 740);
		bool status = window.OnCreate();
		if (status == false) {
			Debug::Log(MessageType::TYPE_FATAL_ERROR, "Failed to initialize a Window and/or OpenGL", __FILE__, __LINE__);
			throw std::string("Failed to initialize a Window and/or OpenGL");
		}
		
		//to fix, need to find some way to assign the currentscene to the window
		
		if (currentScene == nullptr) {
			Debug::Log(MessageType::TYPE_FATAL_ERROR, "Failed to initialize the Scene", __FILE__, __LINE__);
			throw std::string("Failed to initialize the Scene");
		}
		if (currentScene->OnCreate() == false) return false;
		SDL_Delay(20000);
		return true;
		
		

	}
	void ArchonEngine::Run()
	{
		
		Timer timer;
		timer.Start();
		
		while (isRunning) {

			timer.UpdateFrameTicks();
			Update(timer.GetDeltaTime());
			Render();
			SDL_Delay(timer.GetSleepTime(fps));

		}

	}
	bool ArchonEngine::getIsRunning()
	{
		return isRunning;
	}


	void ArchonEngine::Update(const float deltaTime_)
	{
		assert(currentScene);
		currentScene->Update(deltaTime_);
		for (Manager *m : managers)
		{
			m->update();
		}
		currentScene->Update(deltaTime_);


	}

	void ArchonEngine::Render()
	{

		assert(currentScene);
		currentScene->Render();
	}




