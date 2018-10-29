#include "Window.h"
#include <glew.h>
#include <cassert>


namespace core
{
	Window::Window() :window(nullptr), winRect(), context(nullptr), isInitialized(false), isFullScreen(false) 
	{
		/// Nothing much to do here. Init the variables, that's it 			
	}



	Window::~Window()
	{
		OnDestroy();
	}

	bool Window::OnCreate() {
		isInitialized = false;

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);/// Enable Depth Cueing (the Z-buffer) 
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);/// Turn on double buffering with a 24bit Z buffer. 
		SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

		/// I am concerned that following functions do nothing
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);


		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			Debug::Log(MessageType::TYPE_FATAL_ERROR, std::string(SDL_GetError()), __FILE__, __LINE__);
			return isInitialized;
		}


		/// Create the SDL window
		window = SDL_CreateWindow("Isle Of Lunae", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			winRect.w, winRect.h, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
		if (window == nullptr) {
			Debug::Log(MessageType::TYPE_FATAL_ERROR, SDL_GetError(), __FILE__, __LINE__);
			return false;
		}

		/// Attach OpenGl to the new Window
		context = SDL_GL_CreateContext(window);
		if (context == nullptr) {
			Debug::Log(MessageType::TYPE_FATAL_ERROR, SDL_GetError(), __FILE__, __LINE__);
			return false;
		}

		/// Fire up the GL Extension Wrangler
		glewExperimental = GL_TRUE;
		GLenum glewError = glewInit();
		if (glewError != GLEW_OK) {
			Debug::Log(MessageType::TYPE_FATAL_ERROR, (char*)glewGetErrorString(glewError), __FILE__, __LINE__);
			assert(0);
		}

		/// This makes the buffer swap syncronize with the monitor's vertical refresh 
		if (SDL_GL_SetSwapInterval(1) < 0) {
			Debug::Log(MessageType::TYPE_WARNING, SDL_GetError(), __FILE__, __LINE__);
		}

		Debug::Log(MessageType::TYPE_INFO, (char*)glewGetString(GLEW_VERSION), __FILE__, __LINE__);

		GetInstalledOpenGLInfo();

		isInitialized = true;
		return true;
	}
	void Window::OnDestroy() {
		SDL_DestroyWindow(window);
		SDL_Quit();
		SDL_GL_DeleteContext(context);
		window = nullptr;
		context = nullptr;
		isInitialized = false;
	}
	void Window::setWindowSize(const int width_, const int height_) {
		winRect.w = width_;
		winRect.h = height_;
	}


	void Window::ToggleFullScreen() {
		isFullScreen = !isFullScreen;
		SDL_SetWindowFullscreen(window, (isFullScreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN));
	}


	int Window::getWidth() const {
		return winRect.w;
	}

	int Window::getHeight() const {
		return winRect.h;
	}
	void Window::GetInstalledOpenGLInfo() {
		/*/// You can to get some info regarding versions and manufacturer
		const GLubyte *version = glGetString(GL_VERSION);
		/// You can also get the version as ints	
		const GLubyte *vendor = glGetString(GL_VENDOR);
		const GLubyte *renderer = glGetString(GL_RENDERER);
		const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);


		std::cout << "GL Version " << version << std::endl;
		std::cout << "Graphics card vendor " << vendor << std::endl;
		std::cout << "Graphics card name " << renderer << std::endl;
		std::cout << "GLSL Version " << glslVersion << std::endl; */
	}
}

