#include "tulippch.h"
#include "Tulip/Renderer/UniformBuffer.h"
#include "Tulip/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLUniformBuffer.h"


namespace Tulip
{
    Ref<UniformBuffer> UniformBuffer::Create(uint32_t size, uint32_t binding)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:    TULIP_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL:  return CreateRef<OpenGLUniformBuffer>(size, binding);
        }

        TULIP_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}