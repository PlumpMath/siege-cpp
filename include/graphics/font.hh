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

#ifndef __CPP_SIEGE_GRAPHICS_FONT_H__
#define __CPP_SIEGE_GRAPHICS_FONT_H__

#include "../common.hh"

namespace siege
{
    namespace graphics
    {
        class Font
        {
            private:
                siege::c::SGFont* handle;
                void create(const char* fname, float height, siege::c::SGuint preload);
                Font(siege::c::SGFont* hdl);

            public:
                Font(const char* fname, float height, siege::c::SGuint preload = 256);
                ~Font();

                Font* resizeCopy(float height);
                Font* resize(float height);

                void print(float x, float y, const char* format, ...);
                void printV(float x, float y, const char* format, va_list args);
                void printT(float x, float y, const char* text);

                void printCentered(float x, float y, const char* format, ...);
                void printCenteredV(float x, float y, const char* format, va_list args);
                void printCenteredT(float x, float y, const char* text);

                void printXCentered(float x, float y, const char* format, ...);
                void printXCenteredV(float x, float y, const char* format, va_list args);
                void printXCenteredT(float x, float y, const char* text);

                void printYCentered(float x, float y, const char* format, ...);
                void printYCenteredV(float x, float y, const char* format, va_list args);
                void printYCenteredT(float x, float y, const char* text);

                void strSize(float* x, float* y, const char* format, ...);
                void strSize(float& x, float& y, const char* format, ...);
                void strSizeV(float* x, float* y, const char* format, va_list args);
                void strSizeV(float& x, float& y, const char* format, va_list args);
                void strSizeT(float* x, float* y, const char* text);
                void strSizeT(float& x, float& y, const char* text);
        } ;
    }
}

#endif // __CPP_SIEGE_GRAPHICS_FONT_H__
