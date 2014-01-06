// Copyright (C) 2012 by wubenqi
// Distributable under the terms of either the Apache License (Version 2.0) or 
// the GNU Lesser General Public License, as specified in the COPYING file.
//
// By: wubenqi<wubenqi@gmail.com>
//

#ifndef LUABIND_PB_LUABIND_PB_MODULE_H_
#define LUABIND_PB_LUABIND_PB_MODULE_H_
#pragma once

#include "base/basictypes.h"

#if defined(OS_WIN)
#include <windows.h>
#else
#define WINAPI
#endif

// class LuabindPBModule;

struct lua_State;

// ��protoc-gen-luabind����
//void LuabindPBModule_RegisterLuabindPB(LuabindPBModule* module, LuabindRegister_Func func);
//
//typedef LuabindPBModule* (*FN_CreateLuabindPBModule)();
//typedef void (*FN_DestroyLuabindPBModule)(LuabindPBModule* module);
//typedef void (*FN_LuabindPBModule_ResetIterator)(LuabindPBModule* module);
//typedef LuabindRegister_Func (*FN_LuabindPBModule_GetNextRegisterLuabindPB)(LuabindPBModule* module);

typedef void (*FN_LuabindPBModule_Register)(lua_State* L);

//extern "C" {
//
////// ����������
////LuabindPBModule* CreateLuabindPBModule();
////void DestroyLuabindPBModule(LuabindPBModule* module);
////void LuabindPBModule_ResetIterator(LuabindPBModule* module);
////// ����ȫ���Ѿ�ע�����Ϣ
////LuabindRegister_Func LuabindPBModule_GetNextRegisterLuabindPB(LuabindPBModule* module);
//
//void WINAPI LuabindPBModule_Register(lua_State* L);
//
//};

#endif
