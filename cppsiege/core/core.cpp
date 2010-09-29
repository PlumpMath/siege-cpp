#include "core.hh"

using namespace siege::c;
namespace siege
{
    namespace core
    {
        SGuint loadModules(char** modules)
        {
            return sgLoadModules(modules);
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
