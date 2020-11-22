#pragma once

#include "Koopa/Core/Layer.h"
#include "Koopa/Events/KeyEvent.h"
#include "Koopa/Events/MouseEvent.h"
#include "Koopa/Events/ApplicationEvent.h"

namespace kp {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};

}