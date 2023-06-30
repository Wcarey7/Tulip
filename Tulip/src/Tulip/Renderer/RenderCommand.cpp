#include "tulippch.h"
#include "RenderCommand.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"


namespace Tulip 
{
    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}