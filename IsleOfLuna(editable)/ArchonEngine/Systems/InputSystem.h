#pragma once
#include "System.h"

namespace core
{
	class InputSystem : public System
	{
		bool quitResquested;

		bool m_leftPressed = false;
		bool m_rightPressed = false;
		bool m_upPressed = false;
		bool m_downPressed = false;
		bool m_spacePressed = false;
		bool m_enterPressed = false;

	public:
		InputSystem();
		~InputSystem();

		void update() override;

		inline bool IsLeftPressed() const { return m_leftPressed; }
		inline bool IsRightPressed() const { return m_rightPressed; }
		inline bool IsUpPressed() const { return m_upPressed; }
		inline bool IsDownPressed() const { return m_downPressed; }
		inline bool IsSpacePressed() const { return m_spacePressed; }
		inline bool IsEnterPressed() const { return m_enterPressed; }

		inline bool QuitResquested() const { return quitResquested; }
	};
}

