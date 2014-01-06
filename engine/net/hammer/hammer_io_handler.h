// Copyright (C) 2012 by wubenqi
// Distributable under the terms of either the Apache License (Version 2.0) or 
// the GNU Lesser General Public License, as specified in the COPYING file.
//
// By: wubenqi<wubenqi@gmail.com>
//

#ifndef NET_HAMMER_HAMMER_IO_HANDLER_H_
#define NET_HAMMER_HAMMER_IO_HANDLER_H_
#pragma once

#include "net/base/packet.h"
#include "net/engine/io_handler.h"
#include "net/hammer/hammer_packet_header.h"
#include "net/base/data_io_buffer.h"
#include "base/memory/ref_counted.h"

namespace net {

class HammerIOHandler :
	public IOHandler {
public:
	HammerIOHandler(SOCKET socket, Reactor* reactor);
	virtual ~HammerIOHandler();

	virtual int OnDataReceived(const PacketPtr& packet) { return 0; } 

	int SendData(const PacketPtr& packet);
	int SendSyncData(const PacketPtr& packet);

  void AsyncSendPacket(PacketPtr packet);

protected:
	virtual void Read();

private:
  void OnAsyncSendPacket(PacketPtr packet);
	int RecvData(uint8* data, int data_len);

	scoped_refptr<DataIOBuffer> read_buf_;

/*
	uint8*	body_;
	uint8	head_[HammerPacketHeader::kPacketHeaderSize];
	uint32  cur_body_pos_;
	uint32  cur_head_pos_;

	bool	is_header_;
	bool	is_ended_;

	//SouchengIOHandlerDelegate* soucheng_ih_delegate_;
	PacketPtr data_;
 */
};

}

#endif	//
