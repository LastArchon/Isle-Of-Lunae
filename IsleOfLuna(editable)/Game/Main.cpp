#include <iostream>
#include <ArchonEngine.h>

#include "Scenes/MainMenu.h"
#include "../ArchonEngine/Core/Debug.h"

using namespace core;

int main(int argc, char* args[])
{

	/*ArchonEngine e(new MainMenu());
	if (e.Init())
	{
		e.Run();
	}

	return -1; */

	/// c11: This is evaluated at compile time, if void* != 4 then
	/// this must be a 64-bit build - just a quick test
	static_assert(sizeof(void*) == 4, "This program is not ready for 64-bit build");


	Debug::DebugInit();
	try {
		ArchonEngine::GetInstance()->Run();
	}
	catch (std::string fatalError) {
		std::cout << "Fatal error: " << fatalError << std::endl;
	}
	catch (...) {
		std::cout << "Unknown Fatal error: " << std::endl;
	}
	exit(0); 

}