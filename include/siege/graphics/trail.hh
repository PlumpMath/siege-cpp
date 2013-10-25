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

#ifndef __CPP_SIEGE_GRAPHICS_TRAIL_H__
#define __CPP_SIEGE_GRAPHICS_TRAIL_H__

#include "../common.hh"

namespace siege
{
    namespace graphics
    {
        class Trail: public SGClass<c::SGTrail>
        {
        private:
            void create(c::SGuint maxpoints) { handle = c::sgTrailCreate(maxpoints); }

        public:
            Trail(c::SGuint maxpoints = 0) { create(maxpoints); }
            ~Trail() { c::sgTrailDestroy(handle); }

            void destroy() { if(handle) c::sgTrailDestroy(handle); handle = NULL; }

            void popPoint() { c::sgTrailPopPoint(handle); }

            //void setGradient();

            void addPoint(float x, float y) { c::sgTrailAddPoint2f(handle, x, y); }
            void addBreak() { c::sgTrailAddBreak(handle); }
            void draw() { c::sgTrailDraw(handle); }
        } ;
        RTYPE(Trail);
    }
}

#endif // __CPP_SIEGE_GRAPHICS_TRAIL_H__
