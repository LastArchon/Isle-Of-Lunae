#ifndef WINDOW_H
#define WINDOW_H

//make sure there are in this order
#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include "../Core/Debug.h"
#include <string>
#include <iostream>
#include "System.h"
#define GL3_PROTOTYPES 1

namespace core
{
	class Window 
	{
	public:

		Window();
		~Window();
		Window(const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator=(const Window&) = delete;
		Window& operator=(Window&&) = delete;


		bool OnCreate();
		void OnDestroy();
		void setWindowSize(const int Width_, const int Height_);
		void ToggleFullScreen();
		int getWidth() const;
		int getHeight() const;
		inline SDL_Window* GetWindow() { return window; }

	private:
		SDL_Window* window;
		SDL_GLContext context;
		SDL_Rect winRect;
		bool isInitialized;
		bool isFullScreen;
	protected:
		void GetInstalledOpenGLInfo();
	};

}

#endif // !WINDOW_H
