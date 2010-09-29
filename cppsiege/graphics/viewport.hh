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

#ifndef __CPP_SIEGE_GRAPHICS_VIEWPORT_H__
#define __CPP_SIEGE_GRAPHICS_VIEWPORT_H__

#include "../common.hh"

namespace siege
{
    namespace graphics
    {
        /// \todo overload
        class Viewport
        {
        private:
            siege::c::SGViewport* handle;
            void create(siege::c::SGuint wposx, siege::c::SGuint wposy, siege::c::SGuint wsizex, siege::c::SGuint wsizey, float posx, float posy, float sizex, float sizey);
            void create(siege::c::SGuint wposx, siege::c::SGuint wposy, siege::c::SGuint wsizex, siege::c::SGuint wsizey);
            void create();

        public:
            Viewport(siege::c::SGuint wposx, siege::c::SGuint wposy, siege::c::SGuint wsizex, siege::c::SGuint wsizey, float posx, float posy, float sizex, float sizey);
            Viewport(siege::c::SGuint wposx, siege::c::SGuint wposy, siege::c::SGuint wsizex, siege::c::SGuint wsizey);
            Viewport();
            ~Viewport();

            void set(siege::c::SGuint wposx, siege::c::SGuint wposy, siege::c::SGuint wsizex, siege::c::SGuint wsizey, float posx, float posy, float sizex, float sizey);
            void set(siege::c::SGuint wposx, siege::c::SGuint wposy, siege::c::SGuint wsizex, siege::c::SGuint wsizey);
            void reset();
        } ;
    }
}

#endif // __CPP_SIEGE_GRAPHICS_VIEWPORT_H__
