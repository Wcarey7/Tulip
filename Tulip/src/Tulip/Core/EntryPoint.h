#pragma once
#include "Tulip/Core/Core.h"

#ifdef TULIP_PLATFORM_WINDOWS

extern Tulip::Application* Tulip::CreateApplication();


int main(int argc, char** argv)
{
    Tulip::Log::Init();

    TULIP_PROFILE_BEGIN_SESSION("Startup", "TulipProfile-Startup.json");
    auto app = Tulip::CreateApplication();
    TULIP_PROFILE_END_SESSION();

    TULIP_PROFILE_BEGIN_SESSION("Runtime", "TulipProfile-Runtime.json");
    app->Run();
    TULIP_PROFILE_END_SESSION();

    TULIP_PROFILE_BEGIN_SESSION("Shutdown", "TulipProfile-Shutdown.json");
    delete app;
    TULIP_PROFILE_END_SESSION();
}

#endif