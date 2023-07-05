#include "tulippch.h"
#include "Tulip/Renderer/Buffer.h"

#include "Tulip/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"


namespace Tulip 
{
    Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:     TULIP_CORE_ASSERT(false, "RendeerAPI::None is currently not supported"); return nullptr;
            case RendererAPI::API::OpenGL:   return CreateRef<OpenGLVertexBuffer>(vertices, size);
        }

        TULIP_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }

    Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:     TULIP_CORE_ASSERT(false, "RendeerAPI::None is currently not supported"); return nullptr;
            case RendererAPI::API::OpenGL:   return CreateRef<OpenGLIndexBuffer>(indices, count);
        }

        TULIP_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}