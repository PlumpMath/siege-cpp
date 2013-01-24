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

#ifndef __CPP_SIEGE_AUDIO_BUFFER_H__
#define __CPP_SIEGE_AUDIO_BUFFER_H__

#include "../common.hh"

namespace siege
{
    namespace audio
    {
        /// \todo overload
        class Buffer
        {
            friend class Source;
        private:
            c::SGAudioBuffer* handle;
            void create(const char* fname)
            {
                handle = c::sgAudioBufferCreateFile(fname);
            }

        public:
            Buffer(const char* fname)
            {
                create(fname);
            }
            ~Buffer()
            {
                c::sgAudioBufferDestroy(handle);
            }

            void setData(c::SGuint channels, c::SGenum format, c::SGenum frequency, void* data, std::size_t datalen)
            {
                c::sgAudioBufferSetData(handle, channels, format, frequency, data, datalen);
            }
        } ;
        RTYPE(Buffer);
    }
}

#endif // __CPP_SIEGE_AUDIO_BUFFER_H__
