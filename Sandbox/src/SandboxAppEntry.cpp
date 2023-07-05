#include "Tulip.h"
#include "Tulip/Core/EntryPoint.h"
#include "ExampleLayer.h"


class Sandbox : public Tulip::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox()
    {

    }
};


Tulip::Application* Tulip::CreateApplication()
{
    return new Sandbox();
}