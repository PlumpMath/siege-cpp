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

#ifndef __CPP_SIEGE_AUDIO_SOURCE_H__
#define __CPP_SIEGE_AUDIO_SOURCE_H__

#include "../common.hh"

namespace siege
{
    namespace audio
    {
        /// \todo overload
        class Source
        {
            friend class Buffer;
        private:
            siege::c::SGAudioSource* handle;
            void create(class Buffer* buffer, float priority, float volume, float pitch, bool looping);

        public:
            Source(class Buffer* buffer, float priority, float volume, float pitch, bool looping);
            Source(class Buffer* buffer, float priority, float volume, float pitch);
            Source(class Buffer* buffer, float priority, float volume, bool looping);
            Source(class Buffer* buffer, float priority, float volume);
            Source(class Buffer* buffer, float priority, bool looping);
            Source(class Buffer* buffer, float priority);
            Source(class Buffer* buffer, bool looping);
            Source(class Buffer* buffer);
            Source(float priority, float volume, float pitch, bool looping);
            Source(float priority, float volume, float pitch);
            Source(float priority, float volume, bool looping);
            Source(float priority, float volume);
            Source(float priority, bool looping);
            Source(float priority);
            Source(bool looping);
            Source();
            ~Source();

            void play();

            bool isActive();
        } ;
    }
}

#endif // __CPP_SIEGE_AUDIO_SOURCE_H__
