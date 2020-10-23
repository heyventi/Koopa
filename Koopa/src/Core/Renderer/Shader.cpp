#include "kppch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace kp {

    Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:    KP_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::API::OpenGL:  return new OpenGLShader(vertexSrc, fragmentSrc);
        }

        KP_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}