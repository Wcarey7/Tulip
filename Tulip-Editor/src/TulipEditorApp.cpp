#include "Tulip.h"
#include "Tulip/Core/EntryPoint.h"
#include "EditorLayer.h"



namespace Tulip
{
    class TulipEditor : public Application
    {
    public:
        TulipEditor()
            : Application("Tulip Editor")
        {
            PushLayer(new EditorLayer());
        }

        ~TulipEditor()
        {

        }
    };


    Application* CreateApplication()
    {
        return new TulipEditor();
    }
}