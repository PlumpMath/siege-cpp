#include "keyboard.hh"

using namespace siege::c;
namespace siege
{
    namespace input
    {
        namespace keyboard
        {
            bool key(SGenum key)
            {
                return sgKeyboardKey(key);
            }
            bool keyPress(SGenum key)
            {
                return sgKeyboardKeyPress(key);
            }
            bool keyRelease(SGenum key)
            {
                return sgKeyboardKeyRelease(key);
            }
            bool chr(SGdchar chr)
            {
                return sgKeyboardChar(chr);
            }
            bool chrPress(SGdchar chr)
            {
                return sgKeyboardCharPress(chr);
            }
            bool chrRelease(SGdchar chr)
            {
                return sgKeyboardCharRelease(chr);
            }
        }
    }
}
