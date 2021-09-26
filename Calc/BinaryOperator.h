#pragma once
#include "ValueType.h"
#include <string>
struct BinaryOperator
{
	double             (*p_DOUBLE)(double             lhs, double             rhs);
	unsigned long long (*p_QWORD )(unsigned long long lhs, unsigned long long rhs);
	unsigned long      (*p_DWORD )(unsigned long      lhs, unsigned long      rhs);
	unsigned short     (*p_WORD  )(unsigned short     lhs, unsigned short     rhs);
	unsigned char      (*p_BYTE  )(unsigned char      lhs, unsigned char      rhs);

	std::wstring compute(ValueType t, const std::wstring& lhs, const std::wstring& rhs) const;
};
extern const BinaryOperator op_Add;
extern const BinaryOperator op_Sub;
extern const BinaryOperator op_Mul;
extern const BinaryOperator op_Div;
