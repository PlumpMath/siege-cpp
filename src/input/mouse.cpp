/*
 * Copyright (c) 2007 SIEGE Development Team
 * All rights reserved.
 *
 * This file is part of libSIEGE.
 *
 * This software is copyrighted work licensed under the terms of the
 * 2-clause BSD license. Please consult the file "license.txt" for
 * details.
 *
 * If you did not recieve the file with this program, please email
 * Tim Chas <darkuranium@gmail.com>.
 */

#include <input/mouse.hh>

using namespace siege::c;

namespace siege
{
	namespace input
	{
		namespace mouse
		{
			void getPosPrev(SGint* x, SGint* y)
			{
				sgMouseGetPosPrev(x, y);
			}
			void getPosPrev(SGint& x, SGint& y)
			{
				sgMouseGetPosPrev(&x, &y);
			}
			SGint getPosPrevX()
			{
				return sgMouseGetPosPrevX();
			}
			SGint getPosPrevY()
			{
				return sgMouseGetPosPrevY();
			}

			void getPos(SGint* x, SGint* y)
			{
				sgMouseGetPos(x, y);
			}
			void getPos(SGint& x, SGint& y)
			{
				sgMouseGetPos(&x, &y);
			}
			SGint getPosX()
			{
				return sgMouseGetPosX();
			}
			SGint getPosY()
			{
				return sgMouseGetPosY();
			}

			SGint getWheelPrev()
			{
				return sgMouseGetWheelPrev();
			}
			SGint getWheel()
			{
				return sgMouseGetWheel();
			}

			bool getButtonPrev(SGuint button)
			{
				return sgMouseGetButtonPrev(button);
			}
			bool getButton(SGuint button)
			{
				return sgMouseGetButton(button);
			}
			bool getButtonPress(SGuint button)
			{
				return sgMouseGetButtonPress(button);
			}
			bool getButtonRelease(SGuint button)
			{
				return sgMouseGetButtonRelease(button);
			}

			bool getButtonLeftPrev()
			{
				return sgMouseGetButtonLeftPrev();
			}
			bool getButtonLeft()
			{
				return sgMouseGetButtonLeft();
			}
			bool getButtonLeftPress()
			{
				return sgMouseGetButtonLeftPress();
			}
			bool getButtonLeftRelease()
			{
				return sgMouseGetButtonLeftRelease();
			}

			bool getButtonRightPrev()
			{
				return sgMouseGetButtonRightPrev();
			}
			bool getButtonRight()
			{
				return sgMouseGetButtonRight();
			}
			bool getButtonRightPress()
			{
				return sgMouseGetButtonRightPress();
			}
			bool getButtonRightRelease()
			{
				return sgMouseGetButtonRightRelease();
			}

			bool getButtonMiddlePrev()
			{
				return sgMouseGetButtonMiddlePrev();
			}
			bool getButtonMiddle()
			{
				return sgMouseGetButtonMiddle();
			}
			bool getButtonMiddlePress()
			{
				return sgMouseGetButtonMiddlePress();
			}
			bool getButtonMiddleRelease()
			{
				return sgMouseGetButtonMiddleRelease();
			}
		}
	}
}
