#pragma once

#include "Spring/Core/Core.h"
#include "Spring/Events/Event.h"

#include "Timestep.h"

namespace Spring {

	class SPRING_API Layer 
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

	protected:
		std::string m_DebugName;
	};

}