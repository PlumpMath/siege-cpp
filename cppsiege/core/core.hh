#ifndef __CPP_SIEGE_CORE_H__
#define __CPP_SIEGE_CORE_H__

#include "../common.hh"

namespace siege
{
    namespace core
    {
        /// \todo overload for strings and vectors
        siege::c::SGuint loadModules(char** modules);
        siege::c::SGbool loadModule(char* module);
        siege::c::SGbool init(siege::c::SGuint width, siege::c::SGuint height, siege::c::SGuint bpp, siege::c::SGuint flags);
        siege::c::SGbool deinit();

        siege::c::SGint run();
        siege::c::SGbool loop(siege::c::SGint* code = NULL);
        void stop(siege::c::SGint ret = 0);
    }
}

#endif // __CPP_SIEGE_CORE_H__
