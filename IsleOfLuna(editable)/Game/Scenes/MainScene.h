#pragma once
#include <Scene.h>
#include <ArchonEngine.h>
#include <Window.h>
namespace core
{
	class InputSystem;

class MainScene : public Scene
{
	core::InputSystem* inputSystem;
public:

	 MainScene();
	virtual ~MainScene();

	/// Delete these possible default constructors and operators  
	MainScene(const MainScene&) = delete;
	MainScene(MainScene &&) = delete;
	MainScene& operator=(const MainScene &) = delete;
	MainScene& operator=(MainScene &&) = delete;

	virtual bool OnCreate();
	virtual void OnDestroy();
	virtual void Update(const float deltaTime);
	virtual void Render() const;
	virtual void OnResize(const int, const int);
};
};
