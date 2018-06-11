/* https://github.com/shaovoon/EnumConvGen */
#ifndef SDL_SCANCODE_HELPER
#define SDL_SCANCODE_HELPER
namespace scancode_helper {
std::string to_string(ef const& val);
void from_string(std::string const& val, /* OUT */ ef& out_val);
int to_int(ef const& val);
void from_int(int const& val, /* OUT */ ef& out_val);
std::ostream& operator<<(std::ostream& os, ef const& val);
std::istream& operator>>(std::istream& is, ef& val);

std::string to_string(ef const& val) {
    switch (val) {
        case (int)SDL_SCANCODE_UNKNOWN:
            return "SDL_SCANCODE_UNKNOWN";
        case (int)SDL_SCANCODE_A:
            return "SDL_SCANCODE_A";
        case (int)SDL_SCANCODE_B:
            return "SDL_SCANCODE_B";
        case (int)SDL_SCANCODE_C:
            return "SDL_SCANCODE_C";
        case (int)SDL_SCANCODE_D:
            return "SDL_SCANCODE_D";
        case (int)SDL_SCANCODE_E:
            return "SDL_SCANCODE_E";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_G:
            return "SDL_SCANCODE_G";
        case (int)SDL_SCANCODE_H:
            return "SDL_SCANCODE_H";
        case (int)SDL_SCANCODE_I:
            return "SDL_SCANCODE_I";
        case (int)SDL_SCANCODE_J:
            return "SDL_SCANCODE_J";
        case (int)SDL_SCANCODE_K:
            return "SDL_SCANCODE_K";
        case (int)SDL_SCANCODE_L:
            return "SDL_SCANCODE_L";
        case (int)SDL_SCANCODE_M:
            return "SDL_SCANCODE_M";
        case (int)SDL_SCANCODE_N:
            return "SDL_SCANCODE_N";
        case (int)SDL_SCANCODE_O:
            return "SDL_SCANCODE_O";
        case (int)SDL_SCANCODE_P:
            return "SDL_SCANCODE_P";
        case (int)SDL_SCANCODE_Q:
            return "SDL_SCANCODE_Q";
        case (int)SDL_SCANCODE_R:
            return "SDL_SCANCODE_R";
        case (int)SDL_SCANCODE_S:
            return "SDL_SCANCODE_S";
        case (int)SDL_SCANCODE_T:
            return "SDL_SCANCODE_T";
        case (int)SDL_SCANCODE_U:
            return "SDL_SCANCODE_U";
        case (int)SDL_SCANCODE_V:
            return "SDL_SCANCODE_V";
        case (int)SDL_SCANCODE_W:
            return "SDL_SCANCODE_W";
        case (int)SDL_SCANCODE_X:
            return "SDL_SCANCODE_X";
        case (int)SDL_SCANCODE_Y:
            return "SDL_SCANCODE_Y";
        case (int)SDL_SCANCODE_Z:
            return "SDL_SCANCODE_Z";
        case (int)SDL_SCANCODE_:
            return "SDL_SCANCODE_";
        case (int)SDL_SCANCODE_:
            return "SDL_SCANCODE_";
        case (int)SDL_SCANCODE_:
            return "SDL_SCANCODE_";
        case (int)SDL_SCANCODE_:
            return "SDL_SCANCODE_";
        case (int)SDL_SCANCODE_:
            return "SDL_SCANCODE_";
        case (int)SDL_SCANCODE_:
            return "SDL_SCANCODE_";
        case (int)SDL_SCANCODE_:
            return "SDL_SCANCODE_";
        case (int)SDL_SCANCODE_:
            return "SDL_SCANCODE_";
        case (int)SDL_SCANCODE_:
            return "SDL_SCANCODE_";
        case (int)SDL_SCANCODE_:
            return "SDL_SCANCODE_";
        case (int)SDL_SCANCODE_RETURN:
            return "SDL_SCANCODE_RETURN";
        case (int)SDL_SCANCODE_ESCAPE:
            return "SDL_SCANCODE_ESCAPE";
        case (int)SDL_SCANCODE_BACKSPACE:
            return "SDL_SCANCODE_BACKSPACE";
        case (int)SDL_SCANCODE_TAB:
            return "SDL_SCANCODE_TAB";
        case (int)SDL_SCANCODE_SPACE:
            return "SDL_SCANCODE_SPACE";
        case (int)SDL_SCANCODE_MINUS:
            return "SDL_SCANCODE_MINUS";
        case (int)SDL_SCANCODE_EQUALS:
            return "SDL_SCANCODE_EQUALS";
        case (int)SDL_SCANCODE_LEFTBRACKET:
            return "SDL_SCANCODE_LEFTBRACKET";
        case (int)SDL_SCANCODE_RIGHTBRACKET:
            return "SDL_SCANCODE_RIGHTBRACKET";
        case (int)SDL_SCANCODE_BACKSLASH:
            return "SDL_SCANCODE_BACKSLASH";
        case (int)SDL_SCANCODE_NONUSHASH:
            return "SDL_SCANCODE_NONUSHASH";
        case (int)SDL_SCANCODE_SEMICOLON:
            return "SDL_SCANCODE_SEMICOLON";
        case (int)SDL_SCANCODE_APOSTROPHE:
            return "SDL_SCANCODE_APOSTROPHE";
        case (int)SDL_SCANCODE_GRAVE:
            return "SDL_SCANCODE_GRAVE";
        case (int)SDL_SCANCODE_COMMA:
            return "SDL_SCANCODE_COMMA";
        case (int)SDL_SCANCODE_PERIOD:
            return "SDL_SCANCODE_PERIOD";
        case (int)SDL_SCANCODE_SLASH:
            return "SDL_SCANCODE_SLASH";
        case (int)SDL_SCANCODE_CAPSLOCK:
            return "SDL_SCANCODE_CAPSLOCK";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_PRINTSCREEN:
            return "SDL_SCANCODE_PRINTSCREEN";
        case (int)SDL_SCANCODE_SCROLLLOCK:
            return "SDL_SCANCODE_SCROLLLOCK";
        case (int)SDL_SCANCODE_PAUSE:
            return "SDL_SCANCODE_PAUSE";
        case (int)SDL_SCANCODE_INSERT:
            return "SDL_SCANCODE_INSERT";
        case (int)SDL_SCANCODE_HOME:
            return "SDL_SCANCODE_HOME";
        case (int)SDL_SCANCODE_PAGEUP:
            return "SDL_SCANCODE_PAGEUP";
        case (int)SDL_SCANCODE_DELETE:
            return "SDL_SCANCODE_DELETE";
        case (int)SDL_SCANCODE_END:
            return "SDL_SCANCODE_END";
        case (int)SDL_SCANCODE_PAGEDOWN:
            return "SDL_SCANCODE_PAGEDOWN";
        case (int)SDL_SCANCODE_RIGHT:
            return "SDL_SCANCODE_RIGHT";
        case (int)SDL_SCANCODE_LEFT:
            return "SDL_SCANCODE_LEFT";
        case (int)SDL_SCANCODE_DOWN:
            return "SDL_SCANCODE_DOWN";
        case (int)SDL_SCANCODE_UP:
            return "SDL_SCANCODE_UP";
        case (int)SDL_SCANCODE_NUMLOCKCLEAR:
            return "SDL_SCANCODE_NUMLOCKCLEAR";
        case (int)SDL_SCANCODE_KP_DIVIDE:
            return "SDL_SCANCODE_KP_DIVIDE";
        case (int)SDL_SCANCODE_KP_MULTIPLY:
            return "SDL_SCANCODE_KP_MULTIPLY";
        case (int)SDL_SCANCODE_KP_MINUS:
            return "SDL_SCANCODE_KP_MINUS";
        case (int)SDL_SCANCODE_KP_PLUS:
            return "SDL_SCANCODE_KP_PLUS";
        case (int)SDL_SCANCODE_KP_ENTER:
            return "SDL_SCANCODE_KP_ENTER";
        case (int)SDL_SCANCODE_KP_:
            return "SDL_SCANCODE_KP_";
        case (int)SDL_SCANCODE_KP_:
            return "SDL_SCANCODE_KP_";
        case (int)SDL_SCANCODE_KP_:
            return "SDL_SCANCODE_KP_";
        case (int)SDL_SCANCODE_KP_:
            return "SDL_SCANCODE_KP_";
        case (int)SDL_SCANCODE_KP_:
            return "SDL_SCANCODE_KP_";
        case (int)SDL_SCANCODE_KP_:
            return "SDL_SCANCODE_KP_";
        case (int)SDL_SCANCODE_KP_:
            return "SDL_SCANCODE_KP_";
        case (int)SDL_SCANCODE_KP_:
            return "SDL_SCANCODE_KP_";
        case (int)SDL_SCANCODE_KP_:
            return "SDL_SCANCODE_KP_";
        case (int)SDL_SCANCODE_KP_:
            return "SDL_SCANCODE_KP_";
        case (int)SDL_SCANCODE_KP_PERIOD:
            return "SDL_SCANCODE_KP_PERIOD";
        case (int)SDL_SCANCODE_NONUSBACKSLASH:
            return "SDL_SCANCODE_NONUSBACKSLASH";
        case (int)SDL_SCANCODE_APPLICATION:
            return "SDL_SCANCODE_APPLICATION";
        case (int)SDL_SCANCODE_POWER:
            return "SDL_SCANCODE_POWER";
        case (int)SDL_SCANCODE_KP_EQUALS:
            return "SDL_SCANCODE_KP_EQUALS";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_F:
            return "SDL_SCANCODE_F";
        case (int)SDL_SCANCODE_EXECUTE:
            return "SDL_SCANCODE_EXECUTE";
        case (int)SDL_SCANCODE_HELP:
            return "SDL_SCANCODE_HELP";
        case (int)SDL_SCANCODE_MENU:
            return "SDL_SCANCODE_MENU";
        case (int)SDL_SCANCODE_SELECT:
            return "SDL_SCANCODE_SELECT";
        case (int)SDL_SCANCODE_STOP:
            return "SDL_SCANCODE_STOP";
        case (int)SDL_SCANCODE_AGAIN:
            return "SDL_SCANCODE_AGAIN";
        case (int)SDL_SCANCODE_UNDO:
            return "SDL_SCANCODE_UNDO";
        case (int)SDL_SCANCODE_CUT:
            return "SDL_SCANCODE_CUT";
        case (int)SDL_SCANCODE_COPY:
            return "SDL_SCANCODE_COPY";
        case (int)SDL_SCANCODE_PASTE:
            return "SDL_SCANCODE_PASTE";
        case (int)SDL_SCANCODE_FIND:
            return "SDL_SCANCODE_FIND";
        case (int)SDL_SCANCODE_MUTE:
            return "SDL_SCANCODE_MUTE";
        case (int)SDL_SCANCODE_VOLUMEUP:
            return "SDL_SCANCODE_VOLUMEUP";
        case (int)SDL_SCANCODE_VOLUMEDOWN:
            return "SDL_SCANCODE_VOLUMEDOWN";
        case (int)SDL_SCANCODE_KP_COMMA:
            return "SDL_SCANCODE_KP_COMMA";
        case (int)SDL_SCANCODE_KP_EQUALSAS:
            return "SDL_SCANCODE_KP_EQUALSAS";
        case (int)SDL_SCANCODE_INTERNATIONAL:
            return "SDL_SCANCODE_INTERNATIONAL";
        case (int)SDL_SCANCODE_INTERNATIONAL:
            return "SDL_SCANCODE_INTERNATIONAL";
        case (int)SDL_SCANCODE_INTERNATIONAL:
            return "SDL_SCANCODE_INTERNATIONAL";
        case (int)SDL_SCANCODE_INTERNATIONAL:
            return "SDL_SCANCODE_INTERNATIONAL";
        case (int)SDL_SCANCODE_INTERNATIONAL:
            return "SDL_SCANCODE_INTERNATIONAL";
        case (int)SDL_SCANCODE_INTERNATIONAL:
            return "SDL_SCANCODE_INTERNATIONAL";
        case (int)SDL_SCANCODE_INTERNATIONAL:
            return "SDL_SCANCODE_INTERNATIONAL";
        case (int)SDL_SCANCODE_INTERNATIONAL:
            return "SDL_SCANCODE_INTERNATIONAL";
        case (int)SDL_SCANCODE_INTERNATIONAL:
            return "SDL_SCANCODE_INTERNATIONAL";
        case (int)SDL_SCANCODE_LANG:
            return "SDL_SCANCODE_LANG";
        case (int)SDL_SCANCODE_LANG:
            return "SDL_SCANCODE_LANG";
        case (int)SDL_SCANCODE_LANG:
            return "SDL_SCANCODE_LANG";
        case (int)SDL_SCANCODE_LANG:
            return "SDL_SCANCODE_LANG";
        case (int)SDL_SCANCODE_LANG:
            return "SDL_SCANCODE_LANG";
        case (int)SDL_SCANCODE_LANG:
            return "SDL_SCANCODE_LANG";
        case (int)SDL_SCANCODE_LANG:
            return "SDL_SCANCODE_LANG";
        case (int)SDL_SCANCODE_LANG:
            return "SDL_SCANCODE_LANG";
        case (int)SDL_SCANCODE_LANG:
            return "SDL_SCANCODE_LANG";
        case (int)SDL_SCANCODE_ALTERASE:
            return "SDL_SCANCODE_ALTERASE";
        case (int)SDL_SCANCODE_SYSREQ:
            return "SDL_SCANCODE_SYSREQ";
        case (int)SDL_SCANCODE_CANCEL:
            return "SDL_SCANCODE_CANCEL";
        case (int)SDL_SCANCODE_CLEAR:
            return "SDL_SCANCODE_CLEAR";
        case (int)SDL_SCANCODE_PRIOR:
            return "SDL_SCANCODE_PRIOR";
        case (int)SDL_SCANCODE_RETURN:
            return "SDL_SCANCODE_RETURN";
        case (int)SDL_SCANCODE_SEPARATOR:
            return "SDL_SCANCODE_SEPARATOR";
        case (int)SDL_SCANCODE_OUT:
            return "SDL_SCANCODE_OUT";
        case (int)SDL_SCANCODE_OPER:
            return "SDL_SCANCODE_OPER";
        case (int)SDL_SCANCODE_CLEARAGAIN:
            return "SDL_SCANCODE_CLEARAGAIN";
        case (int)SDL_SCANCODE_CRSEL:
            return "SDL_SCANCODE_CRSEL";
        case (int)SDL_SCANCODE_EXSEL:
            return "SDL_SCANCODE_EXSEL";
        case (int)SDL_SCANCODE_KP_:
            return "SDL_SCANCODE_KP_";
        case (int)SDL_SCANCODE_KP_:
            return "SDL_SCANCODE_KP_";
        case (int)SDL_SCANCODE_THOUSANDSSEPARATOR:
            return "SDL_SCANCODE_THOUSANDSSEPARATOR";
        case (int)SDL_SCANCODE_DECIMALSEPARATOR:
            return "SDL_SCANCODE_DECIMALSEPARATOR";
        case (int)SDL_SCANCODE_CURRENCYUNIT:
            return "SDL_SCANCODE_CURRENCYUNIT";
        case (int)SDL_SCANCODE_CURRENCYSUBUNIT:
            return "SDL_SCANCODE_CURRENCYSUBUNIT";
        case (int)SDL_SCANCODE_KP_LEFTPAREN:
            return "SDL_SCANCODE_KP_LEFTPAREN";
        case (int)SDL_SCANCODE_KP_RIGHTPAREN:
            return "SDL_SCANCODE_KP_RIGHTPAREN";
        case (int)SDL_SCANCODE_KP_LEFTBRACE:
            return "SDL_SCANCODE_KP_LEFTBRACE";
        case (int)SDL_SCANCODE_KP_RIGHTBRACE:
            return "SDL_SCANCODE_KP_RIGHTBRACE";
        case (int)SDL_SCANCODE_KP_TAB:
            return "SDL_SCANCODE_KP_TAB";
        case (int)SDL_SCANCODE_KP_BACKSPACE:
            return "SDL_SCANCODE_KP_BACKSPACE";
        case (int)SDL_SCANCODE_KP_A:
            return "SDL_SCANCODE_KP_A";
        case (int)SDL_SCANCODE_KP_B:
            return "SDL_SCANCODE_KP_B";
        case (int)SDL_SCANCODE_KP_C:
            return "SDL_SCANCODE_KP_C";
        case (int)SDL_SCANCODE_KP_D:
            return "SDL_SCANCODE_KP_D";
        case (int)SDL_SCANCODE_KP_E:
            return "SDL_SCANCODE_KP_E";
        case (int)SDL_SCANCODE_KP_F:
            return "SDL_SCANCODE_KP_F";
        case (int)SDL_SCANCODE_KP_XOR:
            return "SDL_SCANCODE_KP_XOR";
        case (int)SDL_SCANCODE_KP_POWER:
            return "SDL_SCANCODE_KP_POWER";
        case (int)SDL_SCANCODE_KP_PERCENT:
            return "SDL_SCANCODE_KP_PERCENT";
        case (int)SDL_SCANCODE_KP_LESS:
            return "SDL_SCANCODE_KP_LESS";
        case (int)SDL_SCANCODE_KP_GREATER:
            return "SDL_SCANCODE_KP_GREATER";
        case (int)SDL_SCANCODE_KP_AMPERSAND:
            return "SDL_SCANCODE_KP_AMPERSAND";
        case (int)SDL_SCANCODE_KP_DBLAMPERSAND:
            return "SDL_SCANCODE_KP_DBLAMPERSAND";
        case (int)SDL_SCANCODE_KP_VERTICALBAR:
            return "SDL_SCANCODE_KP_VERTICALBAR";
        case (int)SDL_SCANCODE_KP_DBLVERTICALBAR:
            return "SDL_SCANCODE_KP_DBLVERTICALBAR";
        case (int)SDL_SCANCODE_KP_COLON:
            return "SDL_SCANCODE_KP_COLON";
        case (int)SDL_SCANCODE_KP_HASH:
            return "SDL_SCANCODE_KP_HASH";
        case (int)SDL_SCANCODE_KP_SPACE:
            return "SDL_SCANCODE_KP_SPACE";
        case (int)SDL_SCANCODE_KP_AT:
            return "SDL_SCANCODE_KP_AT";
        case (int)SDL_SCANCODE_KP_EXCLAM:
            return "SDL_SCANCODE_KP_EXCLAM";
        case (int)SDL_SCANCODE_KP_MEMSTORE:
            return "SDL_SCANCODE_KP_MEMSTORE";
        case (int)SDL_SCANCODE_KP_MEMRECALL:
            return "SDL_SCANCODE_KP_MEMRECALL";
        case (int)SDL_SCANCODE_KP_MEMCLEAR:
            return "SDL_SCANCODE_KP_MEMCLEAR";
        case (int)SDL_SCANCODE_KP_MEMADD:
            return "SDL_SCANCODE_KP_MEMADD";
        case (int)SDL_SCANCODE_KP_MEMSUBTRACT:
            return "SDL_SCANCODE_KP_MEMSUBTRACT";
        case (int)SDL_SCANCODE_KP_MEMMULTIPLY:
            return "SDL_SCANCODE_KP_MEMMULTIPLY";
        case (int)SDL_SCANCODE_KP_MEMDIVIDE:
            return "SDL_SCANCODE_KP_MEMDIVIDE";
        case (int)SDL_SCANCODE_KP_PLUSMINUS:
            return "SDL_SCANCODE_KP_PLUSMINUS";
        case (int)SDL_SCANCODE_KP_CLEAR:
            return "SDL_SCANCODE_KP_CLEAR";
        case (int)SDL_SCANCODE_KP_CLEARENTRY:
            return "SDL_SCANCODE_KP_CLEARENTRY";
        case (int)SDL_SCANCODE_KP_BINARY:
            return "SDL_SCANCODE_KP_BINARY";
        case (int)SDL_SCANCODE_KP_OCTAL:
            return "SDL_SCANCODE_KP_OCTAL";
        case (int)SDL_SCANCODE_KP_DECIMAL:
            return "SDL_SCANCODE_KP_DECIMAL";
        case (int)SDL_SCANCODE_KP_HEXADECIMAL:
            return "SDL_SCANCODE_KP_HEXADECIMAL";
        case (int)SDL_SCANCODE_LCTRL:
            return "SDL_SCANCODE_LCTRL";
        case (int)SDL_SCANCODE_LSHIFT:
            return "SDL_SCANCODE_LSHIFT";
        case (int)SDL_SCANCODE_LALT:
            return "SDL_SCANCODE_LALT";
        case (int)SDL_SCANCODE_LGUI:
            return "SDL_SCANCODE_LGUI";
        case (int)SDL_SCANCODE_RCTRL:
            return "SDL_SCANCODE_RCTRL";
        case (int)SDL_SCANCODE_RSHIFT:
            return "SDL_SCANCODE_RSHIFT";
        case (int)SDL_SCANCODE_RALT:
            return "SDL_SCANCODE_RALT";
        case (int)SDL_SCANCODE_RGUI:
            return "SDL_SCANCODE_RGUI";
        case (int)SDL_SCANCODE_MODE:
            return "SDL_SCANCODE_MODE";
        case (int)SDL_SCANCODE_AUDIONEXT:
            return "SDL_SCANCODE_AUDIONEXT";
        case (int)SDL_SCANCODE_AUDIOPREV:
            return "SDL_SCANCODE_AUDIOPREV";
        case (int)SDL_SCANCODE_AUDIOSTOP:
            return "SDL_SCANCODE_AUDIOSTOP";
        case (int)SDL_SCANCODE_AUDIOPLAY:
            return "SDL_SCANCODE_AUDIOPLAY";
        case (int)SDL_SCANCODE_AUDIOMUTE:
            return "SDL_SCANCODE_AUDIOMUTE";
        case (int)SDL_SCANCODE_MEDIASELECT:
            return "SDL_SCANCODE_MEDIASELECT";
        case (int)SDL_SCANCODE_WWW:
            return "SDL_SCANCODE_WWW";
        case (int)SDL_SCANCODE_MAIL:
            return "SDL_SCANCODE_MAIL";
        case (int)SDL_SCANCODE_CALCULATOR:
            return "SDL_SCANCODE_CALCULATOR";
        case (int)SDL_SCANCODE_COMPUTER:
            return "SDL_SCANCODE_COMPUTER";
        case (int)SDL_SCANCODE_AC_SEARCH:
            return "SDL_SCANCODE_AC_SEARCH";
        case (int)SDL_SCANCODE_AC_HOME:
            return "SDL_SCANCODE_AC_HOME";
        case (int)SDL_SCANCODE_AC_BACK:
            return "SDL_SCANCODE_AC_BACK";
        case (int)SDL_SCANCODE_AC_FORWARD:
            return "SDL_SCANCODE_AC_FORWARD";
        case (int)SDL_SCANCODE_AC_STOP:
            return "SDL_SCANCODE_AC_STOP";
        case (int)SDL_SCANCODE_AC_REFRESH:
            return "SDL_SCANCODE_AC_REFRESH";
        case (int)SDL_SCANCODE_AC_BOOKMARKS:
            return "SDL_SCANCODE_AC_BOOKMARKS";
        case (int)SDL_SCANCODE_BRIGHTNESSDOWN:
            return "SDL_SCANCODE_BRIGHTNESSDOWN";
        case (int)SDL_SCANCODE_BRIGHTNESSUP:
            return "SDL_SCANCODE_BRIGHTNESSUP";
        case (int)SDL_SCANCODE_DISPLAYSWITCH:
            return "SDL_SCANCODE_DISPLAYSWITCH";
        case (int)SDL_SCANCODE_KBDILLUMTOGGLE:
            return "SDL_SCANCODE_KBDILLUMTOGGLE";
        case (int)SDL_SCANCODE_KBDILLUMDOWN:
            return "SDL_SCANCODE_KBDILLUMDOWN";
        case (int)SDL_SCANCODE_KBDILLUMUP:
            return "SDL_SCANCODE_KBDILLUMUP";
        case (int)SDL_SCANCODE_EJECT:
            return "SDL_SCANCODE_EJECT";
        case (int)SDL_SCANCODE_SLEEP:
            return "SDL_SCANCODE_SLEEP";
        case (int)SDL_SCANCODE_APP:
            return "SDL_SCANCODE_APP";
        case (int)SDL_SCANCODE_APP:
            return "SDL_SCANCODE_APP";
        case (int)SDL_NUM_SCANCODES:
            return "SDL_NUM_SCANCODES";
    }
    return "";
}

void from_string(std::string const& val, /* OUT */ ef& out_val) {
    if (val == "SDL_SCANCODE_UNKNOWN") {
        out_val = SDL_SCANCODE_UNKNOWN;
    } else if (val == "SDL_SCANCODE_A") {
        out_val = SDL_SCANCODE_A;
    } else if (val == "SDL_SCANCODE_B") {
        out_val = SDL_SCANCODE_B;
    } else if (val == "SDL_SCANCODE_C") {
        out_val = SDL_SCANCODE_C;
    } else if (val == "SDL_SCANCODE_D") {
        out_val = SDL_SCANCODE_D;
    } else if (val == "SDL_SCANCODE_E") {
        out_val = SDL_SCANCODE_E;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_G") {
        out_val = SDL_SCANCODE_G;
    } else if (val == "SDL_SCANCODE_H") {
        out_val = SDL_SCANCODE_H;
    } else if (val == "SDL_SCANCODE_I") {
        out_val = SDL_SCANCODE_I;
    } else if (val == "SDL_SCANCODE_J") {
        out_val = SDL_SCANCODE_J;
    } else if (val == "SDL_SCANCODE_K") {
        out_val = SDL_SCANCODE_K;
    } else if (val == "SDL_SCANCODE_L") {
        out_val = SDL_SCANCODE_L;
    } else if (val == "SDL_SCANCODE_M") {
        out_val = SDL_SCANCODE_M;
    } else if (val == "SDL_SCANCODE_N") {
        out_val = SDL_SCANCODE_N;
    } else if (val == "SDL_SCANCODE_O") {
        out_val = SDL_SCANCODE_O;
    } else if (val == "SDL_SCANCODE_P") {
        out_val = SDL_SCANCODE_P;
    } else if (val == "SDL_SCANCODE_Q") {
        out_val = SDL_SCANCODE_Q;
    } else if (val == "SDL_SCANCODE_R") {
        out_val = SDL_SCANCODE_R;
    } else if (val == "SDL_SCANCODE_S") {
        out_val = SDL_SCANCODE_S;
    } else if (val == "SDL_SCANCODE_T") {
        out_val = SDL_SCANCODE_T;
    } else if (val == "SDL_SCANCODE_U") {
        out_val = SDL_SCANCODE_U;
    } else if (val == "SDL_SCANCODE_V") {
        out_val = SDL_SCANCODE_V;
    } else if (val == "SDL_SCANCODE_W") {
        out_val = SDL_SCANCODE_W;
    } else if (val == "SDL_SCANCODE_X") {
        out_val = SDL_SCANCODE_X;
    } else if (val == "SDL_SCANCODE_Y") {
        out_val = SDL_SCANCODE_Y;
    } else if (val == "SDL_SCANCODE_Z") {
        out_val = SDL_SCANCODE_Z;
    } else if (val == "SDL_SCANCODE_") {
        out_val = SDL_SCANCODE_;
    } else if (val == "SDL_SCANCODE_") {
        out_val = SDL_SCANCODE_;
    } else if (val == "SDL_SCANCODE_") {
        out_val = SDL_SCANCODE_;
    } else if (val == "SDL_SCANCODE_") {
        out_val = SDL_SCANCODE_;
    } else if (val == "SDL_SCANCODE_") {
        out_val = SDL_SCANCODE_;
    } else if (val == "SDL_SCANCODE_") {
        out_val = SDL_SCANCODE_;
    } else if (val == "SDL_SCANCODE_") {
        out_val = SDL_SCANCODE_;
    } else if (val == "SDL_SCANCODE_") {
        out_val = SDL_SCANCODE_;
    } else if (val == "SDL_SCANCODE_") {
        out_val = SDL_SCANCODE_;
    } else if (val == "SDL_SCANCODE_") {
        out_val = SDL_SCANCODE_;
    } else if (val == "SDL_SCANCODE_RETURN") {
        out_val = SDL_SCANCODE_RETURN;
    } else if (val == "SDL_SCANCODE_ESCAPE") {
        out_val = SDL_SCANCODE_ESCAPE;
    } else if (val == "SDL_SCANCODE_BACKSPACE") {
        out_val = SDL_SCANCODE_BACKSPACE;
    } else if (val == "SDL_SCANCODE_TAB") {
        out_val = SDL_SCANCODE_TAB;
    } else if (val == "SDL_SCANCODE_SPACE") {
        out_val = SDL_SCANCODE_SPACE;
    } else if (val == "SDL_SCANCODE_MINUS") {
        out_val = SDL_SCANCODE_MINUS;
    } else if (val == "SDL_SCANCODE_EQUALS") {
        out_val = SDL_SCANCODE_EQUALS;
    } else if (val == "SDL_SCANCODE_LEFTBRACKET") {
        out_val = SDL_SCANCODE_LEFTBRACKET;
    } else if (val == "SDL_SCANCODE_RIGHTBRACKET") {
        out_val = SDL_SCANCODE_RIGHTBRACKET;
    } else if (val == "SDL_SCANCODE_BACKSLASH") {
        out_val = SDL_SCANCODE_BACKSLASH;
    } else if (val == "SDL_SCANCODE_NONUSHASH") {
        out_val = SDL_SCANCODE_NONUSHASH;
    } else if (val == "SDL_SCANCODE_SEMICOLON") {
        out_val = SDL_SCANCODE_SEMICOLON;
    } else if (val == "SDL_SCANCODE_APOSTROPHE") {
        out_val = SDL_SCANCODE_APOSTROPHE;
    } else if (val == "SDL_SCANCODE_GRAVE") {
        out_val = SDL_SCANCODE_GRAVE;
    } else if (val == "SDL_SCANCODE_COMMA") {
        out_val = SDL_SCANCODE_COMMA;
    } else if (val == "SDL_SCANCODE_PERIOD") {
        out_val = SDL_SCANCODE_PERIOD;
    } else if (val == "SDL_SCANCODE_SLASH") {
        out_val = SDL_SCANCODE_SLASH;
    } else if (val == "SDL_SCANCODE_CAPSLOCK") {
        out_val = SDL_SCANCODE_CAPSLOCK;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_PRINTSCREEN") {
        out_val = SDL_SCANCODE_PRINTSCREEN;
    } else if (val == "SDL_SCANCODE_SCROLLLOCK") {
        out_val = SDL_SCANCODE_SCROLLLOCK;
    } else if (val == "SDL_SCANCODE_PAUSE") {
        out_val = SDL_SCANCODE_PAUSE;
    } else if (val == "SDL_SCANCODE_INSERT") {
        out_val = SDL_SCANCODE_INSERT;
    } else if (val == "SDL_SCANCODE_HOME") {
        out_val = SDL_SCANCODE_HOME;
    } else if (val == "SDL_SCANCODE_PAGEUP") {
        out_val = SDL_SCANCODE_PAGEUP;
    } else if (val == "SDL_SCANCODE_DELETE") {
        out_val = SDL_SCANCODE_DELETE;
    } else if (val == "SDL_SCANCODE_END") {
        out_val = SDL_SCANCODE_END;
    } else if (val == "SDL_SCANCODE_PAGEDOWN") {
        out_val = SDL_SCANCODE_PAGEDOWN;
    } else if (val == "SDL_SCANCODE_RIGHT") {
        out_val = SDL_SCANCODE_RIGHT;
    } else if (val == "SDL_SCANCODE_LEFT") {
        out_val = SDL_SCANCODE_LEFT;
    } else if (val == "SDL_SCANCODE_DOWN") {
        out_val = SDL_SCANCODE_DOWN;
    } else if (val == "SDL_SCANCODE_UP") {
        out_val = SDL_SCANCODE_UP;
    } else if (val == "SDL_SCANCODE_NUMLOCKCLEAR") {
        out_val = SDL_SCANCODE_NUMLOCKCLEAR;
    } else if (val == "SDL_SCANCODE_KP_DIVIDE") {
        out_val = SDL_SCANCODE_KP_DIVIDE;
    } else if (val == "SDL_SCANCODE_KP_MULTIPLY") {
        out_val = SDL_SCANCODE_KP_MULTIPLY;
    } else if (val == "SDL_SCANCODE_KP_MINUS") {
        out_val = SDL_SCANCODE_KP_MINUS;
    } else if (val == "SDL_SCANCODE_KP_PLUS") {
        out_val = SDL_SCANCODE_KP_PLUS;
    } else if (val == "SDL_SCANCODE_KP_ENTER") {
        out_val = SDL_SCANCODE_KP_ENTER;
    } else if (val == "SDL_SCANCODE_KP_") {
        out_val = SDL_SCANCODE_KP_;
    } else if (val == "SDL_SCANCODE_KP_") {
        out_val = SDL_SCANCODE_KP_;
    } else if (val == "SDL_SCANCODE_KP_") {
        out_val = SDL_SCANCODE_KP_;
    } else if (val == "SDL_SCANCODE_KP_") {
        out_val = SDL_SCANCODE_KP_;
    } else if (val == "SDL_SCANCODE_KP_") {
        out_val = SDL_SCANCODE_KP_;
    } else if (val == "SDL_SCANCODE_KP_") {
        out_val = SDL_SCANCODE_KP_;
    } else if (val == "SDL_SCANCODE_KP_") {
        out_val = SDL_SCANCODE_KP_;
    } else if (val == "SDL_SCANCODE_KP_") {
        out_val = SDL_SCANCODE_KP_;
    } else if (val == "SDL_SCANCODE_KP_") {
        out_val = SDL_SCANCODE_KP_;
    } else if (val == "SDL_SCANCODE_KP_") {
        out_val = SDL_SCANCODE_KP_;
    } else if (val == "SDL_SCANCODE_KP_PERIOD") {
        out_val = SDL_SCANCODE_KP_PERIOD;
    } else if (val == "SDL_SCANCODE_NONUSBACKSLASH") {
        out_val = SDL_SCANCODE_NONUSBACKSLASH;
    } else if (val == "SDL_SCANCODE_APPLICATION") {
        out_val = SDL_SCANCODE_APPLICATION;
    } else if (val == "SDL_SCANCODE_POWER") {
        out_val = SDL_SCANCODE_POWER;
    } else if (val == "SDL_SCANCODE_KP_EQUALS") {
        out_val = SDL_SCANCODE_KP_EQUALS;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_F") {
        out_val = SDL_SCANCODE_F;
    } else if (val == "SDL_SCANCODE_EXECUTE") {
        out_val = SDL_SCANCODE_EXECUTE;
    } else if (val == "SDL_SCANCODE_HELP") {
        out_val = SDL_SCANCODE_HELP;
    } else if (val == "SDL_SCANCODE_MENU") {
        out_val = SDL_SCANCODE_MENU;
    } else if (val == "SDL_SCANCODE_SELECT") {
        out_val = SDL_SCANCODE_SELECT;
    } else if (val == "SDL_SCANCODE_STOP") {
        out_val = SDL_SCANCODE_STOP;
    } else if (val == "SDL_SCANCODE_AGAIN") {
        out_val = SDL_SCANCODE_AGAIN;
    } else if (val == "SDL_SCANCODE_UNDO") {
        out_val = SDL_SCANCODE_UNDO;
    } else if (val == "SDL_SCANCODE_CUT") {
        out_val = SDL_SCANCODE_CUT;
    } else if (val == "SDL_SCANCODE_COPY") {
        out_val = SDL_SCANCODE_COPY;
    } else if (val == "SDL_SCANCODE_PASTE") {
        out_val = SDL_SCANCODE_PASTE;
    } else if (val == "SDL_SCANCODE_FIND") {
        out_val = SDL_SCANCODE_FIND;
    } else if (val == "SDL_SCANCODE_MUTE") {
        out_val = SDL_SCANCODE_MUTE;
    } else if (val == "SDL_SCANCODE_VOLUMEUP") {
        out_val = SDL_SCANCODE_VOLUMEUP;
    } else if (val == "SDL_SCANCODE_VOLUMEDOWN") {
        out_val = SDL_SCANCODE_VOLUMEDOWN;
    } else if (val == "SDL_SCANCODE_KP_COMMA") {
        out_val = SDL_SCANCODE_KP_COMMA;
    } else if (val == "SDL_SCANCODE_KP_EQUALSAS") {
        out_val = SDL_SCANCODE_KP_EQUALSAS;
    } else if (val == "SDL_SCANCODE_INTERNATIONAL") {
        out_val = SDL_SCANCODE_INTERNATIONAL;
    } else if (val == "SDL_SCANCODE_INTERNATIONAL") {
        out_val = SDL_SCANCODE_INTERNATIONAL;
    } else if (val == "SDL_SCANCODE_INTERNATIONAL") {
        out_val = SDL_SCANCODE_INTERNATIONAL;
    } else if (val == "SDL_SCANCODE_INTERNATIONAL") {
        out_val = SDL_SCANCODE_INTERNATIONAL;
    } else if (val == "SDL_SCANCODE_INTERNATIONAL") {
        out_val = SDL_SCANCODE_INTERNATIONAL;
    } else if (val == "SDL_SCANCODE_INTERNATIONAL") {
        out_val = SDL_SCANCODE_INTERNATIONAL;
    } else if (val == "SDL_SCANCODE_INTERNATIONAL") {
        out_val = SDL_SCANCODE_INTERNATIONAL;
    } else if (val == "SDL_SCANCODE_INTERNATIONAL") {
        out_val = SDL_SCANCODE_INTERNATIONAL;
    } else if (val == "SDL_SCANCODE_INTERNATIONAL") {
        out_val = SDL_SCANCODE_INTERNATIONAL;
    } else if (val == "SDL_SCANCODE_LANG") {
        out_val = SDL_SCANCODE_LANG;
    } else if (val == "SDL_SCANCODE_LANG") {
        out_val = SDL_SCANCODE_LANG;
    } else if (val == "SDL_SCANCODE_LANG") {
        out_val = SDL_SCANCODE_LANG;
    } else if (val == "SDL_SCANCODE_LANG") {
        out_val = SDL_SCANCODE_LANG;
    } else if (val == "SDL_SCANCODE_LANG") {
        out_val = SDL_SCANCODE_LANG;
    } else if (val == "SDL_SCANCODE_LANG") {
        out_val = SDL_SCANCODE_LANG;
    } else if (val == "SDL_SCANCODE_LANG") {
        out_val = SDL_SCANCODE_LANG;
    } else if (val == "SDL_SCANCODE_LANG") {
        out_val = SDL_SCANCODE_LANG;
    } else if (val == "SDL_SCANCODE_LANG") {
        out_val = SDL_SCANCODE_LANG;
    } else if (val == "SDL_SCANCODE_ALTERASE") {
        out_val = SDL_SCANCODE_ALTERASE;
    } else if (val == "SDL_SCANCODE_SYSREQ") {
        out_val = SDL_SCANCODE_SYSREQ;
    } else if (val == "SDL_SCANCODE_CANCEL") {
        out_val = SDL_SCANCODE_CANCEL;
    } else if (val == "SDL_SCANCODE_CLEAR") {
        out_val = SDL_SCANCODE_CLEAR;
    } else if (val == "SDL_SCANCODE_PRIOR") {
        out_val = SDL_SCANCODE_PRIOR;
    } else if (val == "SDL_SCANCODE_RETURN") {
        out_val = SDL_SCANCODE_RETURN;
    } else if (val == "SDL_SCANCODE_SEPARATOR") {
        out_val = SDL_SCANCODE_SEPARATOR;
    } else if (val == "SDL_SCANCODE_OUT") {
        out_val = SDL_SCANCODE_OUT;
    } else if (val == "SDL_SCANCODE_OPER") {
        out_val = SDL_SCANCODE_OPER;
    } else if (val == "SDL_SCANCODE_CLEARAGAIN") {
        out_val = SDL_SCANCODE_CLEARAGAIN;
    } else if (val == "SDL_SCANCODE_CRSEL") {
        out_val = SDL_SCANCODE_CRSEL;
    } else if (val == "SDL_SCANCODE_EXSEL") {
        out_val = SDL_SCANCODE_EXSEL;
    } else if (val == "SDL_SCANCODE_KP_") {
        out_val = SDL_SCANCODE_KP_;
    } else if (val == "SDL_SCANCODE_KP_") {
        out_val = SDL_SCANCODE_KP_;
    } else if (val == "SDL_SCANCODE_THOUSANDSSEPARATOR") {
        out_val = SDL_SCANCODE_THOUSANDSSEPARATOR;
    } else if (val == "SDL_SCANCODE_DECIMALSEPARATOR") {
        out_val = SDL_SCANCODE_DECIMALSEPARATOR;
    } else if (val == "SDL_SCANCODE_CURRENCYUNIT") {
        out_val = SDL_SCANCODE_CURRENCYUNIT;
    } else if (val == "SDL_SCANCODE_CURRENCYSUBUNIT") {
        out_val = SDL_SCANCODE_CURRENCYSUBUNIT;
    } else if (val == "SDL_SCANCODE_KP_LEFTPAREN") {
        out_val = SDL_SCANCODE_KP_LEFTPAREN;
    } else if (val == "SDL_SCANCODE_KP_RIGHTPAREN") {
        out_val = SDL_SCANCODE_KP_RIGHTPAREN;
    } else if (val == "SDL_SCANCODE_KP_LEFTBRACE") {
        out_val = SDL_SCANCODE_KP_LEFTBRACE;
    } else if (val == "SDL_SCANCODE_KP_RIGHTBRACE") {
        out_val = SDL_SCANCODE_KP_RIGHTBRACE;
    } else if (val == "SDL_SCANCODE_KP_TAB") {
        out_val = SDL_SCANCODE_KP_TAB;
    } else if (val == "SDL_SCANCODE_KP_BACKSPACE") {
        out_val = SDL_SCANCODE_KP_BACKSPACE;
    } else if (val == "SDL_SCANCODE_KP_A") {
        out_val = SDL_SCANCODE_KP_A;
    } else if (val == "SDL_SCANCODE_KP_B") {
        out_val = SDL_SCANCODE_KP_B;
    } else if (val == "SDL_SCANCODE_KP_C") {
        out_val = SDL_SCANCODE_KP_C;
    } else if (val == "SDL_SCANCODE_KP_D") {
        out_val = SDL_SCANCODE_KP_D;
    } else if (val == "SDL_SCANCODE_KP_E") {
        out_val = SDL_SCANCODE_KP_E;
    } else if (val == "SDL_SCANCODE_KP_F") {
        out_val = SDL_SCANCODE_KP_F;
    } else if (val == "SDL_SCANCODE_KP_XOR") {
        out_val = SDL_SCANCODE_KP_XOR;
    } else if (val == "SDL_SCANCODE_KP_POWER") {
        out_val = SDL_SCANCODE_KP_POWER;
    } else if (val == "SDL_SCANCODE_KP_PERCENT") {
        out_val = SDL_SCANCODE_KP_PERCENT;
    } else if (val == "SDL_SCANCODE_KP_LESS") {
        out_val = SDL_SCANCODE_KP_LESS;
    } else if (val == "SDL_SCANCODE_KP_GREATER") {
        out_val = SDL_SCANCODE_KP_GREATER;
    } else if (val == "SDL_SCANCODE_KP_AMPERSAND") {
        out_val = SDL_SCANCODE_KP_AMPERSAND;
    } else if (val == "SDL_SCANCODE_KP_DBLAMPERSAND") {
        out_val = SDL_SCANCODE_KP_DBLAMPERSAND;
    } else if (val == "SDL_SCANCODE_KP_VERTICALBAR") {
        out_val = SDL_SCANCODE_KP_VERTICALBAR;
    } else if (val == "SDL_SCANCODE_KP_DBLVERTICALBAR") {
        out_val = SDL_SCANCODE_KP_DBLVERTICALBAR;
    } else if (val == "SDL_SCANCODE_KP_COLON") {
        out_val = SDL_SCANCODE_KP_COLON;
    } else if (val == "SDL_SCANCODE_KP_HASH") {
        out_val = SDL_SCANCODE_KP_HASH;
    } else if (val == "SDL_SCANCODE_KP_SPACE") {
        out_val = SDL_SCANCODE_KP_SPACE;
    } else if (val == "SDL_SCANCODE_KP_AT") {
        out_val = SDL_SCANCODE_KP_AT;
    } else if (val == "SDL_SCANCODE_KP_EXCLAM") {
        out_val = SDL_SCANCODE_KP_EXCLAM;
    } else if (val == "SDL_SCANCODE_KP_MEMSTORE") {
        out_val = SDL_SCANCODE_KP_MEMSTORE;
    } else if (val == "SDL_SCANCODE_KP_MEMRECALL") {
        out_val = SDL_SCANCODE_KP_MEMRECALL;
    } else if (val == "SDL_SCANCODE_KP_MEMCLEAR") {
        out_val = SDL_SCANCODE_KP_MEMCLEAR;
    } else if (val == "SDL_SCANCODE_KP_MEMADD") {
        out_val = SDL_SCANCODE_KP_MEMADD;
    } else if (val == "SDL_SCANCODE_KP_MEMSUBTRACT") {
        out_val = SDL_SCANCODE_KP_MEMSUBTRACT;
    } else if (val == "SDL_SCANCODE_KP_MEMMULTIPLY") {
        out_val = SDL_SCANCODE_KP_MEMMULTIPLY;
    } else if (val == "SDL_SCANCODE_KP_MEMDIVIDE") {
        out_val = SDL_SCANCODE_KP_MEMDIVIDE;
    } else if (val == "SDL_SCANCODE_KP_PLUSMINUS") {
        out_val = SDL_SCANCODE_KP_PLUSMINUS;
    } else if (val == "SDL_SCANCODE_KP_CLEAR") {
        out_val = SDL_SCANCODE_KP_CLEAR;
    } else if (val == "SDL_SCANCODE_KP_CLEARENTRY") {
        out_val = SDL_SCANCODE_KP_CLEARENTRY;
    } else if (val == "SDL_SCANCODE_KP_BINARY") {
        out_val = SDL_SCANCODE_KP_BINARY;
    } else if (val == "SDL_SCANCODE_KP_OCTAL") {
        out_val = SDL_SCANCODE_KP_OCTAL;
    } else if (val == "SDL_SCANCODE_KP_DECIMAL") {
        out_val = SDL_SCANCODE_KP_DECIMAL;
    } else if (val == "SDL_SCANCODE_KP_HEXADECIMAL") {
        out_val = SDL_SCANCODE_KP_HEXADECIMAL;
    } else if (val == "SDL_SCANCODE_LCTRL") {
        out_val = SDL_SCANCODE_LCTRL;
    } else if (val == "SDL_SCANCODE_LSHIFT") {
        out_val = SDL_SCANCODE_LSHIFT;
    } else if (val == "SDL_SCANCODE_LALT") {
        out_val = SDL_SCANCODE_LALT;
    } else if (val == "SDL_SCANCODE_LGUI") {
        out_val = SDL_SCANCODE_LGUI;
    } else if (val == "SDL_SCANCODE_RCTRL") {
        out_val = SDL_SCANCODE_RCTRL;
    } else if (val == "SDL_SCANCODE_RSHIFT") {
        out_val = SDL_SCANCODE_RSHIFT;
    } else if (val == "SDL_SCANCODE_RALT") {
        out_val = SDL_SCANCODE_RALT;
    } else if (val == "SDL_SCANCODE_RGUI") {
        out_val = SDL_SCANCODE_RGUI;
    } else if (val == "SDL_SCANCODE_MODE") {
        out_val = SDL_SCANCODE_MODE;
    } else if (val == "SDL_SCANCODE_AUDIONEXT") {
        out_val = SDL_SCANCODE_AUDIONEXT;
    } else if (val == "SDL_SCANCODE_AUDIOPREV") {
        out_val = SDL_SCANCODE_AUDIOPREV;
    } else if (val == "SDL_SCANCODE_AUDIOSTOP") {
        out_val = SDL_SCANCODE_AUDIOSTOP;
    } else if (val == "SDL_SCANCODE_AUDIOPLAY") {
        out_val = SDL_SCANCODE_AUDIOPLAY;
    } else if (val == "SDL_SCANCODE_AUDIOMUTE") {
        out_val = SDL_SCANCODE_AUDIOMUTE;
    } else if (val == "SDL_SCANCODE_MEDIASELECT") {
        out_val = SDL_SCANCODE_MEDIASELECT;
    } else if (val == "SDL_SCANCODE_WWW") {
        out_val = SDL_SCANCODE_WWW;
    } else if (val == "SDL_SCANCODE_MAIL") {
        out_val = SDL_SCANCODE_MAIL;
    } else if (val == "SDL_SCANCODE_CALCULATOR") {
        out_val = SDL_SCANCODE_CALCULATOR;
    } else if (val == "SDL_SCANCODE_COMPUTER") {
        out_val = SDL_SCANCODE_COMPUTER;
    } else if (val == "SDL_SCANCODE_AC_SEARCH") {
        out_val = SDL_SCANCODE_AC_SEARCH;
    } else if (val == "SDL_SCANCODE_AC_HOME") {
        out_val = SDL_SCANCODE_AC_HOME;
    } else if (val == "SDL_SCANCODE_AC_BACK") {
        out_val = SDL_SCANCODE_AC_BACK;
    } else if (val == "SDL_SCANCODE_AC_FORWARD") {
        out_val = SDL_SCANCODE_AC_FORWARD;
    } else if (val == "SDL_SCANCODE_AC_STOP") {
        out_val = SDL_SCANCODE_AC_STOP;
    } else if (val == "SDL_SCANCODE_AC_REFRESH") {
        out_val = SDL_SCANCODE_AC_REFRESH;
    } else if (val == "SDL_SCANCODE_AC_BOOKMARKS") {
        out_val = SDL_SCANCODE_AC_BOOKMARKS;
    } else if (val == "SDL_SCANCODE_BRIGHTNESSDOWN") {
        out_val = SDL_SCANCODE_BRIGHTNESSDOWN;
    } else if (val == "SDL_SCANCODE_BRIGHTNESSUP") {
        out_val = SDL_SCANCODE_BRIGHTNESSUP;
    } else if (val == "SDL_SCANCODE_DISPLAYSWITCH") {
        out_val = SDL_SCANCODE_DISPLAYSWITCH;
    } else if (val == "SDL_SCANCODE_KBDILLUMTOGGLE") {
        out_val = SDL_SCANCODE_KBDILLUMTOGGLE;
    } else if (val == "SDL_SCANCODE_KBDILLUMDOWN") {
        out_val = SDL_SCANCODE_KBDILLUMDOWN;
    } else if (val == "SDL_SCANCODE_KBDILLUMUP") {
        out_val = SDL_SCANCODE_KBDILLUMUP;
    } else if (val == "SDL_SCANCODE_EJECT") {
        out_val = SDL_SCANCODE_EJECT;
    } else if (val == "SDL_SCANCODE_SLEEP") {
        out_val = SDL_SCANCODE_SLEEP;
    } else if (val == "SDL_SCANCODE_APP") {
        out_val = SDL_SCANCODE_APP;
    } else if (val == "SDL_SCANCODE_APP") {
        out_val = SDL_SCANCODE_APP;
    } else if (val == "SDL_NUM_SCANCODES") {
        out_val = SDL_NUM_SCANCODES;
    } else {
        std::ostringstream oss;
        oss << "ef unknown match in string:" << val;
        throw std::runtime_error(oss.str());
    }
}

int to_int(ef const& val) { return (int)val; }

void from_int(int const& val, /* OUT */ ef& out_val) {
    switch (val) {
        case (int)SDL_SCANCODE_UNKNOWN:
            out_val = SDL_SCANCODE_UNKNOWN;
            break;
        case (int)SDL_SCANCODE_A:
            out_val = SDL_SCANCODE_A;
            break;
        case (int)SDL_SCANCODE_B:
            out_val = SDL_SCANCODE_B;
            break;
        case (int)SDL_SCANCODE_C:
            out_val = SDL_SCANCODE_C;
            break;
        case (int)SDL_SCANCODE_D:
            out_val = SDL_SCANCODE_D;
            break;
        case (int)SDL_SCANCODE_E:
            out_val = SDL_SCANCODE_E;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_G:
            out_val = SDL_SCANCODE_G;
            break;
        case (int)SDL_SCANCODE_H:
            out_val = SDL_SCANCODE_H;
            break;
        case (int)SDL_SCANCODE_I:
            out_val = SDL_SCANCODE_I;
            break;
        case (int)SDL_SCANCODE_J:
            out_val = SDL_SCANCODE_J;
            break;
        case (int)SDL_SCANCODE_K:
            out_val = SDL_SCANCODE_K;
            break;
        case (int)SDL_SCANCODE_L:
            out_val = SDL_SCANCODE_L;
            break;
        case (int)SDL_SCANCODE_M:
            out_val = SDL_SCANCODE_M;
            break;
        case (int)SDL_SCANCODE_N:
            out_val = SDL_SCANCODE_N;
            break;
        case (int)SDL_SCANCODE_O:
            out_val = SDL_SCANCODE_O;
            break;
        case (int)SDL_SCANCODE_P:
            out_val = SDL_SCANCODE_P;
            break;
        case (int)SDL_SCANCODE_Q:
            out_val = SDL_SCANCODE_Q;
            break;
        case (int)SDL_SCANCODE_R:
            out_val = SDL_SCANCODE_R;
            break;
        case (int)SDL_SCANCODE_S:
            out_val = SDL_SCANCODE_S;
            break;
        case (int)SDL_SCANCODE_T:
            out_val = SDL_SCANCODE_T;
            break;
        case (int)SDL_SCANCODE_U:
            out_val = SDL_SCANCODE_U;
            break;
        case (int)SDL_SCANCODE_V:
            out_val = SDL_SCANCODE_V;
            break;
        case (int)SDL_SCANCODE_W:
            out_val = SDL_SCANCODE_W;
            break;
        case (int)SDL_SCANCODE_X:
            out_val = SDL_SCANCODE_X;
            break;
        case (int)SDL_SCANCODE_Y:
            out_val = SDL_SCANCODE_Y;
            break;
        case (int)SDL_SCANCODE_Z:
            out_val = SDL_SCANCODE_Z;
            break;
        case (int)SDL_SCANCODE_:
            out_val = SDL_SCANCODE_;
            break;
        case (int)SDL_SCANCODE_:
            out_val = SDL_SCANCODE_;
            break;
        case (int)SDL_SCANCODE_:
            out_val = SDL_SCANCODE_;
            break;
        case (int)SDL_SCANCODE_:
            out_val = SDL_SCANCODE_;
            break;
        case (int)SDL_SCANCODE_:
            out_val = SDL_SCANCODE_;
            break;
        case (int)SDL_SCANCODE_:
            out_val = SDL_SCANCODE_;
            break;
        case (int)SDL_SCANCODE_:
            out_val = SDL_SCANCODE_;
            break;
        case (int)SDL_SCANCODE_:
            out_val = SDL_SCANCODE_;
            break;
        case (int)SDL_SCANCODE_:
            out_val = SDL_SCANCODE_;
            break;
        case (int)SDL_SCANCODE_:
            out_val = SDL_SCANCODE_;
            break;
        case (int)SDL_SCANCODE_RETURN:
            out_val = SDL_SCANCODE_RETURN;
            break;
        case (int)SDL_SCANCODE_ESCAPE:
            out_val = SDL_SCANCODE_ESCAPE;
            break;
        case (int)SDL_SCANCODE_BACKSPACE:
            out_val = SDL_SCANCODE_BACKSPACE;
            break;
        case (int)SDL_SCANCODE_TAB:
            out_val = SDL_SCANCODE_TAB;
            break;
        case (int)SDL_SCANCODE_SPACE:
            out_val = SDL_SCANCODE_SPACE;
            break;
        case (int)SDL_SCANCODE_MINUS:
            out_val = SDL_SCANCODE_MINUS;
            break;
        case (int)SDL_SCANCODE_EQUALS:
            out_val = SDL_SCANCODE_EQUALS;
            break;
        case (int)SDL_SCANCODE_LEFTBRACKET:
            out_val = SDL_SCANCODE_LEFTBRACKET;
            break;
        case (int)SDL_SCANCODE_RIGHTBRACKET:
            out_val = SDL_SCANCODE_RIGHTBRACKET;
            break;
        case (int)SDL_SCANCODE_BACKSLASH:
            out_val = SDL_SCANCODE_BACKSLASH;
            break;
        case (int)SDL_SCANCODE_NONUSHASH:
            out_val = SDL_SCANCODE_NONUSHASH;
            break;
        case (int)SDL_SCANCODE_SEMICOLON:
            out_val = SDL_SCANCODE_SEMICOLON;
            break;
        case (int)SDL_SCANCODE_APOSTROPHE:
            out_val = SDL_SCANCODE_APOSTROPHE;
            break;
        case (int)SDL_SCANCODE_GRAVE:
            out_val = SDL_SCANCODE_GRAVE;
            break;
        case (int)SDL_SCANCODE_COMMA:
            out_val = SDL_SCANCODE_COMMA;
            break;
        case (int)SDL_SCANCODE_PERIOD:
            out_val = SDL_SCANCODE_PERIOD;
            break;
        case (int)SDL_SCANCODE_SLASH:
            out_val = SDL_SCANCODE_SLASH;
            break;
        case (int)SDL_SCANCODE_CAPSLOCK:
            out_val = SDL_SCANCODE_CAPSLOCK;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_PRINTSCREEN:
            out_val = SDL_SCANCODE_PRINTSCREEN;
            break;
        case (int)SDL_SCANCODE_SCROLLLOCK:
            out_val = SDL_SCANCODE_SCROLLLOCK;
            break;
        case (int)SDL_SCANCODE_PAUSE:
            out_val = SDL_SCANCODE_PAUSE;
            break;
        case (int)SDL_SCANCODE_INSERT:
            out_val = SDL_SCANCODE_INSERT;
            break;
        case (int)SDL_SCANCODE_HOME:
            out_val = SDL_SCANCODE_HOME;
            break;
        case (int)SDL_SCANCODE_PAGEUP:
            out_val = SDL_SCANCODE_PAGEUP;
            break;
        case (int)SDL_SCANCODE_DELETE:
            out_val = SDL_SCANCODE_DELETE;
            break;
        case (int)SDL_SCANCODE_END:
            out_val = SDL_SCANCODE_END;
            break;
        case (int)SDL_SCANCODE_PAGEDOWN:
            out_val = SDL_SCANCODE_PAGEDOWN;
            break;
        case (int)SDL_SCANCODE_RIGHT:
            out_val = SDL_SCANCODE_RIGHT;
            break;
        case (int)SDL_SCANCODE_LEFT:
            out_val = SDL_SCANCODE_LEFT;
            break;
        case (int)SDL_SCANCODE_DOWN:
            out_val = SDL_SCANCODE_DOWN;
            break;
        case (int)SDL_SCANCODE_UP:
            out_val = SDL_SCANCODE_UP;
            break;
        case (int)SDL_SCANCODE_NUMLOCKCLEAR:
            out_val = SDL_SCANCODE_NUMLOCKCLEAR;
            break;
        case (int)SDL_SCANCODE_KP_DIVIDE:
            out_val = SDL_SCANCODE_KP_DIVIDE;
            break;
        case (int)SDL_SCANCODE_KP_MULTIPLY:
            out_val = SDL_SCANCODE_KP_MULTIPLY;
            break;
        case (int)SDL_SCANCODE_KP_MINUS:
            out_val = SDL_SCANCODE_KP_MINUS;
            break;
        case (int)SDL_SCANCODE_KP_PLUS:
            out_val = SDL_SCANCODE_KP_PLUS;
            break;
        case (int)SDL_SCANCODE_KP_ENTER:
            out_val = SDL_SCANCODE_KP_ENTER;
            break;
        case (int)SDL_SCANCODE_KP_:
            out_val = SDL_SCANCODE_KP_;
            break;
        case (int)SDL_SCANCODE_KP_:
            out_val = SDL_SCANCODE_KP_;
            break;
        case (int)SDL_SCANCODE_KP_:
            out_val = SDL_SCANCODE_KP_;
            break;
        case (int)SDL_SCANCODE_KP_:
            out_val = SDL_SCANCODE_KP_;
            break;
        case (int)SDL_SCANCODE_KP_:
            out_val = SDL_SCANCODE_KP_;
            break;
        case (int)SDL_SCANCODE_KP_:
            out_val = SDL_SCANCODE_KP_;
            break;
        case (int)SDL_SCANCODE_KP_:
            out_val = SDL_SCANCODE_KP_;
            break;
        case (int)SDL_SCANCODE_KP_:
            out_val = SDL_SCANCODE_KP_;
            break;
        case (int)SDL_SCANCODE_KP_:
            out_val = SDL_SCANCODE_KP_;
            break;
        case (int)SDL_SCANCODE_KP_:
            out_val = SDL_SCANCODE_KP_;
            break;
        case (int)SDL_SCANCODE_KP_PERIOD:
            out_val = SDL_SCANCODE_KP_PERIOD;
            break;
        case (int)SDL_SCANCODE_NONUSBACKSLASH:
            out_val = SDL_SCANCODE_NONUSBACKSLASH;
            break;
        case (int)SDL_SCANCODE_APPLICATION:
            out_val = SDL_SCANCODE_APPLICATION;
            break;
        case (int)SDL_SCANCODE_POWER:
            out_val = SDL_SCANCODE_POWER;
            break;
        case (int)SDL_SCANCODE_KP_EQUALS:
            out_val = SDL_SCANCODE_KP_EQUALS;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_F:
            out_val = SDL_SCANCODE_F;
            break;
        case (int)SDL_SCANCODE_EXECUTE:
            out_val = SDL_SCANCODE_EXECUTE;
            break;
        case (int)SDL_SCANCODE_HELP:
            out_val = SDL_SCANCODE_HELP;
            break;
        case (int)SDL_SCANCODE_MENU:
            out_val = SDL_SCANCODE_MENU;
            break;
        case (int)SDL_SCANCODE_SELECT:
            out_val = SDL_SCANCODE_SELECT;
            break;
        case (int)SDL_SCANCODE_STOP:
            out_val = SDL_SCANCODE_STOP;
            break;
        case (int)SDL_SCANCODE_AGAIN:
            out_val = SDL_SCANCODE_AGAIN;
            break;
        case (int)SDL_SCANCODE_UNDO:
            out_val = SDL_SCANCODE_UNDO;
            break;
        case (int)SDL_SCANCODE_CUT:
            out_val = SDL_SCANCODE_CUT;
            break;
        case (int)SDL_SCANCODE_COPY:
            out_val = SDL_SCANCODE_COPY;
            break;
        case (int)SDL_SCANCODE_PASTE:
            out_val = SDL_SCANCODE_PASTE;
            break;
        case (int)SDL_SCANCODE_FIND:
            out_val = SDL_SCANCODE_FIND;
            break;
        case (int)SDL_SCANCODE_MUTE:
            out_val = SDL_SCANCODE_MUTE;
            break;
        case (int)SDL_SCANCODE_VOLUMEUP:
            out_val = SDL_SCANCODE_VOLUMEUP;
            break;
        case (int)SDL_SCANCODE_VOLUMEDOWN:
            out_val = SDL_SCANCODE_VOLUMEDOWN;
            break;
        case (int)SDL_SCANCODE_KP_COMMA:
            out_val = SDL_SCANCODE_KP_COMMA;
            break;
        case (int)SDL_SCANCODE_KP_EQUALSAS:
            out_val = SDL_SCANCODE_KP_EQUALSAS;
            break;
        case (int)SDL_SCANCODE_INTERNATIONAL:
            out_val = SDL_SCANCODE_INTERNATIONAL;
            break;
        case (int)SDL_SCANCODE_INTERNATIONAL:
            out_val = SDL_SCANCODE_INTERNATIONAL;
            break;
        case (int)SDL_SCANCODE_INTERNATIONAL:
            out_val = SDL_SCANCODE_INTERNATIONAL;
            break;
        case (int)SDL_SCANCODE_INTERNATIONAL:
            out_val = SDL_SCANCODE_INTERNATIONAL;
            break;
        case (int)SDL_SCANCODE_INTERNATIONAL:
            out_val = SDL_SCANCODE_INTERNATIONAL;
            break;
        case (int)SDL_SCANCODE_INTERNATIONAL:
            out_val = SDL_SCANCODE_INTERNATIONAL;
            break;
        case (int)SDL_SCANCODE_INTERNATIONAL:
            out_val = SDL_SCANCODE_INTERNATIONAL;
            break;
        case (int)SDL_SCANCODE_INTERNATIONAL:
            out_val = SDL_SCANCODE_INTERNATIONAL;
            break;
        case (int)SDL_SCANCODE_INTERNATIONAL:
            out_val = SDL_SCANCODE_INTERNATIONAL;
            break;
        case (int)SDL_SCANCODE_LANG:
            out_val = SDL_SCANCODE_LANG;
            break;
        case (int)SDL_SCANCODE_LANG:
            out_val = SDL_SCANCODE_LANG;
            break;
        case (int)SDL_SCANCODE_LANG:
            out_val = SDL_SCANCODE_LANG;
            break;
        case (int)SDL_SCANCODE_LANG:
            out_val = SDL_SCANCODE_LANG;
            break;
        case (int)SDL_SCANCODE_LANG:
            out_val = SDL_SCANCODE_LANG;
            break;
        case (int)SDL_SCANCODE_LANG:
            out_val = SDL_SCANCODE_LANG;
            break;
        case (int)SDL_SCANCODE_LANG:
            out_val = SDL_SCANCODE_LANG;
            break;
        case (int)SDL_SCANCODE_LANG:
            out_val = SDL_SCANCODE_LANG;
            break;
        case (int)SDL_SCANCODE_LANG:
            out_val = SDL_SCANCODE_LANG;
            break;
        case (int)SDL_SCANCODE_ALTERASE:
            out_val = SDL_SCANCODE_ALTERASE;
            break;
        case (int)SDL_SCANCODE_SYSREQ:
            out_val = SDL_SCANCODE_SYSREQ;
            break;
        case (int)SDL_SCANCODE_CANCEL:
            out_val = SDL_SCANCODE_CANCEL;
            break;
        case (int)SDL_SCANCODE_CLEAR:
            out_val = SDL_SCANCODE_CLEAR;
            break;
        case (int)SDL_SCANCODE_PRIOR:
            out_val = SDL_SCANCODE_PRIOR;
            break;
        case (int)SDL_SCANCODE_RETURN:
            out_val = SDL_SCANCODE_RETURN;
            break;
        case (int)SDL_SCANCODE_SEPARATOR:
            out_val = SDL_SCANCODE_SEPARATOR;
            break;
        case (int)SDL_SCANCODE_OUT:
            out_val = SDL_SCANCODE_OUT;
            break;
        case (int)SDL_SCANCODE_OPER:
            out_val = SDL_SCANCODE_OPER;
            break;
        case (int)SDL_SCANCODE_CLEARAGAIN:
            out_val = SDL_SCANCODE_CLEARAGAIN;
            break;
        case (int)SDL_SCANCODE_CRSEL:
            out_val = SDL_SCANCODE_CRSEL;
            break;
        case (int)SDL_SCANCODE_EXSEL:
            out_val = SDL_SCANCODE_EXSEL;
            break;
        case (int)SDL_SCANCODE_KP_:
            out_val = SDL_SCANCODE_KP_;
            break;
        case (int)SDL_SCANCODE_KP_:
            out_val = SDL_SCANCODE_KP_;
            break;
        case (int)SDL_SCANCODE_THOUSANDSSEPARATOR:
            out_val = SDL_SCANCODE_THOUSANDSSEPARATOR;
            break;
        case (int)SDL_SCANCODE_DECIMALSEPARATOR:
            out_val = SDL_SCANCODE_DECIMALSEPARATOR;
            break;
        case (int)SDL_SCANCODE_CURRENCYUNIT:
            out_val = SDL_SCANCODE_CURRENCYUNIT;
            break;
        case (int)SDL_SCANCODE_CURRENCYSUBUNIT:
            out_val = SDL_SCANCODE_CURRENCYSUBUNIT;
            break;
        case (int)SDL_SCANCODE_KP_LEFTPAREN:
            out_val = SDL_SCANCODE_KP_LEFTPAREN;
            break;
        case (int)SDL_SCANCODE_KP_RIGHTPAREN:
            out_val = SDL_SCANCODE_KP_RIGHTPAREN;
            break;
        case (int)SDL_SCANCODE_KP_LEFTBRACE:
            out_val = SDL_SCANCODE_KP_LEFTBRACE;
            break;
        case (int)SDL_SCANCODE_KP_RIGHTBRACE:
            out_val = SDL_SCANCODE_KP_RIGHTBRACE;
            break;
        case (int)SDL_SCANCODE_KP_TAB:
            out_val = SDL_SCANCODE_KP_TAB;
            break;
        case (int)SDL_SCANCODE_KP_BACKSPACE:
            out_val = SDL_SCANCODE_KP_BACKSPACE;
            break;
        case (int)SDL_SCANCODE_KP_A:
            out_val = SDL_SCANCODE_KP_A;
            break;
        case (int)SDL_SCANCODE_KP_B:
            out_val = SDL_SCANCODE_KP_B;
            break;
        case (int)SDL_SCANCODE_KP_C:
            out_val = SDL_SCANCODE_KP_C;
            break;
        case (int)SDL_SCANCODE_KP_D:
            out_val = SDL_SCANCODE_KP_D;
            break;
        case (int)SDL_SCANCODE_KP_E:
            out_val = SDL_SCANCODE_KP_E;
            break;
        case (int)SDL_SCANCODE_KP_F:
            out_val = SDL_SCANCODE_KP_F;
            break;
        case (int)SDL_SCANCODE_KP_XOR:
            out_val = SDL_SCANCODE_KP_XOR;
            break;
        case (int)SDL_SCANCODE_KP_POWER:
            out_val = SDL_SCANCODE_KP_POWER;
            break;
        case (int)SDL_SCANCODE_KP_PERCENT:
            out_val = SDL_SCANCODE_KP_PERCENT;
            break;
        case (int)SDL_SCANCODE_KP_LESS:
            out_val = SDL_SCANCODE_KP_LESS;
            break;
        case (int)SDL_SCANCODE_KP_GREATER:
            out_val = SDL_SCANCODE_KP_GREATER;
            break;
        case (int)SDL_SCANCODE_KP_AMPERSAND:
            out_val = SDL_SCANCODE_KP_AMPERSAND;
            break;
        case (int)SDL_SCANCODE_KP_DBLAMPERSAND:
            out_val = SDL_SCANCODE_KP_DBLAMPERSAND;
            break;
        case (int)SDL_SCANCODE_KP_VERTICALBAR:
            out_val = SDL_SCANCODE_KP_VERTICALBAR;
            break;
        case (int)SDL_SCANCODE_KP_DBLVERTICALBAR:
            out_val = SDL_SCANCODE_KP_DBLVERTICALBAR;
            break;
        case (int)SDL_SCANCODE_KP_COLON:
            out_val = SDL_SCANCODE_KP_COLON;
            break;
        case (int)SDL_SCANCODE_KP_HASH:
            out_val = SDL_SCANCODE_KP_HASH;
            break;
        case (int)SDL_SCANCODE_KP_SPACE:
            out_val = SDL_SCANCODE_KP_SPACE;
            break;
        case (int)SDL_SCANCODE_KP_AT:
            out_val = SDL_SCANCODE_KP_AT;
            break;
        case (int)SDL_SCANCODE_KP_EXCLAM:
            out_val = SDL_SCANCODE_KP_EXCLAM;
            break;
        case (int)SDL_SCANCODE_KP_MEMSTORE:
            out_val = SDL_SCANCODE_KP_MEMSTORE;
            break;
        case (int)SDL_SCANCODE_KP_MEMRECALL:
            out_val = SDL_SCANCODE_KP_MEMRECALL;
            break;
        case (int)SDL_SCANCODE_KP_MEMCLEAR:
            out_val = SDL_SCANCODE_KP_MEMCLEAR;
            break;
        case (int)SDL_SCANCODE_KP_MEMADD:
            out_val = SDL_SCANCODE_KP_MEMADD;
            break;
        case (int)SDL_SCANCODE_KP_MEMSUBTRACT:
            out_val = SDL_SCANCODE_KP_MEMSUBTRACT;
            break;
        case (int)SDL_SCANCODE_KP_MEMMULTIPLY:
            out_val = SDL_SCANCODE_KP_MEMMULTIPLY;
            break;
        case (int)SDL_SCANCODE_KP_MEMDIVIDE:
            out_val = SDL_SCANCODE_KP_MEMDIVIDE;
            break;
        case (int)SDL_SCANCODE_KP_PLUSMINUS:
            out_val = SDL_SCANCODE_KP_PLUSMINUS;
            break;
        case (int)SDL_SCANCODE_KP_CLEAR:
            out_val = SDL_SCANCODE_KP_CLEAR;
            break;
        case (int)SDL_SCANCODE_KP_CLEARENTRY:
            out_val = SDL_SCANCODE_KP_CLEARENTRY;
            break;
        case (int)SDL_SCANCODE_KP_BINARY:
            out_val = SDL_SCANCODE_KP_BINARY;
            break;
        case (int)SDL_SCANCODE_KP_OCTAL:
            out_val = SDL_SCANCODE_KP_OCTAL;
            break;
        case (int)SDL_SCANCODE_KP_DECIMAL:
            out_val = SDL_SCANCODE_KP_DECIMAL;
            break;
        case (int)SDL_SCANCODE_KP_HEXADECIMAL:
            out_val = SDL_SCANCODE_KP_HEXADECIMAL;
            break;
        case (int)SDL_SCANCODE_LCTRL:
            out_val = SDL_SCANCODE_LCTRL;
            break;
        case (int)SDL_SCANCODE_LSHIFT:
            out_val = SDL_SCANCODE_LSHIFT;
            break;
        case (int)SDL_SCANCODE_LALT:
            out_val = SDL_SCANCODE_LALT;
            break;
        case (int)SDL_SCANCODE_LGUI:
            out_val = SDL_SCANCODE_LGUI;
            break;
        case (int)SDL_SCANCODE_RCTRL:
            out_val = SDL_SCANCODE_RCTRL;
            break;
        case (int)SDL_SCANCODE_RSHIFT:
            out_val = SDL_SCANCODE_RSHIFT;
            break;
        case (int)SDL_SCANCODE_RALT:
            out_val = SDL_SCANCODE_RALT;
            break;
        case (int)SDL_SCANCODE_RGUI:
            out_val = SDL_SCANCODE_RGUI;
            break;
        case (int)SDL_SCANCODE_MODE:
            out_val = SDL_SCANCODE_MODE;
            break;
        case (int)SDL_SCANCODE_AUDIONEXT:
            out_val = SDL_SCANCODE_AUDIONEXT;
            break;
        case (int)SDL_SCANCODE_AUDIOPREV:
            out_val = SDL_SCANCODE_AUDIOPREV;
            break;
        case (int)SDL_SCANCODE_AUDIOSTOP:
            out_val = SDL_SCANCODE_AUDIOSTOP;
            break;
        case (int)SDL_SCANCODE_AUDIOPLAY:
            out_val = SDL_SCANCODE_AUDIOPLAY;
            break;
        case (int)SDL_SCANCODE_AUDIOMUTE:
            out_val = SDL_SCANCODE_AUDIOMUTE;
            break;
        case (int)SDL_SCANCODE_MEDIASELECT:
            out_val = SDL_SCANCODE_MEDIASELECT;
            break;
        case (int)SDL_SCANCODE_WWW:
            out_val = SDL_SCANCODE_WWW;
            break;
        case (int)SDL_SCANCODE_MAIL:
            out_val = SDL_SCANCODE_MAIL;
            break;
        case (int)SDL_SCANCODE_CALCULATOR:
            out_val = SDL_SCANCODE_CALCULATOR;
            break;
        case (int)SDL_SCANCODE_COMPUTER:
            out_val = SDL_SCANCODE_COMPUTER;
            break;
        case (int)SDL_SCANCODE_AC_SEARCH:
            out_val = SDL_SCANCODE_AC_SEARCH;
            break;
        case (int)SDL_SCANCODE_AC_HOME:
            out_val = SDL_SCANCODE_AC_HOME;
            break;
        case (int)SDL_SCANCODE_AC_BACK:
            out_val = SDL_SCANCODE_AC_BACK;
            break;
        case (int)SDL_SCANCODE_AC_FORWARD:
            out_val = SDL_SCANCODE_AC_FORWARD;
            break;
        case (int)SDL_SCANCODE_AC_STOP:
            out_val = SDL_SCANCODE_AC_STOP;
            break;
        case (int)SDL_SCANCODE_AC_REFRESH:
            out_val = SDL_SCANCODE_AC_REFRESH;
            break;
        case (int)SDL_SCANCODE_AC_BOOKMARKS:
            out_val = SDL_SCANCODE_AC_BOOKMARKS;
            break;
        case (int)SDL_SCANCODE_BRIGHTNESSDOWN:
            out_val = SDL_SCANCODE_BRIGHTNESSDOWN;
            break;
        case (int)SDL_SCANCODE_BRIGHTNESSUP:
            out_val = SDL_SCANCODE_BRIGHTNESSUP;
            break;
        case (int)SDL_SCANCODE_DISPLAYSWITCH:
            out_val = SDL_SCANCODE_DISPLAYSWITCH;
            break;
        case (int)SDL_SCANCODE_KBDILLUMTOGGLE:
            out_val = SDL_SCANCODE_KBDILLUMTOGGLE;
            break;
        case (int)SDL_SCANCODE_KBDILLUMDOWN:
            out_val = SDL_SCANCODE_KBDILLUMDOWN;
            break;
        case (int)SDL_SCANCODE_KBDILLUMUP:
            out_val = SDL_SCANCODE_KBDILLUMUP;
            break;
        case (int)SDL_SCANCODE_EJECT:
            out_val = SDL_SCANCODE_EJECT;
            break;
        case (int)SDL_SCANCODE_SLEEP:
            out_val = SDL_SCANCODE_SLEEP;
            break;
        case (int)SDL_SCANCODE_APP:
            out_val = SDL_SCANCODE_APP;
            break;
        case (int)SDL_SCANCODE_APP:
            out_val = SDL_SCANCODE_APP;
            break;
        case (int)SDL_NUM_SCANCODES:
            out_val = SDL_NUM_SCANCODES;
            break;
        default: {
            std::ostringstream oss;
            oss << "ef unknown match in integral:" << val;
            throw std::runtime_error(oss.str());
        }
    }
}

std::ostream& operator<<(std::ostream& os, ef const& val) {
    return os << to_string(val);
}

std::istream& operator>>(std::istream& is, ef& val) {
    std::string str;
    is >> str;
    from_string(str, val);
    return is;
}

}  // namespace scancode_helper

#endif

