#include "tulippch.h"
#include "Tulip/Renderer/RenderCommand.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"


namespace Tulip 
{
    Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}