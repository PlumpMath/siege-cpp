/*
 * Copyright (c) 2007 SIEGE Development Team
 * All rights reserved.
 *
 * This file is part of libSIEGE.
 *
 * This software is copyrighted work licensed under the terms of the
 * 2-clause BSD license. Please consult the file "license.txt" for
 * details.
 *
 * If you did not recieve the file with this program, please email
 * Tim Chas <darkuranium@gmail.com>.
 */

#ifndef __CPP_SIEGE_COMMON_H__
#define __CPP_SIEGE_COMMON_H__

#include <cstddef>
#include <cstdarg>

#ifdef CPPSG_REFCOUNT
#define SGREF(T) Ref<T>
#else
#define SGREF(T) T*
#endif

#define RTYPE(type) typedef SGREF(type) P##type

namespace siege
{
    namespace c
    {
        #include <siege/siege.h>
    }

    template<typename T>
    class Ref
    {
        size_t* count;
        T* val;
        void _incref() { if(count) ++(*count); }
        void _decref() { if(count) { --(*count); if(!*count) delete val; } }
    public:
        Ref(): count(NULL), val(NULL) {}
        Ref(T* valv): count(valv ? (new size_t(1)) : NULL), val(valv) {}
        Ref(const Ref& r): count(r.count), val(r.val) { _incref(); }
        ~Ref() { _decref(); }

        Ref& operator=(Ref& r)
        {
            if(val == r.val)
                return *this;
            _decref();
            count = r.count;
            val = r.val;
            _incref();
            return *this;
        }

        operator bool() const { return val != NULL; }
        const bool operator!() const { return !val; }
        const bool operator==(const Ref& r) const { return val == r.val; }
        const bool operator!=(const Ref& r) const { return val != r.val; }

        T& operator*() { return *val; }
        const T& operator*() const { return *val; }
        T* operator->() { return val; }
        const T* operator->() const { return val; }

        size_t getCount() const { return count ? *count : 0; }
    } ;

    template<typename T>
    class SGClass
    {
    protected:
        T* handle;
    public:
        SGClass(): handle(NULL) {}
        virtual ~SGClass() {}
        T* getHandle() const { return handle; }
    };
}

#endif // __CPP_SIEGE_COMMON_H__
