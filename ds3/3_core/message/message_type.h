//
// The MIT License(MIT)
//
// Copyright(c) 2014 Demonsaw LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _EJA_MESSAGE_TYPE_H_
#define _EJA_MESSAGE_TYPE_H_

#include <list>

#include "system/type.h"

// fatal error C1189: #error:  WinSock.h has already been included
#include <msgpack.hpp>

namespace eja
{
	// Macro
	#define make_message_type(T)									\
	T,																\
	T ## _request,													\
	T ## _response,													\
	T ## _callback,													\
	T ## _unused													\

	// Using
	enum class message_type;
	using message_type_list = std::list<message_type>;

	// Type
	enum class message_type
	{
		none,
		padding = 9,

		make_message_type(browse),
		make_message_type(chat),
		make_message_type(client),
		make_message_type(download),
		make_message_type(file),
		make_message_type(group),
		make_message_type(handshake),
		make_message_type(join),		
		make_message_type(ping),		
		make_message_type(quit),
		make_message_type(router),
		make_message_type(search),
		make_message_type(session),
		make_message_type(socket),
		make_message_type(tunnel),
		make_message_type(upload)
	};
}

MSGPACK_ADD_ENUM(eja::message_type);

#endif
