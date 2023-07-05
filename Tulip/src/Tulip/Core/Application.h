#pragma once

#include "Tulip/Core/Core.h"
#include "Tulip/Core/Window.h"
#include "Tulip/Core/LayerStack.h"
#include "Tulip/Events/Event.h"
#include "Tulip/Events/ApplicationEvent.h"
#include "Tulip/Core/Timestep.h"
#include "Tulip/ImGui/ImGuiLayer.h"


namespace Tulip 
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        inline static Application& Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);
    private:
        Scope<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;

        bool m_Running = true;
        bool m_Minimized = false;
        LayerStack m_LayerStack;

        float m_LastFrameTime = 0.0f;

    private:
        static Application* s_Instance;
    };

    Application* CreateApplication();
}


