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

#ifndef __CPP_SIEGE_GRAPHICS_BITMAP_H__
#define __CPP_SIEGE_GRAPHICS_BITMAP_H__

#include "../common.hh"

namespace siege
{
    namespace graphics
    {
        class Bitmap: public SGClass<c::SGBitmap>
        {
        private:
            //void create(PStream stream) { handle = c::sgBitmapCreateStream }
            void create(const char* fname) { handle = c::sgBitmapCreateFile(fname); }
            void create(std::size_t width, std::size_t height, c::SGenum bpp, void* data) { handle = c::sgBitmapCreateData(width, height, bpp, data); }
            void create(std::size_t width, std::size_t height, c::SGenum bpp) { handle = c::sgBitmapCreate(width, height, bpp); }

        public:
            /// \todo overload
            //Bitmap(PStream stream)
            Bitmap(const char* fname) { create(fname); }
            Bitmap(std::size_t width, std::size_t height, c::SGenum bpp, void* data) { create(width, height, bpp, data); }
            Bitmap(std::size_t width, std::size_t height, c::SGenum bpp) { create(width, height, bpp); }
            ~Bitmap() { if(handle) c::sgBitmapDestroy(handle); }

            void destroy() { c::sgBitmapDestroy(handle); handle = NULL; }

            //bool convert(c::SGenum bpp);

            //void setData(std::size_t width, std::size_t height, c::SGenum bpp, void* data) { c::sgBitmapSetData(handle, width, height, bpp, data); }
            void getData(std::size_t* width, std::size_t* height, c::SGenum* bpp, void** data) { c::sgBitmapGetData(handle, width, height, bpp, data); }
            void getData(std::size_t& width, std::size_t& height, c::SGenum& bpp, void*& data) { c::sgBitmapGetData(handle, &width, &height, &bpp, &data); }

            void getSize(std::size_t* width, std::size_t* height) { c::sgBitmapGetSize(handle, width, height); }
            void getSize(std::size_t& width, std::size_t& height) { c::sgBitmapGetSize(handle, &width, &height); }
            std::size_t getWidth() { return c::sgBitmapGetWidth(handle); }
            std::size_t getHeight() { return c::sgBitmapGetHeight(handle); }

            c::SGenum getBPP() { return c::sgBitmapGetBPP(handle); }
        } ;
        RTYPE(Bitmap);
    }
}

#endif // __CPP_SIEGE_GRAPHICS_BITMAP_H__
