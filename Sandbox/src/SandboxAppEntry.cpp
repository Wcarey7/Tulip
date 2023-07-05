#include "Tulip.h"
#include "Tulip/Core/EntryPoint.h"
#include "ExampleLayer.h"
#include "Sandbox2D.h"


class Sandbox : public Tulip::Application
{
public:
    Sandbox()
    {
        //PushLayer(new ExampleLayer());
        PushLayer(new Sandbox2D());
    }

    ~Sandbox()
    {

    }
};


Tulip::Application* Tulip::CreateApplication()
{
    return new Sandbox();
}