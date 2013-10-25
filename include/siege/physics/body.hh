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

#ifndef __CPP_SIEGE_PHYSICS_BODY_H__
#define __CPP_SIEGE_PHYSICS_BODY_H__

#include "../common.hh"
#include "space.hh"

namespace siege
{
    namespace physics
    {
        class Body: public SGClass<c::SGPhysicsBody>
        {
            PSpace space;
            void* data;
        private:
            void create(PSpace spacev, c::SGenum type) { space = spacev; handle = c::sgPhysicsBodyCreate(space ? space->getHandle() : NULL, type); c::sgPhysicsBodySetData(handle, this); }

        public:
            /// \todo overload
            Body(PSpace space, c::SGenum type) { create(space, type); }
            ~Body() { if(handle) c::sgPhysicsBodyDestroy(handle); }

            void destroy() { c::sgPhysicsBodyDestroy(handle); handle = NULL; }

            // TODO: do we need this?
            void setData(void* datav) { data = datav; }
            void* getData() { return data; }

            void setSleeping(bool sleeping) { c::sgPhysicsBodySetSleeping(handle, sleeping); }
            bool getSleeping() { return c::sgPhysicsBodyGetSleeping(handle); }

            void setPos(float x, float y) { c::sgPhysicsBodySetPos(handle, x, y); }
            void getPos(float* x, float* y) { c::sgPhysicsBodyGetPos(handle, x, y); }
            void getPos(float& x, float& y) { c::sgPhysicsBodyGetPos(handle, &x, &y); }

            void setPosX(float x) { c::sgPhysicsBodySetPosX(handle, x); }
            float getPosX() { return c::sgPhysicsBodyGetPosX(handle); }
            void setPosY(float y) { c::sgPhysicsBodySetPosY(handle, y); }
            float getPosY() { return c::sgPhysicsBodyGetPosY(handle); }

            void setAngleRads(float rads) { c::sgPhysicsBodySetAngleRads(handle, rads); }
            float getAngleRads() { return c::sgPhysicsBodyGetAngleRads(handle); }
            void setAngleDegs(float degs) { c::sgPhysicsBodySetAngleDegs(handle, degs); }
            float getAngleDegs() { return c::sgPhysicsBodyGetAngleDegs(handle); }

            void setVel(float x, float y) { c::sgPhysicsBodySetVel(handle, x, y); }
            void getVel(float* x, float* y) { c::sgPhysicsBodyGetVel(handle, x, y); }
            void getVel(float& x, float& y) { c::sgPhysicsBodyGetVel(handle, &x, &y); }

            void setVelX(float x) { c::sgPhysicsBodySetVelX(handle, x); }
            float getVelX() { return c::sgPhysicsBodyGetVelX(handle); }
            void setVelY(float y) { c::sgPhysicsBodySetVelY(handle, y); }
            float getVelY() { return c::sgPhysicsBodyGetVelY(handle); }

            void setAngVelRads(float rads) { c::sgPhysicsBodySetAngVelRads(handle, rads); }
            float getAngVelRads() { return c::sgPhysicsBodyGetAngVelRads(handle); }
            void setAngVelDegs(float degs) { c::sgPhysicsBodySetAngVelDegs(handle, degs); }
            float getAngVelDegs() { return c::sgPhysicsBodyGetAngVelDegs(handle); }

            void setMass(float mass) { c::sgPhysicsBodySetMass(handle, mass); }
            float getMass() { return c::sgPhysicsBodyGetMass(handle); }

            void setMoment(float moment) { c::sgPhysicsBodySetMoment(handle, moment); }
            float getMoment() { return c::sgPhysicsBodyGetMoment(handle); }

            void setForce(float x, float y) { c::sgPhysicsBodySetForce(handle, x, y); }
            void getForce(float* x, float* y) { c::sgPhysicsBodyGetForce(handle, x, y); }
            void getForce(float& x, float& y) { c::sgPhysicsBodyGetForce(handle, &x, &y); }

            void setForceX(float x) { c::sgPhysicsBodySetForceX(handle, x); }
            float getForceX() { return c::sgPhysicsBodyGetForceX(handle); }
            void setForceY(float y) { c::sgPhysicsBodySetForceY(handle, y); }
            float getForceY() { return c::sgPhysicsBodyGetForceY(handle); }

            void setTorque(float torque) { c::sgPhysicsBodySetTorque(handle, torque); }
            float getTorque() { return c::sgPhysicsBodyGetTorque(handle); }

            void applyImpulse(float jx, float jy, float rx, float ry) { c::sgPhysicsBodyApplyImpulse(handle, jx, jy, rx, ry); }
            void applyForce(float jx, float jy, float rx, float ry) { c::sgPhysicsBodyApplyForce(handle, jx, jy, rx, ry); }

            void worldToLocal(float* xo, float* yo, float x, float y) { c::sgPhysicsBodyWorldToLocal(handle, xo, yo, x, y); }
            void worldToLocal(float& xo, float& yo, float x, float y) { c::sgPhysicsBodyWorldToLocal(handle, &xo, &yo, x, y); }
            void worldToLocal(float* x, float* y) { worldToLocal(x, y, *x, *y); }
            void worldToLocal(float& x, float& y) { worldToLocal(x, y, x, y); }

            void localToWorld(float* xo, float* yo, float x, float y) { c::sgPhysicsBodyLocalToWorld(handle, xo, yo, x, y); }
            void localToWorld(float& xo, float& yo, float x, float y) { c::sgPhysicsBodyLocalToWorld(handle, &xo, &yo, x, y); }
            void localToWorld(float* x, float* y) { localToWorld(x, y, *x, *y); }
            void localToWorld(float& x, float& y) { localToWorld(x, y, x, y); }
        } ;
        RTYPE(Body);
    }
}

#endif // __CPP_SIEGE_PHYSICS_BODY_H__
