#include "tulippch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>


namespace Tulip 
{
    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        : m_WindowHandle(windowHandle)
    {
        TULIP_CORE_ASSERT(windowHandle, "Window handle is null");
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        TULIP_CORE_ASSERT(status, "Could not initialize Glad");

        TULIP_CORE_INFO("OpenGl Info :");
        TULIP_CORE_INFO("   Vendor: {0}", (const char*)glGetString(GL_VENDOR));
        TULIP_CORE_INFO("   Renderer: {0}", (const char*)glGetString(GL_RENDERER));
        TULIP_CORE_INFO("   Version: {0}", (const char*)glGetString(GL_VERSION));
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}