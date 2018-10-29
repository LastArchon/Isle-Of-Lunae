#pragma once
#include <string>
namespace core
{
	enum class SystemType : unsigned __int8
	{
		WINDOW,
		INPUT,
		TOTAL_SYSTEMS,
		TIMER,
		AUDIO
	};

	class System
	{
	protected:

	public:
		const SystemType type;
		System(SystemType st);
		virtual ~System();

		virtual bool init();
		virtual void update();
		virtual void draw() const;
		virtual bool shutdown();
	};

}
