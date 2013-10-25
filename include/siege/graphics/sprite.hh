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

#ifndef __CPP_SIEGE_GRAPHICS_SPRITE_H__
#define __CPP_SIEGE_GRAPHICS_SPRITE_H__

#include "../common.hh"
#include "texture.hh"

namespace siege
{
    namespace graphics
    {
        class Sprite: public SGClass<c::SGSprite>
        {
            PTexture texture;
        private:
            void create(PTexture tex, float xoffset, float yoffset) { texture = tex; handle = c::sgSpriteCreateTexture2f(tex->getHandle(), xoffset, yoffset); }
            void create(PTexture tex) { texture = tex; handle = c::sgSpriteCreateTexture(tex->getHandle()); }
            void create(const char* fname, float xoffset, float yoffset) { handle = c::sgSpriteCreateFile2f(fname, xoffset, yoffset); }
            void create(const char* fname) { handle = c::sgSpriteCreateFile(fname); }

        public:
            Sprite(PTexture tex, float xoffset, float yoffset) { create(tex, xoffset, yoffset); }
            Sprite(PTexture tex) { create(tex); }
            Sprite(const char* fname, float xoffset, float yoffset) { create(fname, xoffset, yoffset); }
            Sprite(const char* fname) { create(fname); }
            ~Sprite() { if(handle) c::sgSpriteDestroy(handle); }

            void destroy() { c::sgSpriteDestroy(handle); handle = NULL; }

            bool addFrameFile(const char* fname) { return c::sgSpriteAddFrameFile(handle, fname); }

            void setImage(float image) { c::sgSpriteSetImage(handle, image); }
            float getImage() { return c::sgSpriteGetImage(handle); }

            void setSpeed(float speed) { c::sgSpriteSetSpeed(handle, speed); }
            float getSpeed() { return c::sgSpriteGetSpeed(handle); }

            void drawRads(float x, float y, float z, float xscale, float yscale, float angle) { c::sgSpriteDrawRads3f2f1f(handle, x, y, z, xscale, yscale, angle); }
            void drawDegs(float x, float y, float z, float xscale, float yscale, float angle) { c::sgSpriteDrawDegs3f2f1f(handle, x, y, z, xscale, yscale, angle); }
            void drawRads(float x, float y, float xscale, float yscale, float angle) { c::sgSpriteDrawRads2f2f1f(handle, x, y, xscale, yscale, angle); }
            void drawDegs(float x, float y, float xscale, float yscale, float angle) { c::sgSpriteDrawDegs2f2f1f(handle, x, y, xscale, yscale, angle); }
            void drawRads(float x, float y, float z, float angle) { c::sgSpriteDrawRads3f1f(handle, x, y, z, angle); }
            void drawDegs(float x, float y, float z, float angle) { c::sgSpriteDrawDegs3f1f(handle, x, y, z, angle); }
            void drawRads(float x, float y, float angle) { c::sgSpriteDrawRads2f1f(handle, x, y, angle); }
            void drawDegs(float x, float y, float angle) { c::sgSpriteDrawDegs2f1f(handle, x, y, angle); }
            void draw(float x, float y, float z, float xscale, float yscale) { c::sgSpriteDraw3f2f(handle, x, y, z, xscale, yscale); }
            void draw(float x, float y, float xscale, float yscale) { c::sgSpriteDraw2f2f(handle, x, y, xscale, yscale); }
            void draw(float x, float y, float z) { c::sgSpriteDraw3f(handle, x, y, z); }
            void draw(float x, float y) { c::sgSpriteDraw2f(handle, x, y); }

            void getSize(c::SGuint* width, c::SGuint* height) { c::sgSpriteGetSize(handle, width, height); }
            void getSize(c::SGuint& width, c::SGuint& height) { c::sgSpriteGetSize(handle, &width, &height); }
            c::SGuint getWidth() { return c::sgSpriteGetWidth(handle); }
            c::SGuint getHeight() { return c::sgSpriteGetHeight(handle); }
        } ;
        RTYPE(Sprite);
    }
}

#endif // __CPP_SIEGE_GRAPHICS_SPRITE_H__
