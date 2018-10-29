#include "System.h"

namespace core
{
	System::System(SystemType st) :
		type(st)
	{
	}

	System::~System()
	{
	}

	bool System::init()
	{
		return true;
	}
	void System::update()
	{

	}
	void System::draw() const
	{

	}
	bool System::shutdown()
	{
		return true;
	}
}
