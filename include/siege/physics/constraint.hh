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

#ifndef __CPP_SIEGE_PHYSICS_CONSTRAINT_H__
#define __CPP_SIEGE_PHYSICS_CONSTRAINT_H__

#include "../common.hh"

namespace siege
{
    namespace physics
    {
        /* TODO */
        class Constraint: public SGClass<c::SGPhysicsConstraint>
        {
        private:
            //void create() { handle = c::sgPhysicsConstraintCreate(); }

        public:
            //Constraint() { create(); }
            //~Constraint() { c::sgPhysicsConstraintDestroy(handle); }
        } ;
        RTYPE(Constraint);
    }
}

#endif // __CPP_SIEGE_PHYSICS_CONSTRAINT_H__
