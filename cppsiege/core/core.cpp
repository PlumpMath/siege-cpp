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

#include "core.hh"

using namespace std;
using namespace siege::c;
namespace siege
{
    namespace core
    {
        SGuint loadModulesv(int n, va_list args)
        {
            return sgLoadModulesv(n, args);
        }
        SGuint loadModules(int n, ...)
        {
            va_list args;
            va_start(args, n);
            SGuint ret = sgLoadModulesv(n, args);
            va_end(args);
            return ret;
        }
        SGbool loadModule(char* module)
        {
            return sgLoadModule(module);
        }
        SGbool init(SGuint width, SGuint height, SGuint bpp, SGuint flags)
        {
            return sgInit(width, height, bpp, flags);
        }
        SGbool deinit()
        {
            return sgDeinit();
        }

        SGint run()
        {
            return sgRun();
        }
        SGbool loop(SGint* code)
        {
            return sgLoop(code);
        }
        void stop(SGint ret)
        {
            sgStop(ret);
        }
    }
}
