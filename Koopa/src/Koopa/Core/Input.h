#pragma once

#include <glm/glm.hpp>
#include "Koopa/Core/KeyCodes.h"
#include "Koopa/Core/MouseCodes.h"

namespace kp {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}