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

#include "buffer.hh"

using namespace siege::c;

namespace siege
{
	namespace audio
	{
		void Buffer::create(const char* fname)
		{
			handle = sgAudioBufferCreate(fname);
		}

		Buffer::Buffer(const char* fname)
		{
			create(fname);
		}
		Buffer::Buffer(char* fname)
		{
			create((const char*)fname);
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
