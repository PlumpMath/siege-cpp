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

#ifndef __CPP_SIEGE_GRAPHICS_TEXTURE_H__
#define __CPP_SIEGE_GRAPHICS_TEXTURE_H__

#include "../common.hh"

namespace siege
{
    namespace graphics
    {
        class Texture: public SGClass<c::SGTexture>
        {
        private:
            //void create(PStream stream) { handle = c::sgTextureCreateStream }
            void create(const char* fname) { handle = c::sgTextureCreateFile(fname); }
            void create(std::size_t width, std::size_t height, c::SGenum bpp, void* data) { handle = c::sgTextureCreateData(width, height, bpp, data); }
            void create(std::size_t width, std::size_t height, c::SGenum bpp) { handle = c::sgTextureCreate(width, height, bpp); }

        public:
            /// \todo overload
            //Texture(PStream stream)
            Texture(const char* fname) { create(fname); }
            Texture(std::size_t width, std::size_t height, c::SGenum bpp, void* data) { create(width, height, bpp, data); }
            Texture(std::size_t width, std::size_t height, c::SGenum bpp) { create(width, height, bpp); }
            ~Texture() { if(handle) c::sgTextureDestroy(handle); }

            void destroy() { c::sgTextureDestroy(handle); handle = NULL; }

            void setData(std::size_t width, std::size_t height, c::SGenum bpp, void* data) { c::sgTextureSetData(handle, width, height, bpp, data); }
            void setSubData(std::size_t x, std::size_t y, std::size_t width, std::size_t height, c::SGenum bpp, void* data) { c::sgTextureSetSubData(handle, x, y, width, height, bpp, data); }
            void* getData() { return c::sgTextureGetData(handle); }
            static void freeData(void* data) { c::sgTextureFreeData(data); }

            void drawRads(float x, float y, float z, float xscale, float yscale, float xoffset, float yoffset, float angle) { c::sgTextureDrawRads3f2f2f1f(handle, x, y, z, xscale, yscale, xoffset, yoffset, angle); }
            void drawDegs(float x, float y, float z, float xscale, float yscale, float xoffset, float yoffset, float angle) { c::sgTextureDrawDegs3f2f2f1f(handle, x, y, z, xscale, yscale, xoffset, yoffset, angle); }
            void drawRads(float x, float y, float xscale, float yscale, float xoffset, float yoffset, float angle) { c::sgTextureDrawRads2f2f2f1f(handle, x, y, xscale, yscale, xoffset, yoffset, angle); }
            void drawDegs(float x, float y, float xscale, float yscale, float xoffset, float yoffset, float angle) { c::sgTextureDrawDegs2f2f2f1f(handle, x, y, xscale, yscale, xoffset, yoffset, angle); }
            void drawRads(float x, float y, float z, float xscale, float yscale, float angle) { c::sgTextureDrawRads3f2f1f(handle, x, y, z, xscale, yscale, angle); }
            void drawDegs(float x, float y, float z, float xscale, float yscale, float angle) { c::sgTextureDrawDegs3f2f1f(handle, x, y, z, xscale, yscale, angle); }
            void drawRads(float x, float y, float xscale, float yscale, float angle) { c::sgTextureDrawRads2f2f1f(handle, x, y, xscale, yscale, angle); }
            void drawDegs(float x, float y, float xscale, float yscale, float angle) { c::sgTextureDrawDegs2f2f1f(handle, x, y, xscale, yscale, angle); }
            void drawRads(float x, float y, float z, float angle) { c::sgTextureDrawRads3f1f(handle, x, y, z, angle); }
            void drawDegs(float x, float y, float z, float angle) { c::sgTextureDrawDegs3f1f(handle, x, y, z, angle); }
            void drawRads(float x, float y, float angle) { c::sgTextureDrawRads2f1f(handle, x, y, angle); }
            void drawDegs(float x, float y, float angle) { c::sgTextureDrawDegs2f1f(handle, x, y, angle); }

            void draw(float x, float y, float z, float xscale, float yscale, float xoffset, float yoffset) { c::sgTextureDraw3f2f2f(handle, x, y, z, xscale, yscale, xoffset, yoffset); }
            void draw(float x, float y, float xscale, float yscale, float xoffset, float yoffset) { c::sgTextureDraw2f2f2f(handle, x, y, xscale, yscale, xoffset, yoffset); }
            void draw(float x, float y, float z, float xscale, float yscale) { c::sgTextureDraw3f2f(handle, x, y, z, xscale, yscale); }
            void draw(float x, float y, float xscale, float yscale) { c::sgTextureDraw2f2f(handle, x, y, xscale, yscale); }
            void draw(float x, float y, float z) { c::sgTextureDraw3f(handle, x, y, z); }
            void draw(float x, float y) { c::sgTextureDraw2f(handle, x, y); }
            void draw() { c::sgTextureDraw(handle); }

            void setWrap(c::SGenum swrap, c::SGenum twrap) { c::sgTextureSetWrap(handle, swrap, twrap); }
            void setInterpolation(c::SGenum interp) { c::sgTextureSetInterpolation(handle, interp); }

            void getSize(c::SGuint* width, c::SGuint* height) { c::sgTextureGetSize(handle, width, height); }
            void getSize(c::SGuint& width, c::SGuint& height) { c::sgTextureGetSize(handle, &width, &height); }
            std::size_t getWidth() { return c::sgTextureGetWidth(handle); }
            std::size_t getHeight() { return c::sgTextureGetHeight(handle); }
            c::SGenum getBPP() { return c::sgTextureGetBPP(handle); }
        } ;
        RTYPE(Texture);
    }
}

#endif // __CPP_SIEGE_GRAPHICS_TEXTURE_H__
