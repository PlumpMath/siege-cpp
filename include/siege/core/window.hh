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

#ifndef __CPP_SIEGE_CORE_WINDOW_H__
#define __CPP_SIEGE_CORE_WINDOW_H__

#include "../common.hh"

namespace siege
{
    namespace core
    {
        namespace window
        {
            inline bool open(c::SGuint width, c::SGuint height, c::SGuint bpp, c::SGenum flags = 0) { return c::sgWindowOpen(width, height, bpp, flags); }
            inline bool isOpened() { return c::sgWindowIsOpened(); }
            inline void close() { c::sgWindowClose(); }

            inline void setTitlef(const char* format, ...)
            {
                std::va_list args;
                va_start(args, format);
                c::sgWindowSetTitlefv(format, args);
                va_end(args);
            }
            inline void setTitlefv(const char* format, std::va_list args) { c::sgWindowSetTitlefv(format, args); }
            inline void setTitle(const char* title) { c::sgWindowSetTitle(title); }
            inline char* getTitle() { return c::sgWindowGetTitle(); }

            inline void setSize(c::SGuint width, c::SGuint height) { c::sgWindowSetSize(width, height); }
            inline void getSize(c::SGuint* width, c::SGuint* height) { c::sgWindowGetSize(width, height); }
            inline void getSize(c::SGuint& width, c::SGuint& height) { c::sgWindowGetSize(&width, &height); }

            inline void setWidth(c::SGuint width) { c::sgWindowSetWidth(width); }
            inline c::SGuint getWidth() { return c::sgWindowGetWidth(); }
            inline void setHeight(c::SGuint height) { c::sgWindowSetHeight(height); }
            inline c::SGuint getHeight() { return c::sgWindowGetHeight(); }

            inline void swapBuffers() { c::sgWindowSwapBuffers();}
        }
    }
}


#endif // __CPP_SIEGE_CORE_WINDOW_H__
