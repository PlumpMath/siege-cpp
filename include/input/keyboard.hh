/*
 * Copyright (c) 2007 SIEGE Development Team
 * All rights reserved.
 *
 * This file is part of libSIEGE.
 *
 * This software is copyrighted work licensed under the terms of the
 * 2-clause BSD license. Please consult the file "COPYING.txt" for
 * details.
 *
 * If you did not recieve the file with this program, please email
 * Tim Chas <darkuranium@gmail.com>.
 */

#ifndef __CPP_SIEGE_INPUT_KEYBOARD_H__
#define __CPP_SIEGE_INPUT_KEYBOARD_H__

#include "../common.hh"

namespace siege
{
    namespace input
    {
        namespace keyboard
        {
            inline bool key(c::SGenum key) { return c::sgKeyboardKey(key); }
            inline bool keyPress(c::SGenum key) { return c::sgKeyboardKeyPress(key); }
            inline bool keyRelease(c::SGenum key) { return c::sgKeyboardKeyRelease(key); }
        }
    }
}

#endif // __CPP_SIEGE_INPUT_KEYBOARD_H__
