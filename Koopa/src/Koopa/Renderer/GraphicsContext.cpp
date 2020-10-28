#include "kppch.h"
#include "Koopa/Renderer/GraphicsContext.h"

#include "Koopa/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace kp {

    Scope<GraphicsContext> GraphicsContext::Create(void* window)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    KP_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
        }

        KP_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}