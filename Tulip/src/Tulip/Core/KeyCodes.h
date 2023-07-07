#pragma once

namespace Tulip
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space               = 32,
		Apostrophe          = 39, /* ' */
		Comma               = 44, /* , */
		Minus               = 45, /* - */
		Period              = 46, /* . */
		Slash               = 47, /* / */

		D0                  = 48, /* 0 */
		D1                  = 49, /* 1 */
		D2                  = 50, /* 2 */
		D3                  = 51, /* 3 */
		D4                  = 52, /* 4 */
		D5                  = 53, /* 5 */
		D6                  = 54, /* 6 */
		D7                  = 55, /* 7 */
		D8                  = 56, /* 8 */
		D9                  = 57, /* 9 */

		Semicolon           = 59, /* ; */
		Equal               = 61, /* = */

		A                   = 65,
		B                   = 66,
		C                   = 67,
		D                   = 68,
		E                   = 69,
		F                   = 70,
		G                   = 71,
		H                   = 72,
		I                   = 73,
		J                   = 74,
		K                   = 75,
		L                   = 76,
		M                   = 77,
		N                   = 78,
		O                   = 79,
		P                   = 80,
		Q                   = 81,
		R                   = 82,
		S                   = 83,
		T                   = 84,
		U                   = 85,
		V                   = 86,
		W                   = 87,
		X                   = 88,
		Y                   = 89,
		Z                   = 90,

		LeftBracket         = 91,  /* [ */
		Backslash           = 92,  /* \ */
		RightBracket        = 93,  /* ] */
		GraveAccent         = 96,  /* ` */

		World1              = 161, /* non-US #1 */
		World2              = 162, /* non-US #2 */

		/* Function keys */
		Escape              = 256,
		Enter               = 257,
		Tab                 = 258,
		Backspace           = 259,
		Insert              = 260,
		Delete              = 261,
		Right               = 262,
		Left                = 263,
		Down                = 264,
		Up                  = 265,
		PageUp              = 266,
		PageDown            = 267,
		Home                = 268,
		End                 = 269,
		CapsLock            = 280,
		ScrollLock          = 281,
		NumLock             = 282,
		PrintScreen         = 283,
		Pause               = 284,
		F1                  = 290,
		F2                  = 291,
		F3                  = 292,
		F4                  = 293,
		F5                  = 294,
		F6                  = 295,
		F7                  = 296,
		F8                  = 297,
		F9                  = 298,
		F10                 = 299,
		F11                 = 300,
		F12                 = 301,
		F13                 = 302,
		F14                 = 303,
		F15                 = 304,
		F16                 = 305,
		F17                 = 306,
		F18                 = 307,
		F19                 = 308,
		F20                 = 309,
		F21                 = 310,
		F22                 = 311,
		F23                 = 312,
		F24                 = 313,
		F25                 = 314,

		/* Keypad */
		KP0                 = 320,
		KP1                 = 321,
		KP2                 = 322,
		KP3                 = 323,
		KP4                 = 324,
		KP5                 = 325,
		KP6                 = 326,
		KP7                 = 327,
		KP8                 = 328,
		KP9                 = 329,
		KPDecimal           = 330,
		KPDivide            = 331,
		KPMultiply          = 332,
		KPSubtract          = 333,
		KPAdd               = 334,
		KPEnter             = 335,
		KPEqual             = 336,

		LeftShift           = 340,
		LeftControl         = 341,
		LeftAlt             = 342,
		LeftSuper           = 343,
		RightShift          = 344,
		RightControl        = 345,
		RightAlt            = 346,
		RightSuper          = 347,
		Menu                = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define TULIP_KEY_SPACE           ::Tulip::Key::Space
#define TULIP_KEY_APOSTROPHE      ::Tulip::Key::Apostrophe    /* ' */
#define TULIP_KEY_COMMA           ::Tulip::Key::Comma         /* , */
#define TULIP_KEY_MINUS           ::Tulip::Key::Minus         /* - */
#define TULIP_KEY_PERIOD          ::Tulip::Key::Period        /* . */
#define TULIP_KEY_SLASH           ::Tulip::Key::Slash         /* / */
#define TULIP_KEY_0               ::Tulip::Key::D0
#define TULIP_KEY_1               ::Tulip::Key::D1
#define TULIP_KEY_2               ::Tulip::Key::D2
#define TULIP_KEY_3               ::Tulip::Key::D3
#define TULIP_KEY_4               ::Tulip::Key::D4
#define TULIP_KEY_5               ::Tulip::Key::D5
#define TULIP_KEY_6               ::Tulip::Key::D6
#define TULIP_KEY_7               ::Tulip::Key::D7
#define TULIP_KEY_8               ::Tulip::Key::D8
#define TULIP_KEY_9               ::Tulip::Key::D9
#define TULIP_KEY_SEMICOLON       ::Tulip::Key::Semicolon     /* ; */
#define TULIP_KEY_EQUAL           ::Tulip::Key::Equal         /* = */
#define TULIP_KEY_A               ::Tulip::Key::A
#define TULIP_KEY_B               ::Tulip::Key::B
#define TULIP_KEY_C               ::Tulip::Key::C
#define TULIP_KEY_D               ::Tulip::Key::D
#define TULIP_KEY_E               ::Tulip::Key::E
#define TULIP_KEY_F               ::Tulip::Key::F
#define TULIP_KEY_G               ::Tulip::Key::G
#define TULIP_KEY_H               ::Tulip::Key::H
#define TULIP_KEY_I               ::Tulip::Key::I
#define TULIP_KEY_J               ::Tulip::Key::J
#define TULIP_KEY_K               ::Tulip::Key::K
#define TULIP_KEY_L               ::Tulip::Key::L
#define TULIP_KEY_M               ::Tulip::Key::M
#define TULIP_KEY_N               ::Tulip::Key::N
#define TULIP_KEY_O               ::Tulip::Key::O
#define TULIP_KEY_P               ::Tulip::Key::P
#define TULIP_KEY_Q               ::Tulip::Key::Q
#define TULIP_KEY_R               ::Tulip::Key::R
#define TULIP_KEY_S               ::Tulip::Key::S
#define TULIP_KEY_T               ::Tulip::Key::T
#define TULIP_KEY_U               ::Tulip::Key::U
#define TULIP_KEY_V               ::Tulip::Key::V
#define TULIP_KEY_W               ::Tulip::Key::W
#define TULIP_KEY_X               ::Tulip::Key::X
#define TULIP_KEY_Y               ::Tulip::Key::Y
#define TULIP_KEY_Z               ::Tulip::Key::Z
#define TULIP_KEY_LEFT_BRACKET    ::Tulip::Key::LeftBracket   /* [ */
#define TULIP_KEY_BACKSLASH       ::Tulip::Key::Backslash     /* \ */
#define TULIP_KEY_RIGHT_BRACKET   ::Tulip::Key::RightBracket  /* ] */
#define TULIP_KEY_GRAVE_ACCENT    ::Tulip::Key::GraveAccent   /* ` */
#define TULIP_KEY_WORLD_1         ::Tulip::Key::World1        /* non-US #1 */
#define TULIP_KEY_WORLD_2         ::Tulip::Key::World2        /* non-US #2 */

/* Function keys */
#define TULIP_KEY_ESCAPE          ::Tulip::Key::Escape
#define TULIP_KEY_ENTER           ::Tulip::Key::Enter
#define TULIP_KEY_TAB             ::Tulip::Key::Tab
#define TULIP_KEY_BACKSPACE       ::Tulip::Key::Backspace
#define TULIP_KEY_INSERT          ::Tulip::Key::Insert
#define TULIP_KEY_DELETE          ::Tulip::Key::Delete
#define TULIP_KEY_RIGHT           ::Tulip::Key::Right
#define TULIP_KEY_LEFT            ::Tulip::Key::Left
#define TULIP_KEY_DOWN            ::Tulip::Key::Down
#define TULIP_KEY_UP              ::Tulip::Key::Up
#define TULIP_KEY_PAGE_UP         ::Tulip::Key::PageUp
#define TULIP_KEY_PAGE_DOWN       ::Tulip::Key::PageDown
#define TULIP_KEY_HOME            ::Tulip::Key::Home
#define TULIP_KEY_END             ::Tulip::Key::End
#define TULIP_KEY_CAPS_LOCK       ::Tulip::Key::CapsLock
#define TULIP_KEY_SCROLL_LOCK     ::Tulip::Key::ScrollLock
#define TULIP_KEY_NUM_LOCK        ::Tulip::Key::NumLock
#define TULIP_KEY_PRINT_SCREEN    ::Tulip::Key::PrintScreen
#define TULIP_KEY_PAUSE           ::Tulip::Key::Pause
#define TULIP_KEY_F1              ::Tulip::Key::F1
#define TULIP_KEY_F2              ::Tulip::Key::F2
#define TULIP_KEY_F3              ::Tulip::Key::F3
#define TULIP_KEY_F4              ::Tulip::Key::F4
#define TULIP_KEY_F5              ::Tulip::Key::F5
#define TULIP_KEY_F6              ::Tulip::Key::F6
#define TULIP_KEY_F7              ::Tulip::Key::F7
#define TULIP_KEY_F8              ::Tulip::Key::F8
#define TULIP_KEY_F9              ::Tulip::Key::F9
#define TULIP_KEY_F10             ::Tulip::Key::F10
#define TULIP_KEY_F11             ::Tulip::Key::F11
#define TULIP_KEY_F12             ::Tulip::Key::F12
#define TULIP_KEY_F13             ::Tulip::Key::F13
#define TULIP_KEY_F14             ::Tulip::Key::F14
#define TULIP_KEY_F15             ::Tulip::Key::F15
#define TULIP_KEY_F16             ::Tulip::Key::F16
#define TULIP_KEY_F17             ::Tulip::Key::F17
#define TULIP_KEY_F18             ::Tulip::Key::F18
#define TULIP_KEY_F19             ::Tulip::Key::F19
#define TULIP_KEY_F20             ::Tulip::Key::F20
#define TULIP_KEY_F21             ::Tulip::Key::F21
#define TULIP_KEY_F22             ::Tulip::Key::F22
#define TULIP_KEY_F23             ::Tulip::Key::F23
#define TULIP_KEY_F24             ::Tulip::Key::F24
#define TULIP_KEY_F25             ::Tulip::Key::F25

/* Keypad */
#define TULIP_KEY_KP_0            ::Tulip::Key::KP0
#define TULIP_KEY_KP_1            ::Tulip::Key::KP1
#define TULIP_KEY_KP_2            ::Tulip::Key::KP2
#define TULIP_KEY_KP_3            ::Tulip::Key::KP3
#define TULIP_KEY_KP_4            ::Tulip::Key::KP4
#define TULIP_KEY_KP_5            ::Tulip::Key::KP5
#define TULIP_KEY_KP_6            ::Tulip::Key::KP6
#define TULIP_KEY_KP_7            ::Tulip::Key::KP7
#define TULIP_KEY_KP_8            ::Tulip::Key::KP8
#define TULIP_KEY_KP_9            ::Tulip::Key::KP9
#define TULIP_KEY_KP_DECIMAL      ::Tulip::Key::KPDecimal
#define TULIP_KEY_KP_DIVIDE       ::Tulip::Key::KPDivide
#define TULIP_KEY_KP_MULTIPLY     ::Tulip::Key::KPMultiply
#define TULIP_KEY_KP_SUBTRACT     ::Tulip::Key::KPSubtract
#define TULIP_KEY_KP_ADD          ::Tulip::Key::KPAdd
#define TULIP_KEY_KP_ENTER        ::Tulip::Key::KPEnter
#define TULIP_KEY_KP_EQUAL        ::Tulip::Key::KPEqual

#define TULIP_KEY_LEFT_SHIFT      ::Tulip::Key::LeftShift
#define TULIP_KEY_LEFT_CONTROL    ::Tulip::Key::LeftControl
#define TULIP_KEY_LEFT_ALT        ::Tulip::Key::LeftAlt
#define TULIP_KEY_LEFT_SUPER      ::Tulip::Key::LeftSuper
#define TULIP_KEY_RIGHT_SHIFT     ::Tulip::Key::RightShift
#define TULIP_KEY_RIGHT_CONTROL   ::Tulip::Key::RightControl
#define TULIP_KEY_RIGHT_ALT       ::Tulip::Key::RightAlt
#define TULIP_KEY_RIGHT_SUPER     ::Tulip::Key::RightSuper
#define TULIP_KEY_MENU            ::Tulip::Key::Menu