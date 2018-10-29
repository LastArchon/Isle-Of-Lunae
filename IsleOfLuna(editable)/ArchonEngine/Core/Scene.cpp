#include "Scene.h"

using namespace core;
/// All this constructor does is set the windowPtr 
Scene::Scene(Window& windowRef) : window(&windowRef) {}
Scene::~Scene() {}