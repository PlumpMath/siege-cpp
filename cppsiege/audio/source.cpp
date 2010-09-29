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

        bool Source::isActive()
        {
            return sgAudioSourceIsActive(handle);
        }
    }
}
