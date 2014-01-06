// Copyright (C) 2012 by wubenqi
// Distributable under the terms of either the Apache License (Version 2.0) or 
// the GNU Lesser General Public License, as specified in the COPYING file.
//
// By: wubenqi<wubenqi@gmail.com>
//
//	��Ϸ����, TXTDB���ݿ�ϵͳ, ������EXCEL���������Ʊ���ָ�����ݿ�
//  �����ӿ����������ݿ�����ӿ�
//

#ifndef DB_TXTDB_TXTDB_H_
#define DB_TXTDB_TXTDB_H_
#pragma once

#include "base/memory/singleton.h"

#include "db/base_database.h"

namespace db {

class TXTDB :
	public virtual BaseDatabase {
public:
	TXTDB(void) {}
	virtual ~TXTDB(void) {}

/*
	virtual bool Initialize(const char* dbName);
	virtual void Destroy();

	virtual MiniDBQueryResult* QueryAll();
	void FreeQueryResult(MiniDBQueryResult* query);

	inline uint32 GetMaxIndex() {
		assert(inited_!=false);
		return max_index_+1;
	}

	//�ṩ�˺�����Ϊ���ܺ�Storage���ּ���
	inline std::string GetFormatString() {
		assert(inited_!=false);
		return fieldInfo_.toFormatString();
	}

	inline MiniDBTableFieldInfo* GetFieldInfo() {
		return &fieldInfo_;
	}
*/

	// ��ѯ���
	//  ��һ��TXT�ļ������ȫ������
	//  q_strΪ�ļ�·��
	//  len���ļ�·������
	virtual QueryAnswer *Query(const char *q_str);
	virtual QueryAnswer *Query(const char *q_str, size_t len);
	virtual QueryAnswer *Query(const char *q_str, size_t len, int* err);

	// ���ܵ���
	virtual uint64 ExecuteInsertID(const char *q_str, size_t len, int* err);

	// ���ܵ���
	virtual int Execute(const char *q_str, size_t len, int* err);

	// ���ܵ���
	virtual bool Open(const char* host, const char* user, const char* password, const char* dbname, int port);
	virtual int GetError(int err);
	const std::string& DispError();

protected:
	QueryAnswer *_Query(const char *q_str, int* err);

/*
	MiniDB_AllResult all_result_;
	uint32 m_fieldCount;
	uint32 m_rowCount;

	//��ʽ���ַ���
	uint32 max_index_;
	MiniDBTableFieldInfo fieldInfo_;

	bool inited_;
*/
};

#if 0
class TXTDBFactory :
	public DatabaseFactory {
public:
	static TXTDBFactory* GetInstance() {
		return Singleton<TXTDBFactory>::get();
	}

	virtual BaseDatabase* CreateDatabase(const char* host, const char* user, const char* password, const char* dbname, int port) {
		return new TXTDB();
	}

private:
	friend class Singleton<TXTDBFactory>;
	friend struct DefaultSingletonTraits<TXTDBFactory>;

	TXTDBFactory() {}
	virtual ~TXTDBFactory() {}
};
#endif

}

#endif //
