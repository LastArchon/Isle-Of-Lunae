#pragma once

#include <GameObject.h>
#include <string>

class MainMenuBackground : public scene::GameObject
{
public:
	MainMenuBackground(std::string path);
	~MainMenuBackground();
};