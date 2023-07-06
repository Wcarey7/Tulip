#include "tulippch.h"
#include "Tulip/Renderer/Framebuffer.h"
#include "Tulip/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLFramebuffer.h"


namespace Tulip
{
    Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:     TULIP_CORE_ASSERT(false, "RendeerAPI::None is currently not supported"); return nullptr;
            case RendererAPI::API::OpenGL:   return CreateRef<OpenGLFramebuffer>(spec);
        }

        TULIP_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}