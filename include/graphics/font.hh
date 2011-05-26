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

                void printf(float x, float y, const char* format, ...);
                void printfv(float x, float y, const char* format, va_list args);
                void printfW(float x, float y, const wchar_t* format, ...);
                void printfvW(float x, float y, const wchar_t* format, va_list args);

                void printU32(float x, float y, const siege::c::SGdchar* text);
                void printU16(float x, float y, const siege::c::SGwchar* text);
                void printU8(float x, float y, const siege::c::SGchar* text);
                void printW(float x, float y, const wchar_t* text);
                void print(float x, float y, const char* text);

                void printCenteredf(float x, float y, const char* format, ...);
                void printCenteredfv(float x, float y, const char* format, va_list args);
                void printCenteredfW(float x, float y, const wchar_t* format, ...);
                void printCenteredfvW(float x, float y, const wchar_t* format, va_list args);

                void printCenteredU32(float x, float y, const siege::c::SGdchar* text);
                void printCenteredU16(float x, float y, const siege::c::SGwchar* text);
                void printCenteredU8(float x, float y, const siege::c::SGchar* text);
                void printCenteredW(float x, float y, const wchar_t* text);
                void printCentered(float x, float y, const char* text);

                void printXCenteredf(float x, float y, const char* format, ...);
                void printXCenteredfv(float x, float y, const char* format, va_list args);
                void printXCenteredfW(float x, float y, const wchar_t* format, ...);
                void printXCenteredfvW(float x, float y, const wchar_t* format, va_list args);

                void printXCenteredU32(float x, float y, const siege::c::SGdchar* text);
                void printXCenteredU16(float x, float y, const siege::c::SGwchar* text);
                void printXCenteredU8(float x, float y, const siege::c::SGchar* text);
                void printXCenteredW(float x, float y, const wchar_t* text);
                void printXCentered(float x, float y, const char* text);

                void printYCenteredf(float x, float y, const char* format, ...);
                void printYCenteredfv(float x, float y, const char* format, va_list args);
                void printYCenteredfW(float x, float y, const wchar_t* format, ...);
                void printYCenteredfvW(float x, float y, const wchar_t* format, va_list args);

                void printYCenteredU32(float x, float y, const siege::c::SGdchar* text);
                void printYCenteredU16(float x, float y, const siege::c::SGwchar* text);
                void printYCenteredU8(float x, float y, const siege::c::SGchar* text);
                void printYCenteredW(float x, float y, const wchar_t* text);
                void printYCentered(float x, float y, const char* text);

                void strSizef(float* x, float* y, const char* format, ...);
                void strSizef(float& x, float& y, const char* format, ...);
                void strSizefv(float* x, float* y, const char* format, va_list args);
                void strSizefv(float& x, float& y, const char* format, va_list args);
                void strSizefW(float* x, float* y, const wchar_t* format, ...);
                void strSizefW(float& x, float& y, const wchar_t* format, ...);
                void strSizefvW(float* x, float* y, const wchar_t* format, va_list args);
                void strSizefvW(float& x, float& y, const wchar_t* format, va_list args);

				void strSizeU32(float* x, float* y, const siege::c::SGdchar* text);
				void strSizeU32(float& x, float& y, const siege::c::SGdchar* text);
                void strSizeU16(float* x, float* y, const siege::c::SGwchar* text);
                void strSizeU16(float& x, float& y, const siege::c::SGwchar* text);
                void strSizeU8(float* x, float* y, const siege::c::SGchar* text);
                void strSizeU8(float& x, float& y, const siege::c::SGchar* text);
                void strSizeW(float* x, float* y, const wchar_t* text);
                void strSizeW(float& x, float& y, const wchar_t* text);
                void strSize(float* x, float* y, const char* text);
                void strSize(float& x, float& y, const char* text);
        } ;
    }
}

#endif // __CPP_SIEGE_GRAPHICS_FONT_H__
