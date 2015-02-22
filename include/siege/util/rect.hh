#ifndef __CPP_SIEGE_UTIL_RECT_H__
#define __CPP_SIEGE_UTIL_RECT_H__

#include "../common.hh"
#include "vector.hh"

namespace siege
{
    namespace util
    {
        struct Rect: public c::SGRect
        {
            Rect(Vec2 a, Vec2 b) { c::sgRect2fv(a, b); }
            Rect(float x1, float y1, float x2, float y2) { c::sgRect2f(x1, y1, x2, y2); }
            static Rect WH(Vec2 pos, Vec2 size) { return Rect(pos, pos + size); }
            static Rect WH(float x, float y, float w, float h) { return WH(Vec2(x, y), Vec2(w, h)); }

            Rect(const c::SGRect& rect) { a = rect.a; b = rect.b; }

            Vec2 size() const { return Vec2(c::sgRectSize(*this)); }
            Vec2 center() const { return Vec2(c::sgRectCenter(*this)); }
            Rect offset(Vec2 off) const { return Rect(c::sgRectOffset2f(*this, off.x, off.y)); }
            Rect offset(float x, float y) const { return Rect(c::sgRectOffset2f(*this, x, y)); }
        };
    }
}

#endif /* __CPP_SIEGE_UTIL_RECT_H__ */
