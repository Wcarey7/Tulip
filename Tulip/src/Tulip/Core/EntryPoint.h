#pragma once

#ifdef TULIP_PLATFORM_WINDOWS

extern Tulip::Application* Tulip::CreateApplication();

int main(int argc, char** argv)
{
    Tulip::Log::Init();

    TULIP_CORE_WARN("Core initialized log");
    TULIP_INFO("Client initialized log");

    auto app = Tulip::CreateApplication();
    app->Run();
    delete app;
}

#endif