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

#ifndef __CPP_SIEGE_CORE_ENTITY_H__
#define __CPP_SIEGE_CORE_ENTITY_H__

#include "../common.hh"
#include "../graphics/sprite.hh"

#define ENT(cent) ((Entity*)(cent)->data)
#define BIND(name) handle->name = c_##name;

namespace siege
{
    namespace core
    {
        class Entity: public SGClass<c::SGEntity>
        {
        private:
            static c::SGbool SG_CALL c_cbInside(c::SGEntity* entity, float x, float y) { return ENT(entity)->cbInside(x, y); }

            static void SG_CALL c_lcDestroy(c::SGEntity* entity) { ENT(entity)->lcDestroy(); }

            static void SG_CALL c_evInit(c::SGEntity* entity) { ENT(entity)->evInit(); }
            static void SG_CALL c_evDeinit(c::SGEntity* entity) { ENT(entity)->evDeinit(); }

            static void SG_CALL c_evStart(c::SGEntity* entity) { ENT(entity)->evStart(); }
            static void SG_CALL c_evExit(c::SGEntity* entity) { ENT(entity)->evExit(); }

            static void SG_CALL c_evTick(c::SGEntity* entity) { ENT(entity)->evTick(); }
            static void SG_CALL c_evTickBegin(c::SGEntity* entity) { ENT(entity)->evTickBegin(); }
            static void SG_CALL c_evTickEnd(c::SGEntity* entity) { ENT(entity)->evTickEnd(); }
            static void SG_CALL c_evDraw(c::SGEntity* entity) { ENT(entity)->evDraw(); }

            static void SG_CALL c_evWindowOpen(c::SGEntity* entity) { ENT(entity)->evWindowOpen(); }
            static void SG_CALL c_evWindowClose(c::SGEntity* entity) { ENT(entity)->evWindowClose(); }
            static void SG_CALL c_evWindowResize(c::SGEntity* entity, c::SGuint width, c::SGuint height) { ENT(entity)->evWindowResize(width, height); }

            static void SG_CALL c_evMouseButton(c::SGEntity* entity, c::SGuint button) { ENT(entity)->evMouseButton(button); }
            static void SG_CALL c_evMouseButtonPress(c::SGEntity* entity, c::SGuint button) { ENT(entity)->evMouseButtonPress(button); }
            static void SG_CALL c_evMouseButtonRelease(c::SGEntity* entity, c::SGuint button) { ENT(entity)->evMouseButtonRelease(button); }

            static void SG_CALL c_evMouseButtonLeft(c::SGEntity* entity) { ENT(entity)->evMouseButtonLeft(); }
            static void SG_CALL c_evMouseButtonLeftPress(c::SGEntity* entity) { ENT(entity)->evMouseButtonLeftPress(); }
            static void SG_CALL c_evMouseButtonLeftRelease(c::SGEntity* entity) { ENT(entity)->evMouseButtonLeftRelease(); }

            static void SG_CALL c_evMouseButtonRight(c::SGEntity* entity) { ENT(entity)->evMouseButtonRight(); }
            static void SG_CALL c_evMouseButtonRightPress(c::SGEntity* entity) { ENT(entity)->evMouseButtonRightPress(); }
            static void SG_CALL c_evMouseButtonRightRelease(c::SGEntity* entity) { ENT(entity)->evMouseButtonRightRelease(); }

            static void SG_CALL c_evMouseButtonMiddle(c::SGEntity* entity) { ENT(entity)->evMouseButtonMiddle(); }
            static void SG_CALL c_evMouseButtonMiddlePress(c::SGEntity* entity) { ENT(entity)->evMouseButtonMiddlePress(); }
            static void SG_CALL c_evMouseButtonMiddleRelease(c::SGEntity* entity) { ENT(entity)->evMouseButtonMiddleRelease(); }

            static void SG_CALL c_evMouseMove(c::SGEntity* entity, c::SGint x, c::SGint y) { ENT(entity)->evMouseMove(x, y); }
            static void SG_CALL c_evMouseWheel(c::SGEntity* entity, c::SGint wheel) { ENT(entity)->evMouseWheel(wheel); }

            static void SG_CALL c_evKeyboardKey(c::SGEntity* entity, c::SGuint key) { ENT(entity)->evKeyboardKey(key); }
            static void SG_CALL c_evKeyboardKeyPress(c::SGEntity* entity, c::SGuint key) { ENT(entity)->evKeyboardKeyPress(key); }
            static void SG_CALL c_evKeyboardKeyRelease(c::SGEntity* entity, c::SGuint key) { ENT(entity)->evKeyboardKeyRelease(key); }
            static void SG_CALL c_evKeyboardKeyRepeat(c::SGEntity* entity, c::SGuint key) { ENT(entity)->evKeyboardKeyRepeat(key); }

            static void SG_CALL c_evKeyboardCharPress(c::SGEntity* entity, c::SGdchar chr) { ENT(entity)->evKeyboardCharPress(chr); }

            static void SG_CALL c_evJoystickButton(c::SGEntity* entity, c::SGuint joy, c::SGuint button) { ENT(entity)->evJoystickButton(joy, button); }
            static void SG_CALL c_evJoystickButtonPress(c::SGEntity* entity, c::SGuint joy, c::SGuint button) { ENT(entity)->evJoystickButtonPress(joy, button); }
            static void SG_CALL c_evJoystickButtonRelease(c::SGEntity* entity, c::SGuint joy, c::SGuint button) { ENT(entity)->evJoystickButtonRelease(joy, button); }
            static void SG_CALL c_evJoystickMove(c::SGEntity* entity, c::SGuint joy, float* axis, size_t numaxis) { ENT(entity)->evJoystickMove(joy, axis, numaxis); }

            // networking goes here

            static void SG_CALL c_evLevelStart(c::SGEntity* entity) { ENT(entity)->evLevelStart(); }
            static void SG_CALL c_evLevelEnd(c::SGEntity* entity) { ENT(entity)->evLevelEnd(); }

            static void SG_CALL c_evUser(c::SGEntity* entity, c::SGuint id, va_list args) { ENT(entity)->evUser(id, args); }

            graphics::PSprite sprite;
            void create()
            {
                handle = c::sgEntityCreate();
                handle->data = this;

                BIND(cbInside);

                BIND(lcDestroy);

                BIND(evInit);
                BIND(evDeinit);

                BIND(evStart);
                BIND(evExit);

                BIND(evTick);
                BIND(evTickBegin);
                BIND(evTickEnd);
                BIND(evDraw);

                BIND(evWindowOpen);
                BIND(evWindowClose);
                BIND(evWindowResize);

                BIND(evMouseButton);
                BIND(evMouseButtonPress);
                BIND(evMouseButtonRelease);

                BIND(evMouseButtonLeft);
                BIND(evMouseButtonLeftPress);
                BIND(evMouseButtonLeftRelease);

                BIND(evMouseButtonRight);
                BIND(evMouseButtonRightPress);
                BIND(evMouseButtonRightRelease);

                BIND(evMouseButtonMiddle);
                BIND(evMouseButtonMiddlePress);
                BIND(evMouseButtonMiddleRelease);

                BIND(evMouseMove);
                BIND(evMouseWheel);

                BIND(evKeyboardKey);
                BIND(evKeyboardKeyPress);
                BIND(evKeyboardKeyRelease);
                BIND(evKeyboardKeyRepeat);

                BIND(evKeyboardCharPress);

                BIND(evJoystickButton);
                BIND(evJoystickButtonPress);
                BIND(evJoystickButtonRelease);
                BIND(evJoystickMove);

                // networking goes here

                BIND(evLevelStart);
                BIND(evLevelEnd);

                BIND(evUser);
            }
        public:
            static void destroyAll() { c::sgEntityDestroyAll(); }
            /*SGList* SG_EXPORT sgEntityFind(const char* name);

            void SG_EXPORT sgEntityEventSignalv(size_t num, va_list args);
            void SG_EXPORT sgEntityEventSignal(size_t num, ...);
            void SG_EXPORT sgEntityEventStop(void);*/

            Entity(): sprite() { create(); }
            virtual ~Entity() { if(handle) c::sgEntityDestroy(handle); }

            virtual void destroy() { c::sgEntityDestroy(handle); handle = NULL; }

            void setName(const char* name) { c::sgEntitySetName(handle, name); }
            char* getName() { return c::sgEntityGetName(handle); }

            void setSprite(graphics::PSprite sprite) { c::sgEntitySetSprite(handle, sprite->getHandle()); this->sprite = sprite; }
            graphics::PSprite getSprite() { return this->sprite; }

            //void SG_EXPORT sgEntitySetMask(SGEntity* entity, struct SGMask* mask);
            //struct SGMask* SG_EXPORT sgEntityGetMask(SGEntity* entity);

            //void SG_EXPORT sgEntitySetPhysicsBody(SGEntity* entity, struct SGPhysicsBody* body);
            //struct SGPhysicsBody* SG_EXPORT sgEntityGetPhysicsBody(SGEntity* entity);

            //void SG_EXPORT sgEntitySetAudioSource(SGEntity* entity, struct SGAudioSource* source);
            //struct SGAudioSource* SG_EXPORT sgEntityGetAudioSource(SGEntity* entity);

            void setPos(float x, float y) { c::sgEntitySetPos(handle, x, y); }
            void setPosX(float x) { c::sgEntitySetPosX(handle, x); }
            void setPosY(float y) { c::sgEntitySetPosY(handle, y); }
            void getPos(float* x, float* y) { c::sgEntityGetPos(handle, x, y); }
            void getPos(float& x, float& y) { c::sgEntityGetPos(handle, &x, &y); }
            float getPosX() { return c::sgEntityGetPosX(handle); }
            float getPosY() { return c::sgEntityGetPosY(handle); }

            void setDepth(float depth) { c::sgEntitySetDepth(handle, depth); }
            float getDepth() { return c::sgEntityGetDepth(handle); }

            void setAngleRads(float rads) { c::sgEntitySetAngleRads(handle, rads); }
            float getAngleRads() { return c::sgEntityGetAngleRads(handle); }

            void setAngleDegs(float degs) { c::sgEntitySetAngleDegs(handle, degs); }
            float getAngleDegs() { return c::sgEntityGetAngleDegs(handle); }

            virtual void draw() { c::sgEntityDraw(handle); }

            /*void SG_EXPORT (*lcCollision)(struct SGEntity* entity, struct SGEntity* other, struct SGPhysicsCollision* coll);
            void SG_EXPORT (*lcCollisionOne)(struct SGEntity* entity, struct SGEntity* other, struct SGPhysicsCollision* coll);
            void SG_EXPORT (*lcCollisionTwo)(struct SGEntity* entity, struct SGEntity* other, struct SGPhysicsCollision* coll);

            void SG_EXPORT (*lcCollisionBegin)(struct SGEntity* entity, struct SGEntity* other, struct SGPhysicsCollision* coll);
            void SG_EXPORT (*lcCollisionOneBegin)(struct SGEntity* entity, struct SGEntity* other, struct SGPhysicsCollision* coll);
            void SG_EXPORT (*lcCollisionTwoBegin)(struct SGEntity* entity, struct SGEntity* other, struct SGPhysicsCollision* coll);

            void SG_EXPORT (*lcCollisionEnd)(struct SGEntity* entity, struct SGEntity* other, struct SGPhysicsCollision* coll);
            void SG_EXPORT (*lcCollisionOneEnd)(struct SGEntity* entity, struct SGEntity* other, struct SGPhysicsCollision* coll);
            void SG_EXPORT (*lcCollisionTwoEnd)(struct SGEntity* entity, struct SGEntity* other, struct SGPhysicsCollision* coll);*/

            virtual bool cbInside(float x, float y) { return false; }

            virtual void lcDestroy() {}

            virtual void evInit() {}
            virtual void evDeinit() {}

            virtual void evStart() {}
            virtual void evExit() {}

            virtual void evTick() {}
            virtual void evTickBegin() {}
            virtual void evTickEnd() {}
            virtual void evDraw() { if(handle->visible) draw(); }

            virtual void evWindowOpen() {}
            virtual void evWindowClose() {}
            virtual void evWindowResize(c::SGuint width, c::SGuint height) {}

            virtual void evMouseButton(c::SGuint button) {}
            virtual void evMouseButtonPress(c::SGuint button) {}
            virtual void evMouseButtonRelease(c::SGuint button) {}

            virtual void evMouseButtonLeft() {}
            virtual void evMouseButtonLeftPress() {}
            virtual void evMouseButtonLeftRelease() {}

            virtual void evMouseButtonRight() {}
            virtual void evMouseButtonRightPress() {}
            virtual void evMouseButtonRightRelease() {}

            virtual void evMouseButtonMiddle() {}
            virtual void evMouseButtonMiddlePress() {}
            virtual void evMouseButtonMiddleRelease() {}

            virtual void evMouseMove(c::SGint x, c::SGint y) {}
            virtual void evMouseWheel(c::SGint wheel) {}

            virtual void evKeyboardKey(c::SGuint key) {}
            virtual void evKeyboardKeyPress(c::SGuint key) {}
            virtual void evKeyboardKeyRelease(c::SGuint key) {}
            virtual void evKeyboardKeyRepeat(c::SGuint key) {}

            virtual void evKeyboardCharPress(c::SGdchar chr) {}

            virtual void evJoystickButton(c::SGuint joy, c::SGuint button) {}
            virtual void evJoystickButtonPress(c::SGuint joy, c::SGuint button) {}
            virtual void evJoystickButtonRelease(c::SGuint joy, c::SGuint button) {}
            virtual void evJoystickMove(c::SGuint joy, float* axis, size_t numaxis) {}

            // networking goes here

            virtual void evLevelStart() {}
            virtual void evLevelEnd() {}

            virtual void evUser(c::SGuint id, va_list args) {}
        } ;
        RTYPE(Entity);
    }
}

#undef BIND

#endif // __CPP_SIEGE_CORE_ENTITY_H__
