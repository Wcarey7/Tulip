#include "Tulip.h"
#include "Tulip/Core/EntryPoint.h"
#include "ExampleLayer.h"
#include "Sandbox2D.h"


class Sandbox : public Tulip::Application
{
public:
    Sandbox(const Tulip::ApplicationSpecification& specification)
        : Tulip::Application(specification)
    {
        //PushLayer(new ExampleLayer());
        PushLayer(new Sandbox2D());
    }

    ~Sandbox()
    {

    }
};


Tulip::Application* Tulip::CreateApplication(Tulip::ApplicationCommandLineArgs args)
{
    ApplicationSpecification spec;
    spec.Name = "Sandbox";
    spec.WorkingDirectory = "../Tulip-Editor";
    spec.CommandLineArgs = args;

    return new Sandbox(spec);
}