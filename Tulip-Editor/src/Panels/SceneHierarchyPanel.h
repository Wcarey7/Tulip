#pragma once

#include "Tulip/Core/Core.h"
#include "Tulip/Core/Log.h"
#include "Tulip/Scene/Scene.h"
#include "Tulip/Scene/Entity.h"


namespace Tulip
{
    class SceneHierarchyPanel
    {
    public:
        SceneHierarchyPanel() = default;
        SceneHierarchyPanel(const Ref<Scene>& scene);

        void SetContext(const Ref<Scene>& scene);

        void OnImGuiRender();

    private:
        void DrawEntityNode(Entity entity);
    private:
        Ref<Scene> m_Context;
        Entity m_SelectionContext;
    };
}