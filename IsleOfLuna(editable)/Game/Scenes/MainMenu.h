#ifndef MAINMENU_H
#define MAINMENU_H
#include <Scene.h>
#include <AudioSystem.h>
#include <ArchonEngine.h>
#include <Window.h>
#include "../GameObjects/Images/MainMenuBackground.h"
namespace core
{
	class InputSystem;
	class AudioSystem;
	class Window;

	
	class MainMenu : public Scene
	{
		//Create the objects that will be displayed in the scene
		//MainMenuBackground bgImage;

		core::InputSystem* inputSystem;
		core::AudioSystem* audioSystem;
		Mix_Music *music;
		

	public:
		/// Delete these possible default constructors and operators  
		MainMenu(const MainMenu&) = delete;
		MainMenu(MainMenu &&) = delete;
		MainMenu& operator=(const MainMenu &) = delete;
		MainMenu& operator=(MainMenu &&) = delete;

		explicit MainMenu(Window& windowRef);
		virtual ~MainMenu();

		virtual bool OnCreate();
		virtual void OnDestroy();
		virtual void Update(const float deltaTime_) override;
		virtual void Render() const;
		virtual void OnResize(const int, const int);
		int StartGame();
	};
};
#endif //!MAINMENU_H

