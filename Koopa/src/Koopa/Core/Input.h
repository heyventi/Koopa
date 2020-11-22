#pragma once

#include "Koopa/Core/Base.h"
#include "Koopa/Core/KeyCodes.h"
#include "Koopa/Core/MouseCodes.h"

namespace kp {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}