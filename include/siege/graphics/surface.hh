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

#ifndef __CPP_SIEGE_GRAPHICS_SURFACE_H__
#define __CPP_SIEGE_GRAPHICS_SURFACE_H__

#include "../common.hh"
#include "texture.hh"

namespace siege
{
    namespace graphics
    {
        class Surface: public SGClass<c::SGSurface>
        {
            PTexture texture;
        private:
            //void create(PStream stream) { handle = c::sgSurfaceCreateStream }
            void create(const char* fname) { handle = c::sgSurfaceCreateFile(fname); }
            void create(std::size_t width, std::size_t height, c::SGenum bpp, void* data) { handle = c::sgSurfaceCreateData(width, height, bpp, data); }
            void create(PTexture tex) { texture = tex; handle = c::sgSurfaceCreateTexture(tex->getHandle(), false); }
            void create(std::size_t width, std::size_t height, c::SGenum bpp) { handle = c::sgSurfaceCreate(width, height, bpp); }

        public:
            /// \todo overload
            //Surface(PStream stream)
            Surface(const char* fname) { create(fname); }
            Surface(std::size_t width, std::size_t height, c::SGenum bpp, void* data) { create(width, height, bpp, data); }
            Surface(PTexture tex) { create(texture); }
            Surface(std::size_t width, std::size_t height, c::SGenum bpp) { create(width, height, bpp); }
            ~Surface() { if(handle) c::sgSurfaceDestroy(handle); }

            void destroy() { c::sgSurfaceDestroy(handle); handle = NULL; }

            bool setTexture(PTexture tex) { texture = tex; return c::sgSurfaceSetTexture(handle, tex->getHandle(), false); }
            PTexture getTexture() { return texture; }

            void setData(std::size_t width, std::size_t height, c::SGenum bpp, void* data) { c::sgSurfaceSetData(handle, width, height, bpp, data); }
            void setSubData(std::size_t x, std::size_t y, std::size_t width, std::size_t height, c::SGenum bpp, void* data) { c::sgSurfaceSetSubData(handle, x, y, width, height, bpp, data); }
            void* getData() { return c::sgSurfaceGetData(handle); }
            static void freeData(void* data) { c::sgSurfaceFreeData(data); }

            void drawRads(float x, float y, float z, float xscale, float yscale, float xoffset, float yoffset, float angle) { c::sgSurfaceDrawRads3f2f2f1f(handle, x, y, z, xscale, yscale, xoffset, yoffset, angle); }
            void drawDegs(float x, float y, float z, float xscale, float yscale, float xoffset, float yoffset, float angle) { c::sgSurfaceDrawDegs3f2f2f1f(handle, x, y, z, xscale, yscale, xoffset, yoffset, angle); }
            void drawRads(float x, float y, float xscale, float yscale, float xoffset, float yoffset, float angle) { c::sgSurfaceDrawRads2f2f2f1f(handle, x, y, xscale, yscale, xoffset, yoffset, angle); }
            void drawDegs(float x, float y, float xscale, float yscale, float xoffset, float yoffset, float angle) { c::sgSurfaceDrawDegs2f2f2f1f(handle, x, y, xscale, yscale, xoffset, yoffset, angle); }
            void drawRads(float x, float y, float z, float xscale, float yscale, float angle) { c::sgSurfaceDrawRads3f2f1f(handle, x, y, z, xscale, yscale, angle); }
            void drawDegs(float x, float y, float z, float xscale, float yscale, float angle) { c::sgSurfaceDrawDegs3f2f1f(handle, x, y, z, xscale, yscale, angle); }
            void drawRads(float x, float y, float xscale, float yscale, float angle) { c::sgSurfaceDrawRads2f2f1f(handle, x, y, xscale, yscale, angle); }
            void drawDegs(float x, float y, float xscale, float yscale, float angle) { c::sgSurfaceDrawDegs2f2f1f(handle, x, y, xscale, yscale, angle); }
            void drawRads(float x, float y, float z, float angle) { c::sgSurfaceDrawRads3f1f(handle, x, y, z, angle); }
            void drawDegs(float x, float y, float z, float angle) { c::sgSurfaceDrawDegs3f1f(handle, x, y, z, angle); }
            void drawRads(float x, float y, float angle) { c::sgSurfaceDrawRads2f1f(handle, x, y, angle); }
            void drawDegs(float x, float y, float angle) { c::sgSurfaceDrawDegs2f1f(handle, x, y, angle); }

            void draw(float x, float y, float z, float xscale, float yscale, float xoffset, float yoffset) { c::sgSurfaceDraw3f2f2f(handle, x, y, z, xscale, yscale, xoffset, yoffset); }
            void draw(float x, float y, float xscale, float yscale, float xoffset, float yoffset) { c::sgSurfaceDraw2f2f2f(handle, x, y, xscale, yscale, xoffset, yoffset); }
            void draw(float x, float y, float z, float xscale, float yscale) { c::sgSurfaceDraw3f2f(handle, x, y, z, xscale, yscale); }
            void draw(float x, float y, float xscale, float yscale) { c::sgSurfaceDraw2f2f(handle, x, y, xscale, yscale); }
            void draw(float x, float y, float z) { c::sgSurfaceDraw3f(handle, x, y, z); }
            void draw(float x, float y) { c::sgSurfaceDraw2f(handle, x, y); }
            void draw() { c::sgSurfaceDraw(handle); }

            void target() { c::sgSurfaceTarget(handle); }
            void untarget() { c::sgSurfaceUntarget(handle); }

            void clear(float r, float g, float b, float a) { c::sgSurfaceClear4f(handle, r, g, b, a); }
            void clear(float r, float g, float b) { c::sgSurfaceClear3f(handle, r, g, b); }
            void clear(float g, float a) { c::sgSurfaceClear2f(handle, g, a); }
            void clear(float g) { c::sgSurfaceClear1f(handle, g); }
            void clear(c::SGubyte r, c::SGubyte g, c::SGubyte b, c::SGubyte a) { c::sgSurfaceClear4ub(handle, r, g, b, a); }
            void clear(c::SGubyte r, c::SGubyte g, c::SGubyte b) { c::sgSurfaceClear3ub(handle, r, g, b); }
            void clear(c::SGubyte g, c::SGubyte a) { c::sgSurfaceClear2ub(handle, g, a); }
            void clear(c::SGubyte g) { c::sgSurfaceClear1ub(handle, g); }
            void clear() { c::sgSurfaceClear(handle); }

            void getSize(c::SGuint* width, c::SGuint* height) { c::sgSurfaceGetSize(handle, width, height); }
            void getSize(c::SGuint& width, c::SGuint& height) { c::sgSurfaceGetSize(handle, &width, &height); }
            std::size_t getWidth() { return c::sgSurfaceGetWidth(handle); }
            std::size_t getHeight() { return c::sgSurfaceGetHeight(handle); }
            c::SGenum getBPP() { return c::sgSurfaceGetBPP(handle); }
        } ;
        RTYPE(Surface);
    }
}

#endif // __CPP_SIEGE_GRAPHICS_SURFACE_H__
