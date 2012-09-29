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

#ifndef __CPP_SIEGE_GRAPHICS_FONT_H__
#define __CPP_SIEGE_GRAPHICS_FONT_H__

#include "../common.hh"

namespace siege
{
    namespace graphics
    {
        class Font: public SGClass<c::SGFont>
        {
            private:
                void create(const char* fname, float height, c::SGuint bpp, c::SGuint preload) { handle = c::sgFontCreate(fname, height, bpp, preload); }

            public:
                Font(const char* fname, float height, c::SGuint bpp = 0, c::SGuint preload = 127) { create(fname, height, bpp, preload); }
                ~Font() { c::sgFontDestroy(handle); };

                /*Font* resizeCopy(float height) { return new Font(c::sgFontResizeCopy(handle, height)); }
                Font* resize(float height)
                {
                    c::SGFont* newh = c::sgFontResize(handle, height);
                    if(newh == handle)
                        return this;
                    return new Font(newh);
                }*/

                void printfW(float x, float y, const wchar_t* format, ...)
                {
                    std::va_list args;
                    va_start(args, format);
                    c::sgFontPrintfvW(handle, x, y, format, args);
                    va_end(args);
                }
                void printfvW(float x, float y, const wchar_t* format, std::va_list args) { sgFontPrintfvW(handle, x, y, format, args); }
                void printf(float x, float y, const char* format, ...)
                {
                    std::va_list args;
                    va_start(args, format);
                    c::sgFontPrintfv(handle, x, y, format, args);
                    va_end(args);
                }
                void printfv(float x, float y, const char* format, std::va_list args) { sgFontPrintfv(handle, x, y, format, args); }

                void printU32(float x, float y, const c::SGdchar* text) { sgFontPrintU32(handle, x, y, text); }
                void printU16(float x, float y, const c::SGwchar* text) { sgFontPrintU16(handle, x, y, text); }
                void printU8(float x, float y, const c::SGchar* text) { sgFontPrintU8(handle, x, y, text); }
                void printW(float x, float y, const wchar_t* text) { sgFontPrintW(handle, x, y, text); }
                void print(float x, float y, const char* text) { sgFontPrint(handle, x, y, text); }

                void printAlignedfW(float x, float y, c::SGenum align, const wchar_t* format, ...)
                {
                    std::va_list args;
                    va_start(args, format);
                    c::sgFontPrintAlignedfvW(handle, x, y, align, format, args);
                    va_end(args);
                }
                void printAlignedfvW(float x, float y, c::SGenum align, const wchar_t* format, std::va_list args) { c::sgFontPrintAlignedfvW(handle, x, y, align, format, args); }
                void printAlignedf(float x, float y, c::SGenum align, const char* format, ...)
                {
                    std::va_list args;
                    va_start(args, format);
                    c::sgFontPrintAlignedfv(handle, x, y, align, format, args);
                    va_end(args);
                }
                void printAlignedfv(float x, float y, c::SGenum align, const char* format, std::va_list args) { c::sgFontPrintAlignedfv(handle, x, y, align, format, args); }

                void printAlignedU32(float x, float y, c::SGenum align, const c::SGdchar* text) { c::sgFontPrintAlignedU32(handle, x, y, align, text); }
                void printAlignedU16(float x, float y, c::SGenum align, const c::SGwchar* text) { c::sgFontPrintAlignedU16(handle, x, y, align, text); }
                void printAlignedU8(float x, float y, c::SGenum align, const c::SGchar* text) { c::sgFontPrintAlignedU8(handle, x, y, align, text); }
                void printAlignedW(float x, float y, c::SGenum align, const wchar_t* text) { c::sgFontPrintAlignedW(handle, x, y, align, text); }
                void printAligned(float x, float y, c::SGenum align, const char* text) { c::sgFontPrintAligned(handle, x, y, align, text); }

                void strSizefW(float* x, float* y, const wchar_t* format, ...)
                {
                    std::va_list args;
                    va_start(args, format);
                    c::sgFontStrSizefvW(handle, x, y, format, args);
                    va_end(args);
                }
                void strSizefW(float& x, float& y, const wchar_t* format, ...)
                {
                    std::va_list args;
                    va_start(args, format);
                    c::sgFontStrSizefvW(handle, &x, &y, format, args);
                    va_end(args);
                }
                void strSizefvW(float* x, float* y, const wchar_t* format, std::va_list args) { c::sgFontStrSizefvW(handle, x, y, format, args); }
                void strSizefvW(float& x, float& y, const wchar_t* format, std::va_list args) { c::sgFontStrSizefvW(handle, &x, &y, format, args); }
                void strSizef(float* x, float* y, const char* format, ...)
                {
                    std::va_list args;
                    va_start(args, format);
                    c::sgFontStrSizefv(handle, x, y, format, args);
                    va_end(args);
                }
                void strSizef(float& x, float& y, const char* format, ...)
                {
                    std::va_list args;
                    va_start(args, format);
                    c::sgFontStrSizefv(handle, &x, &y, format, args);
                    va_end(args);
                }
                void strSizefv(float* x, float* y, const char* format, std::va_list args) { c::sgFontStrSizefv(handle, x, y, format, args); }
                void strSizefv(float& x, float& y, const char* format, std::va_list args) { c::sgFontStrSizefv(handle, &x, &y, format, args); }

                void strSizeU32(float* x, float* y, const c::SGdchar* text) { c::sgFontStrSizeU32(handle, x, y, text); }
                void strSizeU32(float& x, float& y, const c::SGdchar* text) { c::sgFontStrSizeU32(handle, &x, &y, text); }
                void strSizeU16(float* x, float* y, const c::SGwchar* text) { c::sgFontStrSizeU16(handle, x, y, text); }
                void strSizeU16(float& x, float& y, const c::SGwchar* text) { c::sgFontStrSizeU16(handle, &x, &y, text); }
                void strSizeU8(float* x, float* y, const c::SGchar* text) { c::sgFontStrSizeU8(handle, x, y, text); }
                void strSizeU8(float& x, float& y, const c::SGchar* text) { c::sgFontStrSizeU8(handle, &x, &y, text); }
                void strSizeW(float* x, float* y, const wchar_t* text) { c::sgFontStrSizeW(handle, x, y, text); }
                void strSizeW(float& x, float& y, const wchar_t* text) { c::sgFontStrSizeW(handle, &x, &y, text); }
                void strSize(float* x, float* y, const char* text) { c::sgFontStrSize(handle, x, y, text); }
                void strSize(float& x, float& y, const char* text) { c::sgFontStrSize(handle, &x, &y, text); }

                std::size_t findIndexfW(float x, float y, const wchar_t* format, ...)
                {
                    std::va_list args;
                    va_start(args, format);
                    std::size_t ret = c::sgFontFindIndexfvW(handle, x, y, format, args);
                    va_end(args);
                    return ret;
                }
                std::size_t findIndexfvW(float x, float y, const wchar_t* format, std::va_list args) { return c::sgFontFindIndexfvW(handle, x, y, format, args); }
                std::size_t findIndexf(float x, float y, const char* format, ...)
                {
                    std::va_list args;
                    va_start(args, format);
                    std::size_t ret = c::sgFontFindIndexfv(handle, x, y, format, args);
                    va_end(args);
                    return ret;
                }
                std::size_t findIndexfv(float x, float y, const char* format, std::va_list args) { return c::sgFontFindIndexfv(handle, x, y, format, args); }

                std::size_t findIndexU32(float x, float y, const c::SGdchar* text) { return c::sgFontFindIndexU32(handle, x, y, text); }
                std::size_t findIndexU16(float x, float y, const c::SGwchar* text) { return c::sgFontFindIndexU16(handle, x, y, text); }
                std::size_t findIndexU8(float x, float y, const c::SGchar* text) { return c::sgFontFindIndexU8(handle, x, y, text); }
                std::size_t findIndexW(float x, float y, const wchar_t* text) { return c::sgFontFindIndexW(handle, x, y, text); }
                std::size_t findIndex(float x, float y, const char* text) { return c::sgFontFindIndex(handle, x, y, text); }

                void getPosfW(float* x, float* y, std::size_t index, const wchar_t* format, ...)
                {
                    std::va_list args;
                    va_start(args, format);
                    c::sgFontGetPosfvW(handle, x, y, index, format, args);
                    va_end(args);
                }
                void getPosfW(float& x, float& y, std::size_t index, const wchar_t* format, ...)
                {
                    std::va_list args;
                    va_start(args, format);
                    c::sgFontGetPosfvW(handle, &x, &y, index, format, args);
                    va_end(args);
                }
                void getPosfvW(float* x, float* y, std::size_t index, const wchar_t* format, std::va_list args) { c::sgFontGetPosfvW(handle, x, y, index, format, args); }
                void getPosfvW(float& x, float& y, std::size_t index, const wchar_t* format, std::va_list args) { c::sgFontGetPosfvW(handle, &x, &y, index, format, args); }
                void getPosf(float* x, float* y, std::size_t index, const char* format, ...)
                {
                    std::va_list args;
                    va_start(args, format);
                    c::sgFontGetPosfv(handle, x, y, index, format, args);
                    va_end(args);
                }
                void getPosf(float& x, float& y, std::size_t index, const char* format, ...)
                {
                    std::va_list args;
                    va_start(args, format);
                    c::sgFontGetPosfv(handle, &x, &y, index, format, args);
                    va_end(args);
                }
                void getPosfv(float* x, float* y, std::size_t index, const char* format, std::va_list args) { c::sgFontGetPosfv(handle, x, y, index, format, args); }
                void getPosfv(float& x, float& y, std::size_t index, const char* format, std::va_list args) { c::sgFontGetPosfv(handle, &x, &y, index, format, args); }

                void getPosU32(float* x, float* y, std::size_t index, const c::SGdchar* text) { c::sgFontGetPosU32(handle, x, y, index, text); }
                void getPosU32(float& x, float& y, std::size_t index, const c::SGdchar* text) { c::sgFontGetPosU32(handle, &x, &y, index, text); }
                void getPosU16(float* x, float* y, std::size_t index, const c::SGwchar* text) { c::sgFontGetPosU16(handle, x, y, index, text); }
                void getPosU16(float& x, float& y, std::size_t index, const c::SGwchar* text) { c::sgFontGetPosU16(handle, &x, &y, index, text); }
                void getPosU8(float* x, float* y, std::size_t index, const c::SGchar* text) { c::sgFontGetPosU8(handle, x, y, index, text); }
                void getPosU8(float& x, float& y, std::size_t index, const c::SGchar* text) { c::sgFontGetPosU8(handle, &x, &y, index, text); }
                void getPosW(float* x, float* y, std::size_t index, const wchar_t* text) { c::sgFontGetPosW(handle, x, y, index, text); }
                void getPosW(float& x, float& y, std::size_t index, const wchar_t* text) { c::sgFontGetPosW(handle, &x, &y, index, text); }
                void getPos(float* x, float* y, std::size_t index, const char* text) { c::sgFontGetPos(handle, x, y, index, text); }
                void getPos(float& x, float& y, std::size_t index, const char* text) { c::sgFontGetPos(handle, &x, &y, index, text); }
        } ;
        RTYPE(Font);
    }
}

#endif // __CPP_SIEGE_GRAPHICS_FONT_H__
