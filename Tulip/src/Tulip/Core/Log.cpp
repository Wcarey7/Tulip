#include "tulippch.h"
#include "Tulip/Core/Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>


namespace Tulip
{
    Ref<spdlog::logger> Log::s_CoreLogger;
    Ref<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$"); //Color, time stamp, Name of logger(core or client), Message
        s_CoreLogger = spdlog::stdout_color_mt("TULIP");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}
