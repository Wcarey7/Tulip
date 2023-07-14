#pragma once

#include "Tulip/Renderer/Texture.h"
#include <filesystem>


namespace Tulip
{
    class ContentBrowserPanel
    {
    public:
        ContentBrowserPanel();

        void OnImGuiRender();

    private:
        std::filesystem::path m_CurrentDirectory;

        Ref<Texture2D> m_DirectoryIcon;
        Ref<Texture2D> m_FileIcon;
    };
}