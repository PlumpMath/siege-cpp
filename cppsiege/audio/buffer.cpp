#include "buffer.hh"

using namespace siege::c;

namespace siege
{
    namespace audio
    {
        void Buffer::create(char* fname)
        {
            handle = sgAudioBufferCreate(fname);
        }

        Buffer::Buffer(char* fname)
        {
            create(fname);
        }
        Buffer::~Buffer()
        {
            sgAudioBufferDestroy(handle);
        }

        void Buffer::setData(SGuint channels, SGuint format, SGuint frequency, void* data, SGuint datalen)
        {
            sgAudioBufferSetData(handle, channels, format, frequency, data, datalen);
        }
    }
}
