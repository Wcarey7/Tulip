#pragma once

#include <filesystem>
#include "Tulip/Core/Core.h"
#include "Tulip/Core/Log.h"


#ifdef TULIP_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define TULIP_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { TULIP##type##ERROR(msg, __VA_ARGS__); TULIP_DEBUGBREAK(); } }
#define TULIP_INTERNAL_ASSERT_WITH_MSG(type, check, ...) TULIP_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define TULIP_INTERNAL_ASSERT_NO_MSG(type, check) TULIP_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", TULIP_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define TULIP_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define TULIP_INTERNAL_ASSERT_GET_MACRO(...) TULIP_EXPAND_MACRO( TULIP_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, TULIP_INTERNAL_ASSERT_WITH_MSG, TULIP_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define TULIP_ASSERT(...) TULIP_EXPAND_MACRO( TULIP_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define TULIP_CORE_ASSERT(...) TULIP_EXPAND_MACRO( TULIP_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define TULIP_ASSERT(...)
#define TULIP_CORE_ASSERT(...)
#endif