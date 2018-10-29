#pragma once

namespace core
{
	/// Interfaces that defines a Manager
	// TODO: Make this a singleton??
	class Manager
	{
	public:
		Manager();
		virtual ~Manager();

		virtual bool init() = 0;
		virtual void update() = 0;
		virtual void draw() const = 0;
		virtual bool shutdown() = 0;
	};
}

