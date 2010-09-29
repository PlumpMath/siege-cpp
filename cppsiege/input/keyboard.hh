/*
    Copyright (c) 2007 SIEGE Development Team
    All rights reserved.

    This file is part of libSIEGE.

    This software is copyrighted work licensed under the terms of the
    2-clause BSD license. Please consult the file "license.txt" for
    details.

    If you did not recieve the file with this program, please email
    Tim Chas <darkuranium@gmail.com>.
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
