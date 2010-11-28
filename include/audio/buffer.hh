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
			void create(const char* fname);

		public:
			Buffer(const char* fname);
			Buffer(char* fname);
			~Buffer();

			void setData(siege::c::SGuint channels, siege::c::SGuint format, siege::c::SGuint frequency, void* data, siege::c::SGuint datalen);
		} ;
	}
}

#endif // __CPP_SIEGE_AUDIO_BUFFER_H__
