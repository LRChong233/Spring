
#include <Spring.h>

class Sandbox : public Spring::Application {
public:
	Sandbox(){}
	~Sandbox(){}
};

Spring::Application* Spring::CreateApplication()
{
	return new Sandbox();
}