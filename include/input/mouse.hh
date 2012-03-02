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

#ifndef __CPP_SIEGE_INPUT_MOUSE_H__
#define __CPP_SIEGE_INPUT_MOUSE_H__

#include "../common.hh"

namespace siege
{
    namespace input
    {
        namespace mouse
        {
            inline void getPosPrev(c::SGint* x, c::SGint* y) { c::sgMouseGetPosPrev(x, y); }
            inline void getPosPrev(c::SGint& x, c::SGint& y) { c::sgMouseGetPosPrev(&x, &y); }
            inline c::SGint getPosPrevX() { return c::sgMouseGetPosPrevX(); }
            inline c::SGint getPosPrevY() { return c::sgMouseGetPosPrevY(); }

            inline void getPos(c::SGint* x, c::SGint* y) { c::sgMouseGetPos(x, y); }
            inline void getPos(c::SGint& x, c::SGint& y) { c::sgMouseGetPos(&x, &y); }
            inline c::SGint getPosX() { return c::sgMouseGetPosX(); }
            inline c::SGint getPosY() { return c::sgMouseGetPosY(); }

            inline c::SGint getWheelPrev() { return c::sgMouseGetWheelPrev(); }
            inline c::SGint getWheel() { return c::sgMouseGetWheel(); }

            inline bool getButtonPrev(c::SGuint button) { return c::sgMouseGetButtonPrev(button); }
            inline bool getButton(c::SGuint button) { return c::sgMouseGetButton(button); }
            inline bool getButtonPress(c::SGuint button) { return c::sgMouseGetButtonPress(button); }
            inline bool getButtonRelease(c::SGuint button) { return c::sgMouseGetButtonRelease(button); }

            inline bool getButtonLeftPrev() { return c::sgMouseGetButtonLeftPrev(); }
            inline bool getButtonLeft() { return c::sgMouseGetButtonLeft(); }
            inline bool getButtonLeftPress() { return c::sgMouseGetButtonLeftPress(); }
            inline bool getButtonLeftRelease() { return c::sgMouseGetButtonLeftRelease(); }

            inline bool getButtonRightPrev() { return c::sgMouseGetButtonRightPrev(); }
            inline bool getButtonRight() { return c::sgMouseGetButtonRight(); }
            inline bool getButtonRightPress() { return c::sgMouseGetButtonRightPress(); }
            inline bool getButtonRightRelease() { return c::sgMouseGetButtonRightRelease(); }

            inline bool getButtonMiddlePrev() { return c::sgMouseGetButtonMiddlePrev(); }
            inline bool getButtonMiddle() { return c::sgMouseGetButtonMiddle(); }
            inline bool getButtonMiddlePress() { return c::sgMouseGetButtonMiddlePress(); }
            inline bool getButtonMiddleRelease() { return c::sgMouseGetButtonMiddleRelease(); }
        }
    }
}

#endif // __CPP_SIEGE_INPUT_MOUSE_H__
