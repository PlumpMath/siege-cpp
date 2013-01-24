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

#ifndef __CPP_SIEGE_CORE_H__
#define __CPP_SIEGE_CORE_H__

#include "../common.hh"

namespace siege
{
    namespace core
    {
        inline void getVersionv(c::SGushort* version) { c::sgGetVersionv(version); }
        inline void getVersion(c::SGushort* vmajor, c::SGushort* vminor, c::SGushort* vpatch) { c::sgGetVersion(vmajor, vminor, vpatch); }
        inline void getVersion(c::SGushort& vmajor, c::SGushort& vminor, c::SGushort& vpatch) { c::sgGetVersion(&vmajor, &vminor, &vpatch); }
        inline char* getVersionString() { return c::sgGetVersionString(); }

        inline c::SGuint loadModulesv(std::size_t n, std::va_list args) { return c::sgLoadModulesv(n, args); }
        inline c::SGuint loadModules(std::size_t n, ...)
        {
            std::va_list args;
            va_start(args, n);
            c::SGuint ret = c::sgLoadModulesv(n, args);
            va_end(args);
            return ret;
        }
        inline c::SGbool loadModule(const char* module) { return c::sgLoadModule(module); }
        inline c::SGbool init(c::SGenum flags) { return c::sgInit(flags); }
        inline c::SGbool deinit() { return c::sgDeinit(); }

        inline c::SGint run() { return c::sgRun(); }
        inline bool loop(c::SGint* code = NULL) { return c::sgLoop(code); }
        inline bool loop(c::SGint& code) { return c::sgLoop(&code); }
        inline void stop(c::SGint ret) { c::sgStop(ret); }

        inline c::SGulong getTick() { return c::sgGetTick(); }
    }
}

#endif // __CPP_SIEGE_CORE_H__
