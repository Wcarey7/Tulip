#pragma once

#include "Tulip/Core/Core.h"
#include "Tulip/Core/Application.h"


#ifdef TULIP_PLATFORM_WINDOWS

extern Tulip::Application* Tulip::CreateApplication(ApplicationCommandLineArgs args);


int main(int argc, char** argv)
{
    Tulip::Log::Init();

    TULIP_PROFILE_BEGIN_SESSION("Startup", "TulipProfile-Startup.json");
    auto app = Tulip::CreateApplication({ argc, argv });
    TULIP_PROFILE_END_SESSION();

    TULIP_PROFILE_BEGIN_SESSION("Runtime", "TulipProfile-Runtime.json");
    app->Run();
    TULIP_PROFILE_END_SESSION();

    TULIP_PROFILE_BEGIN_SESSION("Shutdown", "TulipProfile-Shutdown.json");
    delete app;
    TULIP_PROFILE_END_SESSION();
}

#endif