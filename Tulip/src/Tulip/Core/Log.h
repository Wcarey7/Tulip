#pragma once

#include "Tulip/Core/Core.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)


namespace Tulip 
{
    class Log
    {
    public:
        static void Init();

        inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static Ref<spdlog::logger> s_CoreLogger;
        static Ref<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define TULIP_CORE_TRACE(...)     ::Tulip::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TULIP_CORE_INFO(...)      ::Tulip::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TULIP_CORE_WARN(...)      ::Tulip::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TULIP_CORE_ERROR(...)     ::Tulip::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TULIP_CORE_CRITICAL(...)  ::Tulip::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define TULIP_TRACE(...)          ::Tulip::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TULIP_INFO(...)           ::Tulip::Log::GetClientLogger()->info(__VA_ARGS__)
#define TULIP_WARN(...)           ::Tulip::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TULIP_ERROR(...)          ::Tulip::Log::GetClientLogger()->error(__VA_ARGS__)
#define TULIP_CRITICAL(...)       ::Tulip::Log::GetClientLogger()->critical(__VA_ARGS__)

