// Copyright (C) 2012 by wubenqi
// Distributable under the terms of either the Apache License (Version 2.0) or 
// the GNU Lesser General Public License, as specified in the COPYING file.
//
// By: wubenqi<wubenqi@gmail.com>
//

#ifndef NET_BASE_BYTE_STREAM_H_
#define NET_BASE_BYTE_STREAM_H_
#pragma once

#include "base/basictypes.h"
#include <string>

namespace net {

class ByteStream {
public:
	// Flag values
	enum Mode { store = 0, load = 1}; // ���棨д�������س������������ڴ洢�棨�ڴ�д��������ڴ��س����ڴ������
	/**
	 * ��������д���ByteStream����,��д�������ֽ���
	 * @param dataLen ���ݵ���󳤶�
	 */
	ByteStream(void);
	
	/**
	 * �������ڶ�����ByteStream����,�ٶ�pBuffer����dataLen���ȵ�����
	 * �κζ�ByteStream����ĸ��Ľ�Ӱ�������pBuffer�е�����
	 * @param pBuffer ����,Ӧȷ��������dataLen����
	 * @param dataLen ���ݳ���
	 */
	ByteStream( const void* pBuffer, uint32 dataLen );
	
	virtual ~ByteStream(void);

	inline bool IsStoring() const    // ���棨д�ļ���ģʽ��
	{ return m_nMode == ByteStream::store; }
	inline bool IsLoading() const    // �س������ļ���ģʽ��
	{ return m_nMode == ByteStream::load; }

public:
	/**
	 * ���ڲ�ָ�붨λ��ĳһλ��
	 * @param pos ���ڲ�ָ�붨λ����λ��,��λ������ڿ�ʼλ��(0)
	 * @return �ɹ����ص�ǰ�ڲ�ָ��ָ��λ��,���򷵻�-1
	 */
	int32 Seek(uint32 pos) const;

	/**
	 * �����ڲ�ָ����ָ��λ��
	 * @return ���ɹ�����-1
	 */
	uint32 Tell(void) const;

	/**
	 * ���������ֽ�
	 * @param pos Ҫ�������ֽ���
	 * @return �ɹ�����0
	 */
	int32 Skip(uint32 pos) const;

	/**
	 * �ж�operator << ��operator >>���� �Ƿ�ɹ�
	 * @return �����ɹ�,�򷵻�true
	 */
	bool Fail(void) const;

	/**
	 * ���صײ�Ļ�����ָ��
	 */
	const char* Data(void) const;

	/**
	 * ���صײ�����ݵĳ���
	 */
	uint32 Length(void) const;

	/**
	 * ���������ֽ�
	 * @param pdata ��Ŷ���������,Ӧ��ȷ����ָ�������ܹ�����dataLen���ֽ�
	 * @param dataLen Ҫ�������ֽ���
	 * @return �ɹ�����0
	 */
	int32 ReadBytes(void* pdata, uint32 dataLen) const;

	/**
	 * д�뼸���ֽ�
	 * @param pdata Ҫд�������,Ӧ��ȷ����ָ������ӵ��dataLen���ֽ�
	 * @param dataLen Ҫд����ֽ���
	 * @return �ɹ�����0
	 */
	int32 WriteBytes(const void* pdata, uint32 dataLen);

	/**
	 * ����һ���ַ���(��'\0'��β)
	 * @param pdata ��Ŷ������ַ���,Ӧ��ȷ����ָ�������ܹ�����dataLen���ֽ�
	 * @param dataLen Ҫ�������ֽ���,������β�ַ�'\0'
	 * @return �ɹ�����0
	 */
	int32 ReadString(char* pdata, uint32 dataLen) const;
	int32 ReadString(std::string& data) const;
	const ByteStream& operator >> (std::string& str) const;

	/**
	 * д��һ���ַ���(��'\0'��β)
	 * @param pdata Ҫд����ַ���
	 * @return �ɹ�����0
	 */
	int32 WriteString(const char* pdata);
	int32 WriteString(const std::string& data);
	ByteStream& operator << (const std::string& str);

	/**
	 * д��һ��bool����
	 * @param b Ҫд���bool
	 * @return ���ɹ�,��fail() == true
	 */
	ByteStream& operator << (bool b);

	/**
	 * д��һ��char��
	 * @param ch Ҫд���ch
	 * @return ���ɹ�,��fail() == true
	 */
	ByteStream& operator << (char ch);

	/**
	 * д��һ��uint8��
	 * @param ch Ҫд���uint8
	 * @return ���ɹ�,��fail() == true
	 */
	ByteStream& operator << (uint8 ch);

	/**
	 * д��һ��int16��
	 * @param s Ҫд���int16
	 * @return ���ɹ�,��fail() == true
	 */
	ByteStream& operator << (int16 s);

	/**
	 * д��һ��uint16��
	 * @param s Ҫд���uint16
	 * @return ���ɹ�,��fail() == true
	 */
	ByteStream& operator << (uint16 s);

	/**
	 * д��һ��int32��
	 * @param l Ҫд���int32
	 * @return ���ɹ�,��fail() == true
	 */
	ByteStream& operator << (int32 l);

	/**
	 * д��һ��uint32��
	 * @param l Ҫд���uint32
	 * @return ���ɹ�,��fail() == true
	 */
	ByteStream& operator << (uint32 l);

	/**
	 * д��һ��int32
	 * @param l ��Ŷ�����int32
	 * @return ���ɹ�,��fail() == true
	 */
	const ByteStream& operator >> (bool& b) const;

	/**
	 * ����һ��char
	 * @param ch ��Ŷ�����char
	 * @return ���ɹ�,��fail() == true
	 */
	const ByteStream& operator >> (char& ch) const;

	/**
	 * ����һ��uint8
	 * @param ch ��Ŷ�����uint8
	 * @return ���ɹ�,��fail() == true
	 */
	const ByteStream& operator >> (uint8& ch) const;

	/**
	 * ����һ��int16
	 * @param s ��Ŷ�����int16
	 * @return ���ɹ�,��fail() == true
	 */
	const ByteStream& operator >> (int16& s) const;

	/**
	 * ����һ��uint16
	 * @param s ��Ŷ�����uint16
	 * @return ���ɹ�,��fail() == true
	 */
	const ByteStream& operator >> (uint16& s) const;

	/**
	 * ����һ��int32
	 * @param l ��Ŷ�����int32
	 * @return ���ɹ�,��fail() == true
	 */
	const ByteStream& operator >> (int32& l) const;

	/**
	 * ����һ��int32
	 * @param l ��Ŷ�����int32
	 * @return ���ɹ�,��fail() == true
	 */
	const ByteStream& operator >> (uint32& l) const;

	operator bool () const {
		return 0 == m_failed;
	}
	bool operator!() const {
		return 0 != m_failed;
	}


protected:
	/** ��ֹ����������� */
	ByteStream( const ByteStream& s );
	/** ��ֹ��ֵ���� */
	ByteStream& operator= ( const ByteStream& s );

protected:
	virtual void* Alloc(uint32 dwNewLen);
	virtual void  Free();

protected:
	char*			m_pBuffer;	/**< ʵ�����ڶ�д�Ļ����� */
	bool			m_isNew;	/**< m_pBuffer�Ƿ����ö�̬����� */
	uint32	m_maxLen;	/**< ����������󳤶� */
	uint32	m_dataLen;	/**< �������е����ݳ��� */
	mutable  uint32	m_currentPos;	/**< �������ж�д�ĵ�ǰλ�� */
	mutable  uint32	m_failed;	/**< ָʾ��д�����Ƿ�ɹ� */
	int m_nMode;
};

}


#endif
	
