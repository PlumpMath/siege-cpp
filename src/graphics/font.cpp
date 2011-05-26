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

using namespace std;

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

        void Font::printf(float x, float y, const char* format, ...)
        {
            va_list args;
            va_start(args, format);
            sgFontPrintfv(handle, x, y, format, args);
            va_end(args);
        }
        void Font::printfv(float x, float y, const char* format, va_list args)
        {
            sgFontPrintfv(handle, x, y, format, args);
        }
        void Font::printfW(float x, float y, const wchar_t* format, ...)
        {
			va_list args;
			va_start(args, format);
			sgFontPrintfvW(handle, x, y, format, args);
			va_end(args);
		}
		void Font::printfvW(float x, float y, const wchar_t* format, va_list args)
		{
			sgFontPrintfvW(handle, x, y, format, args);
		}

		void Font::printU32(float x, float y, const SGdchar* text)
        {
            sgFontPrintU32(handle, x, y, text);
        }
		void Font::printU16(float x, float y, const SGwchar* text)
        {
            sgFontPrintU16(handle, x, y, text);
        }
        void Font::printU8(float x, float y, const SGchar* text)
        {
            sgFontPrintU8(handle, x, y, text);
        }
        void Font::printW(float x, float y, const wchar_t* text)
        {
            sgFontPrintW(handle, x, y, text);
        }
        void Font::print(float x, float y, const char* text)
        {
            sgFontPrint(handle, x, y, text);
        }

        void Font::printCenteredf(float x, float y, const char* format, ...)
        {
            va_list args;
            va_start(args, format);
            sgFontPrintCenteredfv(handle, x, y, format, args);
            va_end(args);
        }
        void Font::printCenteredfv(float x, float y, const char* format, va_list args)
        {
            sgFontPrintCenteredfv(handle, x, y, format, args);
        }
        void Font::printCenteredfW(float x, float y, const wchar_t* format, ...)
        {
			va_list args;
			va_start(args, format);
			sgFontPrintCenteredfvW(handle, x, y, format, args);
			va_end(args);
		}
		void Font::printCenteredfvW(float x, float y, const wchar_t* format, va_list args)
		{
			sgFontPrintCenteredfvW(handle, x, y, format, args);
		}

		void Font::printCenteredU32(float x, float y, const SGdchar* text)
        {
            sgFontPrintCenteredU32(handle, x, y, text);
        }
		void Font::printCenteredU16(float x, float y, const SGwchar* text)
        {
            sgFontPrintCenteredU16(handle, x, y, text);
        }
        void Font::printCenteredU8(float x, float y, const SGchar* text)
        {
            sgFontPrintCenteredU8(handle, x, y, text);
        }
        void Font::printCenteredW(float x, float y, const wchar_t* text)
        {
            sgFontPrintCenteredW(handle, x, y, text);
        }
        void Font::printCentered(float x, float y, const char* text)
        {
            sgFontPrintCentered(handle, x, y, text);
        }

        void Font::printXCenteredf(float x, float y, const char* format, ...)
        {
            va_list args;
            va_start(args, format);
            sgFontPrintXCenteredfv(handle, x, y, format, args);
            va_end(args);
        }
        void Font::printXCenteredfv(float x, float y, const char* format, va_list args)
        {
            sgFontPrintXCenteredfv(handle, x, y, format, args);
        }
        void Font::printXCenteredfW(float x, float y, const wchar_t* format, ...)
        {
			va_list args;
			va_start(args, format);
			sgFontPrintXCenteredfvW(handle, x, y, format, args);
			va_end(args);
		}
		void Font::printXCenteredfvW(float x, float y, const wchar_t* format, va_list args)
		{
			sgFontPrintXCenteredfvW(handle, x, y, format, args);
		}

		void Font::printXCenteredU32(float x, float y, const SGdchar* text)
        {
            sgFontPrintXCenteredU32(handle, x, y, text);
        }
		void Font::printXCenteredU16(float x, float y, const SGwchar* text)
        {
            sgFontPrintXCenteredU16(handle, x, y, text);
        }
        void Font::printXCenteredU8(float x, float y, const SGchar* text)
        {
            sgFontPrintXCenteredU8(handle, x, y, text);
        }
        void Font::printXCenteredW(float x, float y, const wchar_t* text)
        {
            sgFontPrintXCenteredW(handle, x, y, text);
        }
        void Font::printXCentered(float x, float y, const char* text)
        {
            sgFontPrintXCentered(handle, x, y, text);
        }

        void Font::printYCenteredf(float x, float y, const char* format, ...)
        {
            va_list args;
            va_start(args, format);
            sgFontPrintYCenteredfv(handle, x, y, format, args);
            va_end(args);
        }
        void Font::printYCenteredfv(float x, float y, const char* format, va_list args)
        {
            sgFontPrintYCenteredfv(handle, x, y, format, args);
        }
        void Font::printYCenteredfW(float x, float y, const wchar_t* format, ...)
        {
			va_list args;
			va_start(args, format);
			sgFontPrintYCenteredfvW(handle, x, y, format, args);
			va_end(args);
		}
		void Font::printYCenteredfvW(float x, float y, const wchar_t* format, va_list args)
		{
			sgFontPrintYCenteredfvW(handle, x, y, format, args);
		}

		void Font::printYCenteredU32(float x, float y, const SGdchar* text)
        {
            sgFontPrintYCenteredU32(handle, x, y, text);
        }
		void Font::printYCenteredU16(float x, float y, const SGwchar* text)
        {
            sgFontPrintYCenteredU16(handle, x, y, text);
        }
        void Font::printYCenteredU8(float x, float y, const SGchar* text)
        {
            sgFontPrintYCenteredU8(handle, x, y, text);
        }
        void Font::printYCenteredW(float x, float y, const wchar_t* text)
        {
            sgFontPrintYCenteredW(handle, x, y, text);
        }
        void Font::printYCentered(float x, float y, const char* text)
        {
            sgFontPrintYCentered(handle, x, y, text);
        }

        void Font::strSizef(float* x, float* y, const char* format, ...)
        {
            va_list args;
            va_start(args, format);
            sgFontStrSizefv(handle, x, y, format, args);
            va_end(args);
        }
        void Font::strSizef(float& x, float& y, const char* format, ...)
        {
            va_list args;
            va_start(args, format);
            sgFontStrSizefv(handle, &x, &y, format, args);
            va_end(args);
        }
        void Font::strSizefv(float* x, float* y, const char* format, va_list args)
        {
            sgFontStrSizefv(handle, x, y, format, args);
        }
        void Font::strSizefv(float& x, float& y, const char* format, va_list args)
        {
            sgFontStrSizefv(handle, &x, &y, format, args);
        }
        void Font::strSizefW(float* x, float* y, const wchar_t* format, ...)
        {
			va_list args;
			va_start(args, format);
			sgFontStrSizefvW(handle, x, y, format, args);
			va_end(args);
		}
        void Font::strSizefW(float& x, float& y, const wchar_t* format, ...)
        {
			va_list args;
			va_start(args, format);
			sgFontStrSizefvW(handle, &x, &y, format, args);
			va_end(args);
		}
		void Font::strSizefvW(float* x, float* y, const wchar_t* format, va_list args)
		{
			sgFontStrSizefvW(handle, x, y, format, args);
		}
		void Font::strSizefvW(float& x, float& y, const wchar_t* format, va_list args)
		{
			sgFontStrSizefvW(handle, &x, &y, format, args);
		}

        void Font::strSizeU32(float* x, float* y, const SGdchar* text)
        {
            sgFontStrSizeU32(handle, x, y, text);
        }
        void Font::strSizeU32(float& x, float& y, const SGdchar* text)
        {
            sgFontStrSizeU32(handle, &x, &y, text);
        }
        void Font::strSizeU16(float* x, float* y, const SGwchar* text)
        {
            sgFontStrSizeU16(handle, x, y, text);
        }
        void Font::strSizeU16(float& x, float& y, const SGwchar* text)
        {
            sgFontStrSizeU16(handle, &x, &y, text);
        }
        void Font::strSizeU8(float* x, float* y, const SGchar* text)
        {
            sgFontStrSizeU8(handle, x, y, text);
        }
        void Font::strSizeU8(float& x, float& y, const SGchar* text)
        {
            sgFontStrSizeU8(handle, &x, &y, text);
        }
        void Font::strSizeW(float* x, float* y, const wchar_t* text)
        {
            sgFontStrSizeW(handle, x, y, text);
        }
        void Font::strSizeW(float& x, float& y, const wchar_t* text)
        {
            sgFontStrSizeW(handle, &x, &y, text);
        }
        void Font::strSize(float* x, float* y, const char* text)
        {
            sgFontStrSize(handle, x, y, text);
        }
        void Font::strSize(float& x, float& y, const char* text)
        {
            sgFontStrSize(handle, &x, &y, text);
        }
    }
}
