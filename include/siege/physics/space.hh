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

#ifndef __CPP_SIEGE_PHYSICS_SPACE_H__
#define __CPP_SIEGE_PHYSICS_SPACE_H__

#include "../common.hh"

namespace siege
{
    namespace physics
    {
        class Space: public SGClass<c::SGPhysicsSpace>
        {
            void* data;
        private:
            void create() { handle = c::sgPhysicsSpaceCreate(); c::sgPhysicsSpaceSetData(handle, this); }

        public:
            /// \todo overload
            explicit Space() { create(); }
            ~Space() { c::sgPhysicsSpaceDestroy(handle); }

            void step(float time) { c::sgPhysicsSpaceStep(handle, time); }

            void setIterations(c::SGuint iterations) { c::sgPhysicsSpaceSetIterations(handle, iterations); }
            void setGravity(float x, float y) { c::sgPhysicsSpaceSetGravity(handle, x, y); }
            //void getGravity()
            void setDamping(float damping) { c::sgPhysicsSpaceSetDamping(handle, damping); }
            //void getDamping()

            // TODO: Should we remove this?
            void setData(void* datav) { data = datav; }
            void* getData() { return data; }

            //getStaticBody() => problem because of refcounting ...
            //getDefault() => problem because of refcounting and handle stuff
        } ;
        RTYPE(Space);
    }
}

#endif // __CPP_SIEGE_PHYSICS_SHAPE_H__
