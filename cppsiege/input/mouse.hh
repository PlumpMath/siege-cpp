#ifndef __CPP_SIEGE_INPUT_MOUSE_H__
#define __CPP_SIEGE_INPUT_MOUSE_H__

#include "../common.hh"

namespace siege
{
    namespace input
    {
        namespace mouse
        {
            void getPosPrev(siege::c::SGint* x, siege::c::SGint* y);
            siege::c::SGint getPosPrevX();
            siege::c::SGint getPosPrevY();

            void getPos(siege::c::SGint* x, siege::c::SGint* y);
            siege::c::SGint getPosX();
            siege::c::SGint getPosY();

            siege::c::SGint getWheelPrev();
            siege::c::SGint getWheel();

            bool getButtonPrev(siege::c::SGuint button);
            bool getButton(siege::c::SGuint button);
            bool getButtonPress(siege::c::SGuint button);
            bool getButtonRelease(siege::c::SGuint button);

            bool getButtonLeftPrev();
            bool getButtonLeft();
            bool getButtonLeftPress();
            bool getButtonLeftRelease();

            bool getButtonRightPrev();
            bool getButtonRight();
            bool getButtonRightPress();
            bool getButtonRightRelease();

            bool getButtonMiddlePrev();
            bool getButtonMiddle();
            bool getButtonMiddlePress();
            bool getButtonMiddleRelease();
        }
    }
}

#endif // __CPP_SIEGE_INPUT_MOUSE_H__
