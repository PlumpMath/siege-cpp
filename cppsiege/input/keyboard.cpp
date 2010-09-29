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
