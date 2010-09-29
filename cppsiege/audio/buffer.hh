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
            siege::c::SGAudioBuffer* handle;
            void create(char* fname);

        public:
            Buffer(char* fname);
            ~Buffer();

            void setData(siege::c::SGuint channels, siege::c::SGuint format, siege::c::SGuint frequency, void* data, siege::c::SGuint datalen);
        } ;
    }
}

#endif // __CPP_SIEGE_AUDIO_BUFFER_H__
