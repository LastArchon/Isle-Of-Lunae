#include "MainMenuBackground.h"



MainMenuBackground::MainMenuBackground(std::string path) :
	GameObject(path)
{
	transform.y = 70;
	transform.x = 0;
	transform.w = 0;
	transform.h = 0;
}


MainMenuBackground::~MainMenuBackground()
{
}
