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

#ifndef __CPP_SIEGE_H__
#define __CPP_SIEGE_H__

#include "common.hh"
#include "audio/buffer.hh"
#include "audio/source.hh"
#include "core/core.hh"
#include "core/entity.hh"
#include "core/window.hh"
#include "graphics/draw.hh"
#include "graphics/font.hh"
#include "graphics/sprite.hh"
#include "graphics/turtle.hh"
#include "graphics/viewport.hh"
#include "input/keyboard.hh"

namespace siege
{
	namespace type
	{
		using c::SGbool;
		using c::SGenum;

		using c::SGchar;
		using c::SGwchar;
		using c::SGdchar;

		using c::SGbyte;
		using c::SGubyte;
		using c::SGshort;
		using c::SGushort;
		using c::SGint;
		using c::SGuint;
		using c::SGlong;
		using c::SGulong;

		using c::SGfloat;
		using c::SGdouble;
	}
}

#endif // __CPP_SIEGE_H__
