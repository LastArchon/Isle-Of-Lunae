#include "MainScene.h"
#include <glew.h>
#include <ArchonEngine.h>
#include <SystemManager.h>
#include <InputSystem.h>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace core;

MainScene::MainScene(Window& windowRef) : Scene(windowRef)
{
}
void MainScene::OnResize(int w_, int h_)
{
	window->setWindowSize(w_, h_);
	//glViewport(0, 0, window->getWidth(), window->getHeight());
}
MainScene::~MainScene()
{
	OnDestroy();
}

bool MainScene::OnCreate()
{

	inputSystem = dynamic_cast<core::InputSystem*>(core::SystemManager::GetInstance()->GetSystem(core::SystemType::INPUT));
	//audioSystem = dynamic_cast<core::AudioSystem*>(core::SystemManager::GetInstance()->GetSystem(core::SystemType::AUDIO));
	//audioSystem->LoadSound("IsleOfLunae_MainTheme.wav");
	//audioSystem->PlayMusic();
	return true;
}

void MainScene::Update(const float deltaTime_)
{



	if (inputSystem->QuitResquested())
	{
		OnDestroy();
	}



}

void MainScene::Render() const
{
	//glEnable(GL_DEPTH_TEST);
	//glDisable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SDL_GL_SwapWindow(window->GetWindow());
	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());

	}


}

void MainScene::OnDestroy()
{
}