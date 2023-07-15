#pragma once

#include "Tulip/Core/Layer.h"
#include "Tulip/Events/ApplicationEvent.h"
#include "Tulip/Events/KeyEvent.h"
#include "Tulip/Events/MouseEvent.h"


namespace Tulip 
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnEvent(Event& e) override;

        void Begin();
        void End();

        void BlockEvents(bool block) { m_BlockEvents = block; }

        void SetDarkThemeColors();

    private:
        bool m_BlockEvents = true;
    };
}