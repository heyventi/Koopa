#include "kppch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace kp {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		KP_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		KP_CORE_ASSERT(status, "Failed to initialize Glad!");

		KP_CORE_INFO("OpenGL Renderer");
		KP_CORE_INFO("  Vendor : {0}", glGetString(GL_VENDOR));
		KP_CORE_INFO("  Renderer : {0}", glGetString(GL_RENDERER));
		KP_CORE_INFO("  Version : {0}", glGetString(GL_VERSION));

		KP_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Koopa requires at least OpenGL version 4.5!");

	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}