#ifndef __CPP_SIEGE_INPUT_KEYBOARD_H__
#define __CPP_SIEGE_INPUT_KEYBOARD_H__

#include "../common.hh"

namespace siege
{
    namespace input
    {
        namespace keyboard
        {
            bool key(siege::c::SGenum key);
            bool keyPress(siege::c::SGenum key);
            bool keyRelease(siege::c::SGenum key);
            bool chr(siege::c::SGdchar chr);
            bool chrPress(siege::c::SGdchar chr);
            bool chrRelease(siege::c::SGdchar chr);
        }
    }
}

#endif // __CPP_SIEGE_INPUT_KEYBOARD_H__
