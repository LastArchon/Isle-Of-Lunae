#include "MainMenu.h"
#include <glew.h>
#include "MainScene.h"
#include <ArchonEngine.h>
#include <SystemManager.h>
#include <InputSystem.h>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace core;


MainMenu::MainMenu(Window& windowRef) : Scene(windowRef)
{
}
void MainMenu::OnResize(int w_, int h_) 
{
	window->setWindowSize(w_, h_);
	//glViewport(0, 0, window->getWidth(), window->getHeight());
}
MainMenu::~MainMenu()
{
	OnDestroy();
}

bool MainMenu::OnCreate()
{

	inputSystem = dynamic_cast<core::InputSystem*>(core::SystemManager::GetInstance()->GetSystem(core::SystemType::INPUT));
	audioSystem = dynamic_cast<core::AudioSystem*>(core::SystemManager::GetInstance()->GetSystem(core::SystemType::AUDIO));
	audioSystem->LoadSound("IsleOfLunae_MainTheme.wav");
	audioSystem->PlayMusic();
	return true;
}

void MainMenu::Update(const float deltaTime_)
{


	if (inputSystem->IsSpacePressed())
	{
		StartGame();
	}
	if (inputSystem->QuitResquested())
	{
		OnDestroy();
	}



}

void MainMenu::Render() const
{
	//glEnable(GL_DEPTH_TEST);
	//glDisable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SDL_GL_SwapWindow(window->GetWindow());
	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());

	}


}

void MainMenu::OnDestroy()
{
}
int MainMenu::StartGame()
{
	static_assert(sizeof(void*) == 4, "This program is not ready for 64-bit build");


	Debug::DebugInit();
	try {
		ArchonEngine::GetInstance()->Run();
	}
	catch (std::string fatalError) {
		std::cout << "Fatal error: " << fatalError << std::endl;
	}
	catch (...) {
		std::cout << "Unknown Fatal error: " << std::endl;
	}
	exit(0);
}