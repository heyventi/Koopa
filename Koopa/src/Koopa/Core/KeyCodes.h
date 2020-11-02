#pragma once

namespace kp
{
    typedef enum class KeyCode : uint16_t
    {
        // From glfw3.h
        Space = 32,
        Apostrophe = 39, /* ' */
        Comma = 44, /* , */
        Minus = 45, /* - */
        Period = 46, /* . */
        Slash = 47, /* / */

        D0 = 48, /* 0 */
        D1 = 49, /* 1 */
        D2 = 50, /* 2 */
        D3 = 51, /* 3 */
        D4 = 52, /* 4 */
        D5 = 53, /* 5 */
        D6 = 54, /* 6 */
        D7 = 55, /* 7 */
        D8 = 56, /* 8 */
        D9 = 57, /* 9 */

        Semicolon = 59, /* ; */
        Equal = 61, /* = */

        A = 65,
        B = 66,
        C = 67,
        D = 68,
        E = 69,
        F = 70,
        G = 71,
        H = 72,
        I = 73,
        J = 74,
        K = 75,
        L = 76,
        M = 77,
        N = 78,
        O = 79,
        P = 80,
        Q = 81,
        R = 82,
        S = 83,
        T = 84,
        U = 85,
        V = 86,
        W = 87,
        X = 88,
        Y = 89,
        Z = 90,

        LeftBracket = 91,  /* [ */
        Backslash = 92,  /* \ */
        RightBracket = 93,  /* ] */
        GraveAccent = 96,  /* ` */

        World1 = 161, /* non-US #1 */
        World2 = 162, /* non-US #2 */

        /* Function keys */
        Escape = 256,
        Enter = 257,
        Tab = 258,
        Backspace = 259,
        Insert = 260,
        Delete = 261,
        Right = 262,
        Left = 263,
        Down = 264,
        Up = 265,
        PageUp = 266,
        PageDown = 267,
        Home = 268,
        End = 269,
        CapsLock = 280,
        ScrollLock = 281,
        NumLock = 282,
        PrintScreen = 283,
        Pause = 284,
        F1 = 290,
        F2 = 291,
        F3 = 292,
        F4 = 293,
        F5 = 294,
        F6 = 295,
        F7 = 296,
        F8 = 297,
        F9 = 298,
        F10 = 299,
        F11 = 300,
        F12 = 301,
        F13 = 302,
        F14 = 303,
        F15 = 304,
        F16 = 305,
        F17 = 306,
        F18 = 307,
        F19 = 308,
        F20 = 309,
        F21 = 310,
        F22 = 311,
        F23 = 312,
        F24 = 313,
        F25 = 314,

        /* Keypad */
        KP0 = 320,
        KP1 = 321,
        KP2 = 322,
        KP3 = 323,
        KP4 = 324,
        KP5 = 325,
        KP6 = 326,
        KP7 = 327,
        KP8 = 328,
        KP9 = 329,
        KPDecimal = 330,
        KPDivide = 331,
        KPMultiply = 332,
        KPSubtract = 333,
        KPAdd = 334,
        KPEnter = 335,
        KPEqual = 336,

        LeftShift = 340,
        LeftControl = 341,
        LeftAlt = 342,
        LeftSuper = 343,
        RightShift = 344,
        RightControl = 345,
        RightAlt = 346,
        RightSuper = 347,
        Menu = 348
    } Key;

    inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
    {
        os << static_cast<int32_t>(keyCode);
        return os;
    }
}

#define KP_KEY_SPACE           ::kp::Key::Space
#define KP_KEY_APOSTROPHE      ::kp::Key::Apostrophe    /* ' */
#define KP_KEY_COMMA           ::kp::Key::Comma         /* , */
#define KP_KEY_MINUS           ::kp::Key::Minus         /* - */
#define KP_KEY_PERIOD          ::kp::Key::Period        /* . */
#define KP_KEY_SLASH           ::kp::Key::Slash         /* / */
#define KP_KEY_0               ::kp::Key::D0
#define KP_KEY_1               ::kp::Key::D1
#define KP_KEY_2               ::kp::Key::D2
#define KP_KEY_3               ::kp::Key::D3
#define KP_KEY_4               ::kp::Key::D4
#define KP_KEY_5               ::kp::Key::D5
#define KP_KEY_6               ::kp::Key::D6
#define KP_KEY_7               ::kp::Key::D7
#define KP_KEY_8               ::kp::Key::D8
#define KP_KEY_9               ::kp::Key::D9
#define KP_KEY_SEMICOLON       ::kp::Key::Semicolon     /* ; */
#define KP_KEY_EQUAL           ::kp::Key::Equal         /* = */
#define KP_KEY_A               ::kp::Key::A
#define KP_KEY_B               ::kp::Key::B
#define KP_KEY_C               ::kp::Key::C
#define KP_KEY_D               ::kp::Key::D
#define KP_KEY_E               ::kp::Key::E
#define KP_KEY_F               ::kp::Key::F
#define KP_KEY_G               ::kp::Key::G
#define KP_KEY_H               ::kp::Key::H
#define KP_KEY_I               ::kp::Key::I
#define KP_KEY_J               ::kp::Key::J
#define KP_KEY_K               ::kp::Key::K
#define KP_KEY_L               ::kp::Key::L
#define KP_KEY_M               ::kp::Key::M
#define KP_KEY_N               ::kp::Key::N
#define KP_KEY_O               ::kp::Key::O
#define KP_KEY_P               ::kp::Key::P
#define KP_KEY_Q               ::kp::Key::Q
#define KP_KEY_R               ::kp::Key::R
#define KP_KEY_S               ::kp::Key::S
#define KP_KEY_T               ::kp::Key::T
#define KP_KEY_U               ::kp::Key::U
#define KP_KEY_V               ::kp::Key::V
#define KP_KEY_W               ::kp::Key::W
#define KP_KEY_X               ::kp::Key::X
#define KP_KEY_Y               ::kp::Key::Y
#define KP_KEY_Z               ::kp::Key::Z
#define KP_KEY_LEFT_BRACKET    ::kp::Key::LeftBracket   /* [ */
#define KP_KEY_BACKSLASH       ::kp::Key::Backslash     /* \ */
#define KP_KEY_RIGHT_BRACKET   ::kp::Key::RightBracket  /* ] */
#define KP_KEY_GRAVE_ACCENT    ::kp::Key::GraveAccent   /* ` */
#define KP_KEY_WORLD_1         ::kp::Key::World1        /* non-US #1 */
#define KP_KEY_WORLD_2         ::kp::Key::World2        /* non-US #2 */

#define KP_KEY_ESCAPE          ::kp::Key::Escape
#define KP_KEY_ENTER           ::kp::Key::Enter
#define KP_KEY_TAB             ::kp::Key::Tab
#define KP_KEY_BACKSPACE       ::kp::Key::Backspace
#define KP_KEY_INSERT          ::kp::Key::Insert
#define KP_KEY_DELETE          ::kp::Key::Delete
#define KP_KEY_RIGHT           ::kp::Key::Right
#define KP_KEY_LEFT            ::kp::Key::Left
#define KP_KEY_DOWN            ::kp::Key::Down
#define KP_KEY_UP              ::kp::Key::Up
#define KP_KEY_PAGE_UP         ::kp::Key::PageUp
#define KP_KEY_PAGE_DOWN       ::kp::Key::PageDown
#define KP_KEY_HOME            ::kp::Key::Home
#define KP_KEY_END             ::kp::Key::End
#define KP_KEY_CAPS_LOCK       ::kp::Key::CapsLock
#define KP_KEY_SCROLL_LOCK     ::kp::Key::ScrollLock
#define KP_KEY_NUM_LOCK        ::kp::Key::NumLock
#define KP_KEY_PRINT_SCREEN    ::kp::Key::PrintScreen
#define KP_KEY_PAUSE           ::kp::Key::Pause
#define KP_KEY_F1              ::kp::Key::F1
#define KP_KEY_F2              ::kp::Key::F2
#define KP_KEY_F3              ::kp::Key::F3
#define KP_KEY_F4              ::kp::Key::F4
#define KP_KEY_F5              ::kp::Key::F5
#define KP_KEY_F6              ::kp::Key::F6
#define KP_KEY_F7              ::kp::Key::F7
#define KP_KEY_F8              ::kp::Key::F8
#define KP_KEY_F9              ::kp::Key::F9
#define KP_KEY_F10             ::kp::Key::F10
#define KP_KEY_F11             ::kp::Key::F11
#define KP_KEY_F12             ::kp::Key::F12
#define KP_KEY_F13             ::kp::Key::F13
#define KP_KEY_F14             ::kp::Key::F14
#define KP_KEY_F15             ::kp::Key::F15
#define KP_KEY_F16             ::kp::Key::F16
#define KP_KEY_F17             ::kp::Key::F17
#define KP_KEY_F18             ::kp::Key::F18
#define KP_KEY_F19             ::kp::Key::F19
#define KP_KEY_F20             ::kp::Key::F20
#define KP_KEY_F21             ::kp::Key::F21
#define KP_KEY_F22             ::kp::Key::F22
#define KP_KEY_F23             ::kp::Key::F23
#define KP_KEY_F24             ::kp::Key::F24
#define KP_KEY_F25             ::kp::Key::F25

/* Keypad */
#define KP_KEY_KP_0            ::kp::Key::KP0
#define KP_KEY_KP_1            ::kp::Key::KP1
#define KP_KEY_KP_2            ::kp::Key::KP2
#define KP_KEY_KP_3            ::kp::Key::KP3
#define KP_KEY_KP_4            ::kp::Key::KP4
#define KP_KEY_KP_5            ::kp::Key::KP5
#define KP_KEY_KP_6            ::kp::Key::KP6
#define KP_KEY_KP_7            ::kp::Key::KP7
#define KP_KEY_KP_8            ::kp::Key::KP8
#define KP_KEY_KP_9            ::kp::Key::KP9
#define KP_KEY_KP_DECIMAL      ::kp::Key::KPDecimal
#define KP_KEY_KP_DIVIDE       ::kp::Key::KPDivide
#define KP_KEY_KP_MULTIPLY     ::kp::Key::KPMultiply
#define KP_KEY_KP_SUBTRACT     ::kp::Key::KPSubtract
#define KP_KEY_KP_ADD          ::kp::Key::KPAdd
#define KP_KEY_KP_ENTER        ::kp::Key::KPEnter
#define KP_KEY_KP_EQUAL        ::kp::Key::KPEqual

#define KP_KEY_LEFT_SHIFT      ::kp::Key::LeftShift
#define KP_KEY_LEFT_CONTROL    ::kp::Key::LeftControl
#define KP_KEY_LEFT_ALT        ::kp::Key::LeftAlt
#define KP_KEY_LEFT_SUPER      ::kp::Key::LeftSuper
#define KP_KEY_RIGHT_SHIFT     ::kp::Key::RightShift
#define KP_KEY_RIGHT_CONTROL   ::kp::Key::RightControl
#define KP_KEY_RIGHT_ALT       ::kp::Key::RightAlt
#define KP_KEY_RIGHT_SUPER     ::kp::Key::RightSuper
#define KP_KEY_MENU            ::kp::Key::Menu