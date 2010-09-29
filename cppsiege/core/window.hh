#ifndef __CPP_SIEGE_CORE_WINDOW_H__
#define __CPP_SIEGE_CORE_WINDOW_H__

#include "../common.hh"

namespace siege
{
    namespace core
    {
        namespace window
        {
            /// \todo overload
            bool open(siege::c::SGuint width, siege::c::SGuint height, siege::c::SGuint bpp, siege::c::SGenum flags);
            bool isOpened();
            void close();

            void setTitleF(char* format, ...);
            void setTitleFV(char* format, va_list args);
            void setTitle(char* title);
            char* getTitle();

            void setSize(siege::c::SGuint width, siege::c::SGuint height);
            void getSize(siege::c::SGuint* width, siege::c::SGuint* height);

            void setWidth(siege::c::SGuint width);
            siege::c::SGuint getWidth();
            void setHeight(siege::c::SGuint height);
            siege::c::SGuint getHeight();

            void swapBuffers();
        }
    }
}


#endif // __CPP_SIEGE_CORE_WINDOW_H__
