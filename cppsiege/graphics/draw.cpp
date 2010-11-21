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

#include "draw.hh"

using namespace siege::c;
namespace siege
{
	namespace graphics
	{
		namespace draw
		{
			/// \todo overload
			void begin(SGenum type, SGTexture* texture)
			{
				sgDrawBeginT(type, texture);
			}
			void begin(SGenum type)
			{
				sgDrawBegin(type);
			}
			void end()
			{
				sgDrawEnd();
			}
			void color(float r, float g, float b, float a)
			{
				sgDrawColor4f(r, g, b, a);
			}
			void color(float r, float g, float b)
			{
				sgDrawColor3f(r, g, b);
			}
			void color(float g, float a)
			{
				sgDrawColor2f(g, a);
			}
			void color(float g)
			{
				sgDrawColor1f(g);
			}
			void color(SGubyte r, SGubyte g, SGubyte b, SGubyte a)
			{
				sgDrawColor4ub(r, g, b, a);
			}
			void color(SGubyte r, SGubyte g, SGubyte b)
			{
				sgDrawColor3ub(r, g, b);
			}
			void color(SGubyte g, SGubyte a)
			{
				sgDrawColor2ub(g, a);
			}
			void color(SGubyte g)
			{
				sgDrawColor1ub(g);
			}
			void texCoord(float x, float y)
			{
				sgDrawTexCoord2f(x, y);
			}
			void vertex(float x, float y, float z)
			{
				sgDrawVertex3f(x, y, z);
			}
			void vertex(float x, float y)
			{
				sgDrawVertex2f(x, y);
			}
			void clear(float r, float g, float b, float a)
			{
				sgDrawClear4f(r, g, b, a);
			}
			void clear(float r, float g, float b)
			{
				sgDrawClear3f(r, g, b);
			}
			void clear(float g, float a)
			{
				sgDrawClear2f(g, a);
			}
			void clear(float g)
			{
				sgDrawClear1f(g);
			}
			void clear(SGubyte r, SGubyte g, SGubyte b, SGubyte a)
			{
				sgDrawClear4ub(r, g, b, a);
			}
			void clear(SGubyte r, SGubyte g, SGubyte b)
			{
				sgDrawClear3ub(r, g, b);
			}
			void clear(SGubyte g, SGubyte a)
			{
				sgDrawClear2ub(g, a);
			}
			void clear(SGubyte g)
			{
				sgDrawClear1ub(g);
			}
			void clear()
			{
				sgDrawClear();
			}

			void point(float x, float y)
			{
				sgDrawPoint(x, y);
			}
			void pointSetSize(float size)
			{
				sgDrawPointSetSize(size);
			}
			// float pointGetSize();

			void line(float x1, float y1, float x2, float y2)
			{
				sgDrawLine(x1, y1, x2, y2);
			}
			void lineSetWidth(float width)
			{
				sgDrawLineSetWidth(width);
			}
			// float lineGetWidth();

			void triangle(float x1, float y1, float x2, float y2, float x3, float y3, bool fill)
			{
				sgDrawTriangle(x1, y1, x2, y2, x3, y3, fill);
			}

			void quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, bool fill)
			{
				sgDrawQuad(x1, y1, x2, y2, x3, y3, x4, y4, fill);
			}

			void rectangle(float x1, float y1, float x2, float y2, bool fill)
			{
				sgDrawRectangle(x1, y1, x2, y2, fill);
			}

			void ellipse2R(float x, float y, float rx, float ry, bool fill)
			{
				sgDrawEllipse2R(x, y, rx, ry, fill);
			}

			void circle(float x, float y, float radius, bool fill)
			{
				sgDrawCircle(x, y, radius, fill);
			}

			void eArcRads(float x, float y, float rx, float ry, float start, float end, bool ccw, bool fill)
			{
				sgDrawEArcRads(x, y, rx, ry, start, end, ccw, fill);
			}
			void eArcDegs(float x, float y, float rx, float ry, float start, float end, bool ccw, bool fill)
			{
				sgDrawEArcDegs(x, y, rx, ry, start, end, ccw, fill);
			}

			void arcRads(float x, float y, float radius, float start, float end, bool ccw, bool fill)
			{
				sgDrawArcRads(x, y, radius, start, end, ccw, fill);
			}
			void arcDegs(float x, float y, float radius, float start, float end, bool ccw, bool fill)
			{
				sgDrawArcDegs(x, y, radius, start, end, ccw, fill);
			}
		}
	}
}
