#pragma once

#include "Koopa/Core/Layer.h"
#include "Koopa/Events/KeyEvent.h"
#include "Koopa/Events/MouseEvent.h"
#include "Koopa/Events/ApplicationEvent.h"

namespace kp {

	class KOOPA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};

}