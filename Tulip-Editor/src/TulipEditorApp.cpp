#include "Tulip.h"
#include "Tulip/Core/EntryPoint.h"
#include "EditorLayer.h"



namespace Tulip
{
    class TulipEditor : public Application
    {
    public:
        TulipEditor(const ApplicationSpecification& spec)
            : Application(spec)
        {
            PushLayer(new EditorLayer());
        }

        ~TulipEditor()
        {

        }
    };


    Application* CreateApplication(ApplicationCommandLineArgs args)
    {
        ApplicationSpecification spec;
        spec.Name = "Tulip-Editor";
        spec.CommandLineArgs = args;

        return new TulipEditor(spec);
    }
}