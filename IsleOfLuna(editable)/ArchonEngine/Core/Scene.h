#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include <SDL.h>

#include "../Math/Matrix.h"
#include "../Systems/Window.h"
#include "ArchonEngine.h"


namespace core
{


	class Scene
	{
	protected:
		Window* window;
	public:
		/*Scene(const Scene&) = delete;
		Scene(Scene&&) = delete;
		Scene& operator = (const Scene&) = delete;
		Scene& operator = (Scene&&) = delete; */
		

		Scene();
		virtual ~Scene() = 0;

		virtual bool OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void Render() const = 0;
		virtual void Update(const float deltaTime_) = 0;

	};
}
#endif // !SCENE_H