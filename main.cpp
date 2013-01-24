#include <cstdio>

#include <siege-cpp>

#include <cmath>

using namespace siege;
using namespace core;
using namespace type;
using namespace graphics;
using namespace input;

using namespace std;

class Box: public Entity
{
public:
    Box(PSprite sprite, float x, float y, float angle = 0.0): Entity()
    {
        setSprite(sprite);
        setPos(x, y);
        setAngleDegs(angle);
    }

    void evMouseMove(SGint x, SGint y)
    {
        setPos(x, y);
    }
} ;
RTYPE(Box);

int main()
{
    core::loadModule("SDL");
    core::loadModule("OpenGL");
    core::loadModule("DevIL");

    core::init(0);
    window::open(640, 480, 32, 0);

    PSprite sprBox = new Sprite("data/sprites/CrateSmall.png");

    PBox box = new Box(sprBox, 320, 240);
    (void)box;

    for(;;)
    {
        draw::clear();
        if(!core::loop())
            break;

        draw::triangle(0, 0, 320, 240, 0, 240, true);

        PTurtle turtle = new Turtle(320, 240);
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

        window::swapBuffers();
    }

    core::deinit();
    return 0;
}
