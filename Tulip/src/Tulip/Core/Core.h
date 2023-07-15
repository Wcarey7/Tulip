#pragma once

#include <memory>
#include "Tulip/Core/PlatformDetection.h"



#ifdef TULIP_DEBUG
    #if defined(TULIP_PLATFORM_WINDOWS)
        #define TULIP_DEBUGBREAK() __debugbreak()
    #elif defined(TULIP_PLATFORM_LINUX)
        #include <signal.h>
        #define TULIP_DEBUGBREAK() raise(SIGTRAP)
    #else
        #error "Platform doesn't support debugbreak yet!"
    #endif
    #define TULIP_ENABLE_ASSERTS
#else
    #define TULIP_DEBUGBREAK()
#endif


#define TULIP_EXPAND_MACRO(x) x
#define TULIP_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define TULIP_BIND_EVENT_FN(fn) [this](auto&&... args)->decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

//----- Smart Pointer Macros ------------------------------
//---------------------------------------------------------
namespace Tulip 
{
    template<typename T>
    using Scope = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}

#include "Tulip/Core/Log.h"
#include "Tulip/Core/Assert.h"