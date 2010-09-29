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

#ifndef __CPP_SIEGE_GRAPHICS_DRAW_H__
#define __CPP_SIEGE_GRAPHICS_DRAW_H__

#include "../common.hh"

namespace siege
{
    namespace graphics
    {
        namespace draw
        {
            /// \todo overload
            void begin(siege::c::SGenum type, siege::c::SGTexture* texture);
            void begin(siege::c::SGenum type);
            void end();
            void color(float r, float g, float b, float a);
            void color(float r, float g, float b);
            void color(float g, float a);
            void color(float g);
            void color(siege::c::SGubyte r, siege::c::SGubyte g, siege::c::SGubyte b, siege::c::SGubyte a);
            void color(siege::c::SGubyte r, siege::c::SGubyte g, siege::c::SGubyte b);
            void color(siege::c::SGubyte g, siege::c::SGubyte a);
            void color(siege::c::SGubyte g);
            void texCoord(float x, float y);
            void vertex(float x, float y, float z);
            void vertex(float x, float y);
            void clear(float r, float g, float b, float a);
            void clear(float r, float g, float b);
            void clear(float g, float a);
            void clear(float g);
            void clear(siege::c::SGubyte r, siege::c::SGubyte g, siege::c::SGubyte b, siege::c::SGubyte a);
            void clear(siege::c::SGubyte r, siege::c::SGubyte g, siege::c::SGubyte b);
            void clear(siege::c::SGubyte g, siege::c::SGubyte a);
            void clear(siege::c::SGubyte g);
            void clear();

            void point(float x, float y);
            void pointSetSize(float size);
            // float pointGetSize();

            void line(float x1, float y1, float x2, float y2);
            void lineSetWidth(float width);
            // float lineGetWidth();

            void triangle(float x1, float y1, float x2, float y2, float x3, float y3, bool fill = true);

            void quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, bool fill = true);

            void rectangle(float x1, float y1, float x2, float y2, bool fill = true);

            void ellipse2R(float x, float y, float rx, float ry, bool fill = true);

            void circle(float x, float y, float radius, bool fill = true);
        }
    }
}

#endif // __CPP_SIEGE_GRAPHICS_DRAW_H__
