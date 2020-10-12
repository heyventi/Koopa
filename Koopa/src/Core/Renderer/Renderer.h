#pragma once

#include "RenderCommand.h"
#include "Core/Renderer/RendererAPI.h"

namespace kp {

	class Renderer
	{
	public:
		static void BeginScene();
		static void EndScene();
				
        static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

        inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};
}
