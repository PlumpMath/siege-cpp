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

#ifndef __CPP_SIEGE_H__
#define __CPP_SIEGE_H__

#include "common.hh"
#include "audio/buffer.hh"
#include "audio/source.hh"
#include "core/core.hh"
#include "core/window.hh"
#include "graphics/draw.hh"
#include "graphics/turtle.hh"
#include "graphics/viewport.hh"
#include "input/keyboard.hh"

namespace siege
{
    namespace type
    {
        using siege::c::SGvoid;
        using siege::c::SGbool;
        using siege::c::SGenum;

        using siege::c::SGchar;
        using siege::c::SGwchar;
        using siege::c::SGdchar;

        using siege::c::SGbyte;
        using siege::c::SGubyte;
        using siege::c::SGshort;
        using siege::c::SGushort;
        using siege::c::SGint;
        using siege::c::SGuint;
        using siege::c::SGlong;
        using siege::c::SGulong;

        using siege::c::SGfloat;
        using siege::c::SGdouble;
    }
}


#endif // __CPP_SIEGE_H__
