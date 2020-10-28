#include "kppch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace kp {
    
    Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}