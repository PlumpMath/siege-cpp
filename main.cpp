#include <cmath>

#include <siege.hh>

using namespace siege;
using namespace core;
using namespace type;
using namespace graphics;
using namespace input;

int main()
{
    core::loadModule("SDL");
    core::loadModule("OpenGL");

    core::init(640, 480, 32, 0);

    while(core::loop())
    {
        draw::clear();

        draw::triangle(0, 0, 320, 240, 0, 240, true);

        Turtle* turtle = new Turtle(320, 240);
        turtle->penUp();
        turtle->step(100);
        turtle->turnLeftDegs(90);
        turtle->penDown();
        int segs = 32;
        int i;
        for(i = 0; i < segs; i++)
        {
            turtle->step(2 * M_PI * 100 / (float)segs / 2);
            turtle->turnLeftDegs(360 / (float)segs);
            turtle->step(2 * M_PI * 100 / (float)segs / 2);
        }
        delete turtle;

        window::swapBuffers();
    }

    core::deinit();
    return 0;
}
