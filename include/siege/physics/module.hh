#ifndef __CPP_SIEGE_PHYSICS_MODULE_H__
#define __CPP_SIEGE_PHYSICS_MODULE_H__

#include "../common.hh"

namespace siege
{
    namespace physics
    {
        bool isAvailable() { return c::sgPhysicsIsAvailable(); }
    }
}

#endif /* __CPP_SIEGE_PHYSICS_MODULE_H__ */
