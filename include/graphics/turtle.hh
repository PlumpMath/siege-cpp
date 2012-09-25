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

#ifndef __CPP_SIEGE_GRAPHICS_TURTLE_H__
#define __CPP_SIEGE_GRAPHICS_TURTLE_H__

#include "../common.hh"

namespace siege
{
    namespace graphics
    {
        class Turtle: public SGClass<c::SGTurtle>
        {
        private:
            void create(float x, float y, float angle, bool draw) { handle = c::sgTurtleCreateDegs(x, y, angle, draw); }

        public:
            /// \todo overload
            Turtle(float x, float y, float angle, bool draw = true) { create(x, y, angle, draw); }
            Turtle(float x, float y, bool draw = true) { create(x, y, 0.0, draw); }
            ~Turtle() { c::sgTurtleDestroy(handle); }

            void reset() { c::sgTurtleReset(handle); }
            void push() { c::sgTurtlePush(handle); }
            void pop() { c::sgTurtlePop(handle); }
            void step(float dist) { c::sgTurtleStep(handle, dist); }
            void move(float x, float y) { c::sgTurtleMove(handle, x, y); }
            void jump(float x, float y) { c::sgTurtleJump(handle, x, y); }
            void penUp() { c::sgTurtlePenUp(handle); }
            void penDown() { c::sgTurtlePenDown(handle); }

            void setPen(bool pen) { c::sgTurtleSetPen(handle, pen); }
            bool getPen() { return c::sgTurtleGetPen(handle); }

            // alias of jump
            void setPos(float x, float y) { c::sgTurtleSetPos(handle, x, y); }
            void setPosX(float x) { c::sgTurtleSetPosX(handle, x); }
            void setPosY(float y) { c::sgTurtleSetPosY(handle, y); }
            void getPos(float* x, float* y) { c::sgTurtleGetPos(handle, x, y); }
            void getPos(float& x, float& y) { c::sgTurtleGetPos(handle, &x, &y); }
            float getPosX() { return c::sgTurtleGetPosX(handle); }
            float getPosY() { return c::sgTurtleGetPosY(handle); }

            void turnLeftRads(float rads) { c::sgTurtleTurnLeftRads(handle, rads); }
            void turnLeftDegs(float degs) { c::sgTurtleTurnLeftDegs(handle, degs); }
            void turnRightRads(float rads) { c::sgTurtleTurnRightRads(handle, rads); }
            void turnRightDegs(float degs) { c::sgTurtleTurnRightDegs(handle, degs); }

            void setAngleRads(float rads) { c::sgTurtleSetAngleRads(handle, rads); }
            float getAngleRads() { return c::sgTurtleGetAngleRads(handle); }

            void setAngleDegs(float degs) { c::sgTurtleSetAngleDegs(handle, degs); }
            float getAngleDegs() { return c::sgTurtleGetAngleDegs(handle); }
        } ;
        RTYPE(Turtle);
    }
}

#endif // __CPP_SIEGE_GRAPHICS_TURTLE_H__
