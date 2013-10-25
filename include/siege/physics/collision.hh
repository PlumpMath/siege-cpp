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

#ifndef __CPP_SIEGE_PHYSICS_COLLISION_H__
#define __CPP_SIEGE_PHYSICS_COLLISION_H__

#include "../common.hh"
#include "shape.hh"

namespace siege
{
    namespace physics
    {
        class Collision: public SGClass<c::SGPhysicsCollision>
        {
            PShape shape1;
            PShape shape2;
        private:
            Collision(PShape s1, PShape s2): shape1(s1), shape2(s2) {}
            Collision() {}
        public:
            void ignore() { c::sgPhysicsCollisionIgnore(handle); }
            std::size_t getNumContacts() { return c::sgPhysicsCollisionGetNumContacts(handle); }

            void getPoint(std::size_t index, float* x, float* y) { return c::sgPhysicsCollisionGetPoint(handle, index, x, y); }
            void getPoint(std::size_t index, float& x, float& y) { return c::sgPhysicsCollisionGetPoint(handle, index, &x, &y); }

            void getNormal(std::size_t index, float* x, float* y) { return c::sgPhysicsCollisionGetNormal(handle, index, x, y); }
            void getNormal(std::size_t index, float& x, float& y) { return c::sgPhysicsCollisionGetNormal(handle, index, &x, &y); }

            float getDepth(std::size_t index) { return c::sgPhysicsCollisionGetDepth(handle, index); }

            void getImpulse(float* x, float* y, bool friction) { return c::sgPhysicsCollisionGetImpulse(handle, x, y, friction); }
            void getImpulse(float& x, float& y, bool friction) { return c::sgPhysicsCollisionGetImpulse(handle, &x, &y, friction); }

            PShape getShapeOne() { return shape1; }
            PShape getShapeTwo() { return shape2; }
        } ;
        RTYPE(Collision);
    }
}

#endif // __CPP_SIEGE_PHYSICS_COLLISION_H__
