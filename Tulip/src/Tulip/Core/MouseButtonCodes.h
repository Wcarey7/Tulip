#pragma once

namespace Tulip
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0                = 0,
		Button1                = 1,
		Button2                = 2,
		Button3                = 3,
		Button4                = 4,
		Button5                = 5,
		Button6                = 6,
		Button7                = 7,

		ButtonLast             = Button7,
		ButtonLeft             = Button0,
		ButtonRight            = Button1,
		ButtonMiddle           = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define TULIP_MOUSE_BUTTON_0      ::Tulip::Mouse::Button0
#define TULIP_MOUSE_BUTTON_1      ::Tulip::Mouse::Button1
#define TULIP_MOUSE_BUTTON_2      ::Tulip::Mouse::Button2
#define TULIP_MOUSE_BUTTON_3      ::Tulip::Mouse::Button3
#define TULIP_MOUSE_BUTTON_4      ::Tulip::Mouse::Button4
#define TULIP_MOUSE_BUTTON_5      ::Tulip::Mouse::Button5
#define TULIP_MOUSE_BUTTON_6      ::Tulip::Mouse::Button6
#define TULIP_MOUSE_BUTTON_7      ::Tulip::Mouse::Button7
#define TULIP_MOUSE_BUTTON_LAST   ::Tulip::Mouse::ButtonLast
#define TULIP_MOUSE_BUTTON_LEFT   ::Tulip::Mouse::ButtonLeft
#define TULIP_MOUSE_BUTTON_RIGHT  ::Tulip::Mouse::ButtonRight
#define TULIP_MOUSE_BUTTON_MIDDLE ::Tulip::Mouse::ButtonMiddle