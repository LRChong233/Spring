#pragma once

#include "Spring/Core.h"
#include "Spring/Events/Event.h"

namespace Spring {

	class SPRING_API Layer 
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

	protected:
		std::string m_DebugName;
	};

}