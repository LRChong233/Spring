#pragma once

#include "Spring/Layer.h"

#include "Spring/Events/ApplicationEvent.h"
#include "Spring/Events/KeyEvent.h"
#include "Spring/Events/MouseEvent.h"

namespace Spring {

	class SPRING_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}