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

#ifndef __CPP_SIEGE_GRAPHICS_IMAGE_H__
#define __CPP_SIEGE_GRAPHICS_IMAGE_H__

#include "../common.hh"

namespace siege
{
    namespace graphics
    {
        class ImageData: public SGClass<c::SGImageData>
        {
        private:
            //void create(PStream stream) { handle = c::sgImageDataCreateStream }
            void create(const char* fname) { handle = c::sgImageDataCreateFile(fname); }
            void create(std::size_t width, std::size_t height, c::SGenum bpp, void* data) { handle = c::sgImageDataCreateData(width, height, bpp, data); }
            void create(std::size_t width, std::size_t height, c::SGenum bpp) { handle = c::sgImageDataCreate(width, height, bpp); }

        public:
            /// \todo overload
            //ImageData(PStream stream)
            ImageData(const char* fname) { create(fname); }
            ImageData(std::size_t width, std::size_t height, c::SGenum bpp, void* data) { create(width, height, bpp, data); }
            ImageData(std::size_t width, std::size_t height, c::SGenum bpp) { create(width, height, bpp); }
            ~ImageData() { if(handle) c::sgImageDataDestroy(handle); }

            void destroy() { c::sgImageDataDestroy(handle); handle = NULL; }

            //bool convert(c::SGenum bpp);

            //void setData(std::size_t width, std::size_t height, c::SGenum bpp, void* data) { c::sgImageDataSetData(handle, width, height, bpp, data); }
            void getData(std::size_t* width, std::size_t* height, c::SGenum* bpp, void** data) { c::sgImageDataGetData(handle, width, height, bpp, data); }
            void getData(std::size_t& width, std::size_t& height, c::SGenum& bpp, void*& data) { c::sgImageDataGetData(handle, &width, &height, &bpp, &data); }

            void getSize(std::size_t* width, std::size_t* height) { c::sgImageDataGetSize(handle, width, height); }
            void getSize(std::size_t& width, std::size_t& height) { c::sgImageDataGetSize(handle, &width, &height); }
            std::size_t getWidth() { return c::sgImageDataGetWidth(handle); }
            std::size_t getHeight() { return c::sgImageDataGetHeight(handle); }

            c::SGenum getBPP() { return c::sgImageDataGetBpp(handle); }
        } ;
        RTYPE(ImageData);
    }
}

#endif // __CPP_SIEGE_GRAPHICS_IMAGE_H__
