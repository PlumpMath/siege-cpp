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

#include "window.hh"

using namespace siege::c;

namespace siege
{
    namespace core
    {
        namespace window
        {
            bool open(SGuint width, SGuint height, SGuint bpp, SGenum flags)
            {
                return sgWindowOpen(width, height, bpp, flags);
            }
            bool isOpened()
            {
                return sgWindowIsOpened();
            }
            void close()
            {
                sgWindowClose();
            }

            void setTitleF(char* format, ...)
            {
                va_list args;
                va_start(args, format);
                sgWindowSetTitleFV(format, args);
                va_end(args);
            }
            void setTitleFV(char* format, va_list args)
            {
                sgWindowSetTitleFV(format, args);
            }
            void setTitle(char* title)
            {
                sgWindowSetTitle(title);
            }
            char* getTitle()
            {
                return sgWindowGetTitle();
            }

            void setSize(SGuint width, SGuint height)
            {
                sgWindowSetSize(width, height);
            }
            void getSize(SGuint* width, SGuint* height)
            {
                sgWindowGetSize(width, height);
            }

            void setWidth(SGuint width)
            {
                sgWindowSetWidth(width);
            }
            SGuint getWidth()
            {
                return sgWindowGetWidth();
            }
            void setHeight(SGuint height)
            {
                sgWindowSetHeight(height);
            }
            SGuint getHeight()
            {
                return sgWindowGetHeight();
            }

            void swapBuffers()
            {
                sgWindowSwapBuffers();
            }
        }
    }
}
