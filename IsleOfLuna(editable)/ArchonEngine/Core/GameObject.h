#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
namespace scene
{
	class GameObject
	{
	public:
		SDL_Rect transform;
		SDL_Surface* objectImage;

		GameObject(std::string filePath);
		virtual ~GameObject();

		virtual bool init();
		virtual void update();
		virtual void draw() const;
		virtual bool shutdown();
	};
}

