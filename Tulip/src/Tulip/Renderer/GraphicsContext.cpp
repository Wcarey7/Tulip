#include "tulippch.h"
#include "Tulip/Renderer/GraphicsContext.h"
#include "Tulip/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"


namespace Tulip
{
    Scope<GraphicsContext> GraphicsContext::Create(void* window)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:    TULIP_CORE_ASSERT(false, "RendererAPI::None is currently not supported."); return nullptr;
            case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
        }

        TULIP_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
