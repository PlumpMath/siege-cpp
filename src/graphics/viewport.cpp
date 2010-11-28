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

#include "viewport.hh"

using namespace siege::c;
namespace siege
{
	namespace graphics
	{
		void Viewport::create(SGuint wposx, SGuint wposy, SGuint wsizex, SGuint wsizey, float posx, float posy, float sizex, float sizey)
		{
			handle = sgViewportCreate4i4f(wposx, wposy, wsizex, wsizey, posx, posy, sizex, sizey);
		}
		void Viewport::create(SGuint wposx, SGuint wposy, SGuint wsizex, SGuint wsizey)
		{
			handle = sgViewportCreate4i(wposx, wposy, wsizex, wsizey);
		}
		void Viewport::create()
		{
			handle = sgViewportCreate();
		}

		Viewport::Viewport(SGuint wposx, SGuint wposy, SGuint wsizex, SGuint wsizey, float posx, float posy, float sizex, float sizey)
		{
			create(wposx, wposy, wsizex, wsizey, posx, posy, sizex, sizey);
		}
		Viewport::Viewport(SGuint wposx, SGuint wposy, SGuint wsizex, SGuint wsizey)
		{
			create(wposx, wposy, wsizex, wsizey);
		}
		Viewport::Viewport()
		{
			create();
		}
		Viewport::~Viewport()
		{
			sgViewportDestroy(handle);
		}

		void Viewport::set(SGuint wposx, SGuint wposy, SGuint wsizex, SGuint wsizey, float posx, float posy, float sizex, float sizey)
		{
			sgViewportSet4i4f(handle, wposx, wposy, wsizex, wsizey, posx, posy, sizex, sizey);
		}
		void Viewport::set(SGuint wposx, SGuint wposy, SGuint wsizex, SGuint wsizey)
		{
			sgViewportSet4i(handle, wposx, wposy, wsizex, wsizey);
		}
		void Viewport::reset()
		{
			sgViewportReset(handle);
		}
	}
}
