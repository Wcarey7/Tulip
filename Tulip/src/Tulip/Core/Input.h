#pragma once

#include "Tulip/Core/Core.h"
#include "Tulip/Core/KeyCodes.h"
#include "Tulip/Core/MouseButtonCodes.h"

#include <glm/glm.hpp>


namespace Tulip 
{
    class Input 
    {
    public:
        static bool IsKeyPressed(KeyCode key);
        
        static bool IsMouseButtonPressed(MouseCode button);
        static std::pair<float, float> GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
    };
}