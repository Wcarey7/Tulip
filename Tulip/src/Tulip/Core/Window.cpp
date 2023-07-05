#include "tulippch.h"
#include "Tulip/Core/Window.h"

#ifdef TULIP_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsWindow.h"
#endif


namespace Tulip
{
    Scope<Window> Window::Create(const WindowProps& props)
    {
        #ifdef TULIP_PLATFORM_WINDOWS
            return CreateScope<WindowsWindow>(props);
        #else
            TULIP_CORE_ASSERT(false, "Unknown platform!");
            return nullptr;
        #endif
    }
}