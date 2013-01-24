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

#ifndef __CPP_SIEGE_GRAPHICS_DRAW_H__
#define __CPP_SIEGE_GRAPHICS_DRAW_H__

#include "../common.hh"

namespace siege
{
    namespace graphics
    {
        namespace draw
        {
            inline void begin(c::SGenum type, c::SGTexture* texture) { c::sgDrawBeginT(type, texture); }
            inline void begin(c::SGenum type) { c::sgDrawBegin(type); }
            inline void end() { c::sgDrawEnd(); }

            inline void color(float r, float g, float b, float a) { c::sgDrawColor4f(r, g, b, a); }
            inline void color(float r, float g, float b) { c::sgDrawColor3f(r, g, b); }
            inline void color(float g, float a) { c::sgDrawColor2f(g, a); }
            inline void color(float g) { c::sgDrawColor1f(g); }

            inline void color(c::SGubyte r, c::SGubyte g, c::SGubyte b, c::SGubyte a) { c::sgDrawColor4ub(r, g, b, a); }
            inline void color(c::SGubyte r, c::SGubyte g, c::SGubyte b) { c::sgDrawColor3ub(r, g, b); }
            inline void color(c::SGubyte g, c::SGubyte a) { c::sgDrawColor2ub(g, a); }
            inline void color(c::SGubyte g) { c::sgDrawColor1ub(g); }

            inline void texCoord(float x, float y) { c::sgDrawTexCoord2f(x, y); }

            inline void vertex(float x, float y, float z) { c::sgDrawVertex3f(x, y, z); }
            inline void vertex(float x, float y) { c::sgDrawVertex2f(x, y); }

            inline void clear(float r, float g, float b, float a) { c::sgDrawClear4f(r, g, b, a); }
            inline void clear(float r, float g, float b) { c::sgDrawClear3f(r, g, b); }
            inline void clear(float g, float a) { c::sgDrawClear2f(g, a); }
            inline void clear(float g) { c::sgDrawClear1f(g); }

            inline void clear(c::SGubyte r, c::SGubyte g, c::SGubyte b, c::SGubyte a) { c::sgDrawClear4ub(r, g, b, a); }
            inline void clear(c::SGubyte r, c::SGubyte g, c::SGubyte b) { c::sgDrawClear3ub(r, g, b); }
            inline void clear(c::SGubyte g, c::SGubyte a) { c::sgDrawClear2ub(g, a); }
            inline void clear(c::SGubyte g) { c::sgDrawClear1ub(g); }
            inline void clear() { c::sgDrawClear(); }

            inline void point(float x, float y) { c::sgDrawPoint(x, y); }
            inline void pointSetSize(float size) { c::sgDrawPointSetSize(size);}
            // inline float pointGetSize();

            inline void line(float x1, float y1, float x2, float y2) { c::sgDrawLine(x1, y1, x2, y2); }
            inline void lineSetWidth(float width) { c::sgDrawLineSetWidth(width); }
            // inline float lineGetWidth();

            inline void triangle(float x1, float y1, float x2, float y2, float x3, float y3, bool fill = true) { c::sgDrawTriangle(x1, y1, x2, y2, x3, y3, fill); }

            inline void quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, bool fill = true) { c::sgDrawQuad(x1, y1, x2, y2, x3, y3, x4, y4, fill); }

            inline void rectangle(float x1, float y1, float x2, float y2, bool fill = true) { c::sgDrawRectangle(x1, y1, x2, y2, fill); }

            inline void ellipse2R(float x, float y, float rx, float ry, bool fill = true) { c::sgDrawEllipse2R(x, y, rx, ry, fill); }

            inline void circle(float x, float y, float radius, bool fill = true) { c::sgDrawCircle(x, y, radius, fill); }

            inline void earcRads(float x, float y, float rx, float ry, float start, float end, bool ccw, bool fill = true) { c::sgDrawEArcRads(x, y, rx, ry, start, end, ccw, fill); }
            inline void earcDegs(float x, float y, float rx, float ry, float start, float end, bool ccw, bool fill = true) { c::sgDrawEArcDegs(x, y, rx, ry, start, end, ccw, fill); }

            inline void arcRads(float x, float y, float radius, float start, float end, bool ccw, bool fill = true) { c::sgDrawArcRads(x, y, radius, start, end, ccw, fill); }
            inline void arcDegs(float x, float y, float radius, float start, float end, bool ccw, bool fill = true) { c::sgDrawArcDegs(x, y, radius, start, end, ccw, fill); }
        }
    }
}

#endif // __CPP_SIEGE_GRAPHICS_DRAW_H__
