#include "tulippch.h"
#include "Tulip/Renderer/Buffer.h"
#include "Tulip/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"


namespace Tulip 
{
    Ref<VertexArray> VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:     TULIP_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
            case RendererAPI::API::OpenGL:   return CreateRef<OpenGLVertexArray>();
        }

        TULIP_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}