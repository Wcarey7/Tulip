#pragma once

#include "Tulip/Core/Core.h"
#include "Tulip/Core/Window.h"
#include "Tulip/Core/LayerStack.h"
#include "Tulip/Events/Event.h"
#include "Tulip/Events/ApplicationEvent.h"
#include "Tulip/Core/Timestep.h"
#include "Tulip/ImGui/ImGuiLayer.h"


int main(int argc, char** argv);

namespace Tulip 
{
    class Application
    {
    public:
        Application(const std::string& name = "Tulip App");
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        void Close();

        ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

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
        friend int ::main(int argc, char** argv);
    };

    Application* CreateApplication();
}


