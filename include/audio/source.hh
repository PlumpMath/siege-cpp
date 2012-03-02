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

#ifndef __CPP_SIEGE_AUDIO_SOURCE_H__
#define __CPP_SIEGE_AUDIO_SOURCE_H__

#include "../common.hh"
#include "buffer.hh"

namespace siege
{
    namespace audio
    {
        /// \todo overload
        class Source
        {
        private:
            c::SGAudioSource* handle;
            void create(float priority, float volume, float pitch, bool looping)
            {
                handle = c::sgAudioSourceCreate(priority, volume, pitch, looping);
            }

        public:
            Source(float priority, float volume, float pitch, bool looping = false) { create(priority, volume, pitch, looping); }
            Source(float priority, float volume, bool looping = false) { create(priority, volume, 1.0, looping); }
            Source(float priority, bool looping = false) { create(priority, 1.0, 1.0, looping); }
            Source(bool looping = false) { create(0.0, 1.0, 1.0, looping); }
            ~Source() { c::sgAudioSourceDestroy(handle); }

            void play() { c::sgAudioSourcePlay(handle); }
            bool isPlaying() { return c::sgAudioSourceIsPlaying(handle); }

            void pause() { c::sgAudioSourcePause(handle); }
            bool isPaused() { return c::sgAudioSourceIsPaused(handle); }

            void stop() { c::sgAudioSourceStop(handle); }
            bool isStopped() { return c::sgAudioSourceIsStopped(handle); }

            bool isActive() { return c::sgAudioSourceIsActive(handle); }

            void queueBuffers(class Buffer** buffers, size_t numbuffers)
            {
                size_t i;
                c::SGAudioBuffer** cbufs = new c::SGAudioBuffer*[numbuffers];
                for(i = 0; i < numbuffers; i++)
                    cbufs[i] = buffers[i]->handle;
                c::sgAudioSourceQueueBuffers(handle, cbufs, numbuffers);
                delete[] cbufs;
            }
            void queueBuffer(class Buffer* buffer) { c::sgAudioSourceQueueBuffer(handle, buffer->handle); }

            void setPosition(float x, float y, float z) { c::sgAudioSourceSetPosition3f(handle, x, y, z); }
            void setPosition(float x, float y) { c::sgAudioSourceSetPosition2f(handle, x, y); }

            void getPosition(float* x, float* y, float* z) { c::sgAudioSourceGetPosition3f(handle, x, y, z); }
            void getPosition(float& x, float& y, float& z) { c::sgAudioSourceGetPosition3f(handle, &x, &y, &z); }

            void getPosition(float* x, float* y) { c::sgAudioSourceGetPosition2f(handle, x, y); }
            void getPosition(float& x, float& y) { c::sgAudioSourceGetPosition2f(handle, &x, &y); }

            void setVelocity(float x, float y, float z) { c::sgAudioSourceSetVelocity3f(handle, x, y, z); }
            void setVelocity(float x, float y) { c::sgAudioSourceSetVelocity2f(handle, x, y); }

            void getVelocity(float* x, float* y, float* z) { c::sgAudioSourceGetVelocity3f(handle, x, y, z); }
            void getVelocity(float& x, float& y, float& z) { c::sgAudioSourceGetVelocity3f(handle, &x, &y, &z); }
            void getVelocity(float* x, float* y) { c::sgAudioSourceGetVelocity2f(handle, x, y); }
            void getVelocity(float& x, float& y) { c::sgAudioSourceGetVelocity2f(handle, &x, &y); }

            /*void setFalloff(float falloff) { c::sgAudioSourceSetFalloff(handle, falloff); }
            float getFalloff() { return c::sgAudioSourceGetFalloff(handle); }*/

            void setPitch(float pitch) { c::sgAudioSourceSetPitch(handle, pitch); }
            float getPitch() { return c::sgAudioSourceGetPitch(handle); }

            void setVolume(float volume) { c::sgAudioSourceSetVolume(handle, volume); }
            float getVolume() { return c::sgAudioSourceGetVolume(handle); }

            void setLooping(bool looping) { c::sgAudioSourceSetLooping(handle, looping); }
            bool getLooping() { return c::sgAudioSourceGetLooping(handle); }
        } ;
    }
}

#endif // __CPP_SIEGE_AUDIO_SOURCE_H__
