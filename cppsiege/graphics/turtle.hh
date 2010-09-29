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

#ifndef __CPP_SIEGE_GRAPHICS_TURTLE_H__
#define __CPP_SIEGE_GRAPHICS_TURTLE_H__

#include "../common.hh"

namespace siege
{
    namespace graphics
    {
        /// \todo overload
        class Turtle
        {
        private:
            siege::c::SGTurtle* handle;
            void create(float x, float y, float angle, bool draw);

        public:
            Turtle(float x, float y, float angle, bool draw);
            Turtle(float x, float y, float angle);
            Turtle(float x, float y, bool draw);
            Turtle(float x, float y);
            ~Turtle();

            void reset();
            void push();
            void pop();
            void step(float dist);
            void move(float x, float y);
            void jump(float x, float y);
            void penUp();
            void penDown();

            void setPen(bool pen);
            bool getPen();

            // alias of jump
            void setPos(float x, float y);
            void setPosX(float x);
            void setPosY(float y);
            void getPos(float* x, float* y);
            float getPosX();
            float getPosY();

            void turnLeftRads(float rads);
            void turnLeftDegs(float degs);
            void turnRightRads(float rads);
            void turnRightDegs(float degs);

            void setAngleRads(float rads);
            float getAngleRads();

            void setAngleDegs(float degs);
            float getAngleDegs();
        } ;
    }
}

#endif // __CPP_SIEGE_GRAPHICS_TURTLE_H__
