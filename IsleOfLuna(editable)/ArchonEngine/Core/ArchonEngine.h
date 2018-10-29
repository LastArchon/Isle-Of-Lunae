#ifndef ARCHONENGINE_H
#define ARCHONENGINE_H
#include <SDL.h>

#include "../Systems/Window.h"
#include "Debug.h"
#include "Timer.h"
#include "GameInterface.h"
#include "Scene.h"
//#include "../Rendering/3D/Triangle.h"
//#include "../Rendering/3D/Square.h"
#include "../Graphics/ShaderHandler.h"
#include "../Systems/InputSystem.h"
#include "../Systems/SystemManager.h"
#include "../Camera/Camera.h"

#include <memory>

namespace core
{

	class ArchonEngine
	{
	public:
		ArchonEngine(const ArchonEngine&) = delete;
		ArchonEngine(ArchonEngine&&) = delete;
		ArchonEngine& operator=(const ArchonEngine&) = delete;
		ArchonEngine& operator=(ArchonEngine&&) = delete;




		bool Init();
		void Run();
		void Update(const float deltaTime_);
		void Render();
		bool getIsRunning();
		//void HandleEvents();
		//void SetGameInterface(GameInterface* gameInterface_);

		static ArchonEngine* GetInstance();


	

		
		
	private:
		ArchonEngine();
		~ArchonEngine();
		//Create a vector of the managers
		std::vector<Manager*> managers;
		//Create a mainscene
		


		static std::unique_ptr<ArchonEngine> engineInstance;
		friend std::default_delete<ArchonEngine>;

		
		Window window;
		Timer timer;
		bool isRunning;

		unsigned int fps;

	};


}
#endif // !ARCHONENGINE_H
