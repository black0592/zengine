// Copyright (C) 2012 by wubenqi
// Distributable under the terms of either the Apache License (Version 2.0) or 
// the GNU Lesser General Public License, as specified in the COPYING file.
//
// By: wubenqi<wubenqi@gmail.com>
//

#ifndef ZGATED_CLIENT_COMM_HANDLER_H_
#define ZGATED_CLIENT_COMM_HANDLER_H_
#pragma once

#include "base/memory/singleton.h"
#include "base/timer.h"
#include "base/memory/scoped_ptr.h"
#include "base/threading/platform_thread.h"
#include "base/synchronization/lock.h"

#include "net/engine/tcp_acceptor.h"
#include "net/hammer/hammer_io_handler.h"

class ServerCommHandler;
class ClientCommHandler :
  public net::HammerIOHandler {
public:
  enum CommHandlerState {
    kCommHandlerStateInvalid = 0,	  // �Ƿ�
    kCommHandlerStateConnected = 1,	// �Ѿ�����
    kCommHandlerStateNormal = 2,    // ��������

    // ��Ҫ���ж��������رջ��Ǳ����ر�
    kCommHandlerStateClosing = 3,	  // ���ڹر�
    kCommHandlerStateClosed = 4,	  // �Ѿ��ر�
  };

  ClientCommHandler(SOCKET socket, net::Reactor* reactor);
  virtual ~ClientCommHandler();
  void Destroy();

  //////////////////////////////////////////////////////////////////////////
  virtual int OnNewConnection();
  virtual int OnDataReceived(const PacketPtr& packet);
  virtual int OnConnectionClosed();

  virtual void OnTaskDataReceived(const char* data, uint32 data_len);

  //////////////////////////////////////////////////////////////////////////
private:
  int client_id_;
  base::PlatformThreadId thread_id_;
  int conn_state_;
  base::Lock lock_;
  ServerCommHandler* server_comm_handler_;
  std::string log_prefix_;
};

const scoped_refptr<ClientCommHandler>& GetEmptyClientCommHandler();

class ClientCommHandlerFactory :
  public net::IOHandlerFactory {
public:
  static ClientCommHandlerFactory* GetInstance() {
    return Singleton<ClientCommHandlerFactory>::get();
  }

  virtual net::IOHandler* CreateIOHandler(SOCKET socket, net::Reactor* reactor) {
    return new ClientCommHandler(socket, reactor);
  }

private:
  friend class Singleton<ClientCommHandlerFactory>;
  friend struct DefaultSingletonTraits<ClientCommHandlerFactory>;

  ClientCommHandlerFactory() {}
  virtual ~ClientCommHandlerFactory() {}

  DISALLOW_COPY_AND_ASSIGN(ClientCommHandlerFactory);
};

#endif

