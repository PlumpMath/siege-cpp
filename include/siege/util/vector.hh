#ifndef __CPP_SIEGE_UTIL_VECTOR_H__
#define __CPP_SIEGE_UTIL_VECTOR_H__

#include "../common.hh"

namespace siege
{
    namespace util
    {
        struct Vec2: public c::SGVec2
        {
            explicit Vec2(float xy) { x = y = xy; }
            explicit Vec2(const float* xy) { x = xy[0]; y = xy[1]; }
            Vec2(float xv, float yv) { x = xv; y = yv; }

            Vec2(c::SGVec2 v) { x = v.x; y = v.y; }

            static Vec2 polarRads(float rads, float len) { return c::sgVec2PolarRads(rads, len); }
            static Vec2 polarDegs(float degs, float len) { return c::sgVec2PolarDegs(degs, len); }

            static Vec2 nan() { return c::sgVec2Nan(); }

            Vec2 normalize() const { return c::sgVec2Normalize(*this); }

            Vec2 resize(float length) const { return c::sgVec2Resize(*this, length); }
            float length() const { return c::sgVec2Length(*this); }
            float length2() const { return c::sgVec2Length2(*this); }

            Vec2 rotateRads(float rads) const { return c::sgVec2RotateRads(*this, rads); }
            float angleRads() const { return c::sgVec2AngleRads(*this); }
            Vec2 rotateDegs(float degs) const { return c::sgVec2RotateDegs(*this, degs); }
            float angleDegs() const { return c::sgVec2AngleDegs(*this); }

            bool isNan() const { return c::sgVec2IsNan(*this); }

            Vec2 operator+() const { return *this; }
            Vec2 operator-() const { return c::sgVec2Neg(*this); }
            Vec2 operator+(Vec2 o) const { return c::sgVec2Add(*this, o); }
            Vec2 operator-(Vec2 o) const { return c::sgVec2Sub(*this, o); }
            Vec2 operator*(Vec2 o) const { return c::sgVec2Mul(*this, o); }
            Vec2 operator/(Vec2 o) const { return c::sgVec2Div(*this, o); }
            Vec2 operator+(float f) const { return *this + Vec2(f); }
            Vec2 operator-(float f) const { return *this - Vec2(f); }
            Vec2 operator*(float f) const { return *this * Vec2(f); }
            Vec2 operator/(float f) const { return *this / Vec2(f); }

            friend Vec2 operator+(float f, Vec2 v) { return Vec2(f) + v; }
            friend Vec2 operator-(float f, Vec2 v) { return Vec2(f) - v; }
            friend Vec2 operator*(float f, Vec2 v) { return Vec2(f) * v; }
            friend Vec2 operator/(float f, Vec2 v) { return Vec2(f) / v; }

            const bool operator==(Vec2 o) const { return x == o.x && y == o.y; }
            const bool operator!=(Vec2 o) const { return !(*this == o); }

            float distance(Vec2 o) const { return c::sgVec2Distance(*this, o); }
            float distance2(Vec2 o) const { return c::sgVec2Distance2(*this, o); }

            float dot(Vec2 o) const { return c::sgVec2Dot(*this, o); }
            float pdot(Vec2 o) const { return c::sgVec2PDot(*this, o); }
            Vec2 cross() const { return c::sgVec2Cross(*this); }

            Vec2 reflect(Vec2 normal) const { return c::sgVec2Reflect(*this, normal); }
            float projectScalar(Vec2 target) const { return c::sgVec2ProjectScalar(*this, target); }
            Vec2 project(Vec2 target) const { return c::sgVec2Project(*this, target); }
        } ;

        struct Vec3: public c::SGVec3
        {
            explicit Vec3(float xyz) { x = y = z = xyz; }
            explicit Vec3(const float* xyz) { x = xyz[0]; y = xyz[1]; z = xyz[2]; }
            Vec3(float xv, float yv, float zv) { x = xv; y = yv; z = zv; }

            Vec3(c::SGVec3 v) { x = v.x; y = v.y; z = v.z; }
            Vec3(c::SGVec2 a, float b) { x = a.x; y = a.y; z = b; }
            Vec3(float a, c::SGVec2 b) { x = a; y = b.x; z = b.y; }

            static Vec3 cylindricalRads(float rads, float radius, float z) { return c::sgVec3CylindricalRads(rads, radius, z); }
            static Vec3 cylindricalDegs(float degs, float radius, float z) { return c::sgVec3CylindricalDegs(degs, radius, z); }
            static Vec3 sphericalRads(float azimuth, float zenith, float radius) { return c::sgVec3SphericalRads(azimuth, zenith, radius); }
            static Vec3 sphericalDegs(float azimuth, float zenith, float radius) { return c::sgVec3SphericalDegs(azimuth, zenith, radius); }

            static Vec3 nan() { return c::sgVec3Nan(); }

            Vec3 normalize() const { return c::sgVec3Normalize(*this); }

            Vec3 resize(float length) const { return c::sgVec3Resize(*this, length); }
            float length() const { return c::sgVec3Length(*this); }
            float length2() const { return c::sgVec3Length2(*this); }

            bool isNan() const { return c::sgVec3IsNan(*this); }

            Vec3 operator+() const { return *this; }
            Vec3 operator-() const { return c::sgVec3Neg(*this); }
            Vec3 operator+(Vec3 o) const { return c::sgVec3Add(*this, o); }
            Vec3 operator-(Vec3 o) const { return c::sgVec3Sub(*this, o); }
            Vec3 operator*(Vec3 o) const { return c::sgVec3Mul(*this, o); }
            Vec3 operator/(Vec3 o) const { return c::sgVec3Div(*this, o); }
            Vec3 operator+(float f) const { return *this + Vec3(f); }
            Vec3 operator-(float f) const { return *this - Vec3(f); }
            Vec3 operator*(float f) const { return *this * Vec3(f); }
            Vec3 operator/(float f) const { return *this / Vec3(f); }

            friend Vec3 operator+(float f, Vec3 v) { return Vec3(f) + v; }
            friend Vec3 operator-(float f, Vec3 v) { return Vec3(f) - v; }
            friend Vec3 operator*(float f, Vec3 v) { return Vec3(f) * v; }
            friend Vec3 operator/(float f, Vec3 v) { return Vec3(f) / v; }

            const bool operator==(Vec3 o) const { return x == o.x && y == o.y && z == o.z; }
            const bool operator!=(Vec3 o) const { return !(*this == o); }

            float distance(Vec3 o) const { return c::sgVec3Distance(*this, o); }
            float distance2(Vec3 o) const { return c::sgVec3Distance2(*this, o); }

            float dot(Vec3 o) const { return c::sgVec3Dot(*this, o); }
            Vec3 cross(Vec3 o) const { return c::sgVec3Cross(*this, o); }
            float triple(Vec3 b, Vec3 c) const { return c::sgVec3Triple(*this, b, c); }

            Vec3 reflect(Vec3 normal) const { return c::sgVec3Reflect(*this, normal); }
            float projectScalar(Vec3 target) const { return c::sgVec3ProjectScalar(*this, target); }
            Vec3 project(Vec3 target) const { return c::sgVec3Project(*this, target); }
        } ;

        struct Vec4: public c::SGVec4
        {
            explicit Vec4(float xyzw) { x = y = z = w = xyzw; }
            explicit Vec4(const float* xyzw) { x = xyzw[0]; y = xyzw[1]; z = xyzw[2]; w = xyzw[3]; }
            Vec4(float xv, float yv, float zv, float wv) { x = xv; y = yv; z = zv; w = wv; }

            Vec4(c::SGVec4 v) { x = v.x; y = v.y; z = v.z; w = v.w; }
            Vec4(c::SGVec2 a, float b, float c) { x = a.x; y = a.y; z = b; w = c; }
            Vec4(float a, c::SGVec2 b, float c) { x = a; y = b.x; z = b.y; w = c; }
            Vec4(float a, float b, c::SGVec3 c) { x = a; y = b; z = c.x; w = c.y; }
            Vec4(c::SGVec3 a, float b)          { x = a.x; y = a.y; z = a.z; w = b; }
            Vec4(float a, c::SGVec3 b)          { x = a; y = b.x; z = b.y; w = b.z; }

            static Vec4 nan() { return c::sgVec4Nan(); }

            Vec4 normalize() const { return c::sgVec4Normalize(*this); }

            Vec4 resize(float length) const { return c::sgVec4Resize(*this, length); }
            float length() const { return c::sgVec4Length(*this); }
            float length2() const { return c::sgVec4Length2(*this); }

            bool isNan() const { return c::sgVec4IsNan(*this); }

            Vec4 operator+() const { return *this; }
            Vec4 operator-() const { return c::sgVec4Neg(*this); }
            Vec4 operator+(Vec4 o) const { return c::sgVec4Add(*this, o); }
            Vec4 operator-(Vec4 o) const { return c::sgVec4Sub(*this, o); }
            Vec4 operator*(Vec4 o) const { return c::sgVec4Mul(*this, o); }
            Vec4 operator/(Vec4 o) const { return c::sgVec4Div(*this, o); }
            Vec4 operator+(float f) const { return *this + Vec4(f); }
            Vec4 operator-(float f) const { return *this - Vec4(f); }
            Vec4 operator*(float f) const { return *this * Vec4(f); }
            Vec4 operator/(float f) const { return *this / Vec4(f); }

            friend Vec4 operator+(float f, Vec4 v) { return Vec4(f) + v; }
            friend Vec4 operator-(float f, Vec4 v) { return Vec4(f) - v; }
            friend Vec4 operator*(float f, Vec4 v) { return Vec4(f) * v; }
            friend Vec4 operator/(float f, Vec4 v) { return Vec4(f) / v; }

            const bool operator==(Vec4 o) const { return x == o.x && y == o.y && z == o.z; }
            const bool operator!=(Vec4 o) const { return !(*this == o); }

            float distance(Vec4 o) const { return c::sgVec4Distance(*this, o); }
            float distance2(Vec4 o) const { return c::sgVec4Distance2(*this, o); }

            float dot(Vec4 o) const { return c::sgVec4Dot(*this, o); }
            //Vec4 cross(Vec4 b, Vec4 c) const { return c::sgVec4Cross(*this, b, c); }

            Vec4 reflect(Vec4 normal) const { return c::sgVec4Reflect(*this, normal); }
            float projectScalar(Vec4 target) const { return c::sgVec4ProjectScalar(*this, target); }
            Vec4 project(Vec4 target) const { return c::sgVec4Project(*this, target); }
        } ;
    }
}

#endif /* __CPP_SIEGE_UTIL_VECTOR_H__ */
