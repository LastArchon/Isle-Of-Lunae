#include "ArchonEngine.h"
#include "Scene.h"
#include <iostream>
#include <cassert>


using namespace core;


	std::unique_ptr<ArchonEngine> ArchonEngine::engineInstance = nullptr;
	Scene *currentScene;
	ArchonEngine::ArchonEngine() :  window(), isRunning(false), fps(120)
	{
		managers.push_back(SystemManager::GetInstance());
		currentScene = nullptr;
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
	bool ArchonEngine::Init()
	{
		Debug::DebugInit();
		bool status = window.OnCreate();
		if (status ==  false)
		{
			std::cout << "Failed to initialize window" << std::endl;
			return false;
		}
		//Make sure this is called in this order(vertex has to come first) always check this if unknown errors are occuring with the shader
		//ShaderHandler::GetInstance()->CreateProgram("ColourShader", "Engine/Shaders/ColourVertexShader.glsl", "Engine/Shaders/ColourFragmentShader.glsl");
		// this is for the textures and whatnot
		//ShaderHandler::GetInstance()->CreateProgram("baseShader", "Engine/Shaders/VertexShader.glsl", "Engine/Shaders/FragmentShader.glsl");
		if (isRunning = true) {

			if (!ArchonEngine::GetInstance()->Init())
			{
				Debug::FatalError("Failed to initalize game interface", __FILE__, __LINE__);
				return isRunning = false;
			}

		}

		Debug::FatalError("I think it worked?", __FILE__, __LINE__);

		timer.Start();
		return isRunning = true;

		/*Debug::Log(MessageType::TYPE_INFO, "Initializing the window and first scene", __FILE__, __LINE__);

		window.setWindowSize(1024, 740);
		bool status = window.OnCreate();
		if (status == false) {
			Debug::Log(MessageType::TYPE_FATAL_ERROR, "Failed to initialize a Window and/or OpenGL", __FILE__, __LINE__);
			throw std::string("Failed to initialize a Window and/or OpenGL");
		} 

		

		if (currentScene == nullptr) {
			Debug::Log(MessageType::TYPE_FATAL_ERROR, "Failed to initialize the Scene", __FILE__, __LINE__);
			throw std::string("Failed to initialize the Scene");
		}
		if (currentScene->OnCreate() == false) return false; 
		return true; */

	}
	void ArchonEngine::Run()
	{
		//isRunning = Init();
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




