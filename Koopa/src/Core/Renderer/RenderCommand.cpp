#include "kppch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace kp {

    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}