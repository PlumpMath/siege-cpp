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

#include <graphics/font.hh>

using namespace siege::c;

namespace siege
{
    namespace graphics
    {
        void Font::create(const char* fname, float height, SGuint preload)
        {
            handle = sgFontCreate(fname, height, preload);
        }
        Font::Font(siege::c::SGFont* hdl)
        {
            handle = hdl;
        }

        Font::Font(const char* fname, float height, SGuint preload)
        {
            create(fname, height, preload);
        }
        Font::~Font()
        {
            sgFontDestroy(handle);
        }

        Font* Font::resizeCopy(float height)
        {
            return new Font(sgFontResizeCopy(handle, height));
        }
        Font* Font::resize(float height)
        {
            SGFont* newh = sgFontResize(handle, height);
            if(newh == handle)
                return this;
            return new Font(newh);
        }

        void Font::print(float x, float y, const char* format, ...)
        {
            va_list args;
            va_start(args, format);
            sgFontPrintV(handle, x, y, format, args);
            va_end(args);
        }
        void Font::printV(float x, float y, const char* format, va_list args)
        {
            sgFontPrintV(handle, x, y, format, args);
        }
        void Font::printT(float x, float y, const char* text)
        {
            sgFontPrintT(handle, x, y, text);
        }

        void Font::printCentered(float x, float y, const char* format, ...)
        {
            va_list args;
            va_start(args, format);
            sgFontPrintCenteredV(handle, x, y, format, args);
            va_end(args);
        }
        void Font::printCenteredV(float x, float y, const char* format, va_list args)
        {
            sgFontPrintCenteredV(handle, x, y, format, args);
        }
        void Font::printCenteredT(float x, float y, const char* text)
        {
            sgFontPrintCenteredT(handle, x, y, text);
        }

        void Font::printXCentered(float x, float y, const char* format, ...)
        {
            va_list args;
            va_start(args, format);
            sgFontPrintXCenteredV(handle, x, y, format, args);
            va_end(args);
        }
        void Font::printXCenteredV(float x, float y, const char* format, va_list args)
        {
            sgFontPrintXCenteredV(handle, x, y, format, args);
        }
        void Font::printXCenteredT(float x, float y, const char* text)
        {
            sgFontPrintXCenteredT(handle, x, y, text);
        }

        void Font::printYCentered(float x, float y, const char* format, ...)
        {
            va_list args;
            va_start(args, format);
            sgFontPrintYCenteredV(handle, x, y, format, args);
            va_end(args);
        }
        void Font::printYCenteredV(float x, float y, const char* format, va_list args)
        {
            sgFontPrintYCenteredV(handle, x, y, format, args);
        }
        void Font::printYCenteredT(float x, float y, const char* text)
        {
            sgFontPrintYCenteredT(handle, x, y, text);
        }

        void Font::strSize(float* x, float* y, const char* format, ...)
        {
            va_list args;
            va_start(args, format);
            sgFontStrSizeV(handle, x, y, format, args);
            va_end(args);
        }
        void Font::strSize(float& x, float& y, const char* format, ...)
        {
            va_list args;
            va_start(args, format);
            sgFontStrSizeV(handle, &x, &y, format, args);
            va_end(args);
        }
        void Font::strSizeV(float* x, float* y, const char* format, va_list args)
        {
            sgFontStrSizeV(handle, x, y, format, args);
        }
        void Font::strSizeV(float& x, float& y, const char* format, va_list args)
        {
            sgFontStrSizeV(handle, &x, &y, format, args);
        }
        void Font::strSizeT(float* x, float* y, const char* text)
        {
            sgFontStrSizeT(handle, x, y, text);
        }
        void Font::strSizeT(float& x, float& y, const char* text)
        {
            sgFontStrSizeT(handle, &x, &y, text);
        }
    }
}
