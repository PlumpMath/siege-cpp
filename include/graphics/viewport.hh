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

#ifndef __CPP_SIEGE_GRAPHICS_VIEWPORT_H__
#define __CPP_SIEGE_GRAPHICS_VIEWPORT_H__

#include "../common.hh"

namespace siege
{
    namespace graphics
    {
        class Viewport
        {
        private:
            c::SGViewport* handle;
            void create(c::SGuint wposx, c::SGuint wposy, c::SGuint wsizex, c::SGuint wsizey, float posx, float posy, float sizex, float sizey) { handle = c::sgViewportCreate4i4f(wposx, wposy, wsizex, wsizey, posx, posy, sizex, sizey); }
            void create(c::SGuint wposx, c::SGuint wposy, c::SGuint wsizex, c::SGuint wsizey) { handle = c::sgViewportCreate4i(wposx, wposy, wsizex, wsizey); }
            void create() { handle = c::sgViewportCreate(); }

        public:
            Viewport(c::SGuint wposx, c::SGuint wposy, c::SGuint wsizex, c::SGuint wsizey, float posx, float posy, float sizex, float sizey) { create(wposx, wposy, wsizex, wsizey, posx, posy, sizex, sizey); }
            Viewport(c::SGuint wposx, c::SGuint wposy, c::SGuint wsizex, c::SGuint wsizey) { create(wposx, wposy, wsizex, wsizey); }
            Viewport() { create(); }
            ~Viewport() { c::sgViewportDestroy(handle); }

            void set(c::SGuint wposx, c::SGuint wposy, c::SGuint wsizex, c::SGuint wsizey, float posx, float posy, float sizex, float sizey) { c::sgViewportSet4i4f(handle, wposx, wposy, wsizex, wsizey, posx, posy, sizex, sizey); }
            void set(c::SGuint wposx, c::SGuint wposy, c::SGuint wsizex, c::SGuint wsizey) { c::sgViewportSet4i(handle, wposx, wposy, wsizex, wsizey); }
            void reset() { c::sgViewportReset(handle); }
        } ;
    }
}

#endif // __CPP_SIEGE_GRAPHICS_VIEWPORT_H__
