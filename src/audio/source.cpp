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

#include "source.hh"
#include "buffer.hh"

using namespace siege::c;

namespace siege
{
	namespace audio
	{
		void Source::create(class Buffer* buffer, float priority, float volume, float pitch, bool looping)
		{
			handle = sgAudioSourceCreate(buffer->handle, priority, volume, pitch, looping);
		}

		Source::Source(class Buffer* buffer, float priority, float volume, float pitch, bool looping)
		{
			create(buffer, priority, volume, pitch, looping);
		}
		Source::Source(class Buffer* buffer, float priority, float volume, float pitch)
		{
			create(buffer, priority, volume, pitch, false);
		}
		Source::Source(class Buffer* buffer, float priority, float volume, bool looping)
		{
			create(buffer, priority, volume, 1.0, looping);
		}
		Source::Source(class Buffer* buffer, float priority, float volume)
		{
			create(buffer, priority, volume, 1.0, false);
		}
		Source::Source(class Buffer* buffer, float priority, bool looping)
		{
			create(buffer, priority, 1.0, 1.0, looping);
		}
		Source::Source(class Buffer* buffer, float priority)
		{
			create(buffer, priority, 1.0, 1.0, false);
		}
		Source::Source(class Buffer* buffer, bool looping)
		{
			create(buffer, 0.0, 1.0, 1.0, looping);
		}
		Source::Source(class Buffer* buffer)
		{
			create(buffer, 0.0, 1.0, 1.0, false);
		}
		Source::Source(float priority, float volume, float pitch, bool looping)
		{
			create(NULL, priority, volume, pitch, looping);
		}
		Source::Source(float priority, float volume, float pitch)
		{
			create(NULL, priority, volume, pitch, false);
		}
		Source::Source(float priority, float volume, bool looping)
		{
			create(NULL, priority, volume, 1.0, looping);
		}
		Source::Source(float priority, float volume)
		{
			create(NULL, priority, volume, 1.0, false);
		}
		Source::Source(float priority, bool looping)
		{
			create(NULL, priority, 1.0, 1.0, looping);
		}
		Source::Source(float priority)
		{
			create(NULL, priority, 1.0, 1.0, false);
		}
		Source::Source(bool looping)
		{
			create(NULL, 0.0, 1.0, 1.0, looping);
		}
		Source::Source()
		{
			create(NULL, 0.0, 1.0, 1.0, false);
		}
		Source::~Source()
		{
			sgAudioSourceDestroy(handle);
		}

		void Source::play()
		{
			sgAudioSourcePlay(handle);
		}
		bool Source::isPlaying()
		{
			return sgAudioSourceIsPlaying(handle);
		}

		void Source::pause()
		{
			sgAudioSourcePause(handle);
		}
		bool Source::isPaused()
		{
			return sgAudioSourceIsPaused(handle);
		}

		void Source::stop()
		{
			sgAudioSourceStop(handle);
		}
		bool Source::isStopped()
		{
			return sgAudioSourceIsStopped(handle);
		}

		bool Source::isActive()
		{
			return sgAudioSourceIsActive(handle);
		}

		void Source::queueBuffers(class Buffer** buffers, SGuint numbuffers)
		{
			SGuint i;
			SGAudioBuffer** cbufs = new SGAudioBuffer*[numbuffers];
			for(i = 0; i < numbuffers; i++)
				cbufs[i] = buffers[i]->handle;
			sgAudioSourceQueueBuffers(handle, cbufs, numbuffers);
			delete[] cbufs;
		}
		void Source::queueBuffer(class Buffer* buffer)
		{
			sgAudioSourceQueueBuffer(handle, buffer->handle);
        }

		void Source::setPosition(float x, float y, float z)
		{
			sgAudioSourceSetPosition3f(handle, x, y, z);
		}
		void Source::setPosition(float x, float y)
		{
			sgAudioSourceSetPosition2f(handle, x, y);
		}

		void Source::getPosition(float* x, float* y, float* z)
		{
			sgAudioSourceGetPosition3f(handle, x, y, z);
		}
		void Source::getPosition(float& x, float& y, float& z)
		{
			sgAudioSourceGetPosition3f(handle, &x, &y, &z);
		}
		void Source::getPosition(float* x, float* y)
		{
			sgAudioSourceGetPosition2f(handle, x, y);
		}
		void Source::getPosition(float& x, float& y)
		{
			sgAudioSourceGetPosition2f(handle, &x, &y);
		}

		void Source::setVelocity(float x, float y, float z)
		{
			sgAudioSourceSetVelocity3f(handle, x, y, z);
		}
		void Source::setVelocity(float x, float y)
		{
			sgAudioSourceSetVelocity2f(handle, x, y);
		}

		void Source::getVelocity(float* x, float* y, float* z)
		{
			sgAudioSourceGetVelocity3f(handle, x, y, z);
		}
		void Source::getVelocity(float& x, float& y, float& z)
		{
			sgAudioSourceGetVelocity3f(handle, &x, &y, &z);
		}
		void Source::getVelocity(float* x, float* y)
		{
			sgAudioSourceGetVelocity2f(handle, x, y);
		}
		void Source::getVelocity(float& x, float& y)
		{
			sgAudioSourceGetVelocity2f(handle, &x, &y);
		}

		/*void Source::setFalloff(float falloff)
		{
			sgAudioSourceSetFalloff(handle, falloff);
		}
		float Source::getFalloff()
		{
			return sgAudioSourceGetFalloff(handle);
		}*/

		void Source::setPitch(float pitch)
		{
			sgAudioSourceSetPitch(handle, pitch);
		}
		float Source::getPitch()
		{
			return sgAudioSourceGetPitch(handle);
		}


		void Source::setVolume(float volume)
		{
			sgAudioSourceSetVolume(handle, volume);
		}
		float Source::getVolume()
		{
			return sgAudioSourceGetVolume(handle);
		}

		void Source::setLooping(bool looping)
		{
			sgAudioSourceSetLooping(handle, looping);
		}
		bool Source::getLooping()
		{
			return sgAudioSourceGetLooping(handle);
		}
	}
}
