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

#ifndef __CPP_SIEGE_PHYSICS_SHAPE_H__
#define __CPP_SIEGE_PHYSICS_SHAPE_H__

#include "../common.hh"

namespace siege
{
    namespace physics
    {
        /* TODO */
        class Shape: public SGClass<c::SGPhysicsShape>
        {
        } ;
        RTYPE(Shape);
    }
}

#endif // __CPP_SIEGE_PHYSICS_SHAPE_H__
