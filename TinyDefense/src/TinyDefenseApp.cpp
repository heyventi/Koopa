
#include "Koopa.h"
#include "Koopa/Core/EntryPoint.h"

#include "Platform/OpenGL/OpenGLShader.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "TinyDefense2D.h"

class TinyDefense : public kp::Application
{
public:
	TinyDefense()
	{
		//PushLayer(new ExampleLayer());
		PushLayer(new TinyDefense2D());
	}

	~TinyDefense()
	{
	}
};

kp::Application* kp::CreateApplication()
{
	return new TinyDefense();
}