// Copyright (C) 2012 by wubenqi
// Distributable under the terms of either the Apache License (Version 2.0) or 
// the GNU Lesser General Public License, as specified in the COPYING file.
//
// By: wubenqi<wubenqi@gmail.com>
//

#ifndef BASE2_MATH_UTIL_H_
#define BASE2_MATH_UTIL_H_

#include "base/basictypes.h"

namespace base {

// �Ը�����������������
inline int RoundOff(float value) {
	if (value > 0)
		return (int)(value + 0.5);
	else
		return (int)(value - 0.5);
}

// ���ݵ�ǰֵ�����ֵ����ٷֱ�
inline uint32 ComputePercent(uint32 cur_value, uint32 max_value) {
	if (cur_value >= max_value)
		return 100;
	else
		return (uint32)((float)cur_value / max_value * 100);
}

template<class T>
int Float2Int(T val) {
	int result = static_cast<int>(val);

	if(val-result>=0.500000f) {
		++result;
	}
	return result;
}

}

#endif

