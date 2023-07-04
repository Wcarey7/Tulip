#pragma once

#include <memory>


#ifdef TULIP_PLATFORM_WINDOWS
#if TULIP_DYNAMIC_LINK
    #ifdef TULIP_BUILD_DLL
        #define TULIP_API __declspec(dllexport)
    #else
        #define TULIP_API __declspec(dllimport)
    #endif
#else
#define TULIP_API
#endif
#else
    #error Tulip only supports Windows.
#endif


#ifdef TULIP_DEBUG
    #define  TULIP_ENABLE_ASSERTS
#endif

#ifdef TULIP_ENABLE_ASSERTS
    #define TULIP_ASSERT(x, ...) {if(!(x)) { TULIP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define TULIP_CORE_ASSERT(x, ...) {if(!(x)) { TULIP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define TULIP_ASSERT(x, ...)
    #define TULIP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define TULIP_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

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