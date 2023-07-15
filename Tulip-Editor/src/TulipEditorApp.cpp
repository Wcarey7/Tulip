#include "Tulip.h"
#include "Tulip/Core/EntryPoint.h"
#include "EditorLayer.h"



namespace Tulip
{
    class TulipEditor : public Application
    {
    public:
        TulipEditor(ApplicationCommandLineArgs args)
            : Application("Tulip Editor", args)
        {
            PushLayer(new EditorLayer());
        }

        ~TulipEditor()
        {

        }
    };


    Application* CreateApplication(ApplicationCommandLineArgs args)
    {
        return new TulipEditor(args);
    }
}