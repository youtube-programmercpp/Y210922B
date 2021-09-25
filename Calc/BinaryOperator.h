#pragma once
#include <string>
struct BinaryOperator
{
	double    (*d )(double    lhs, double    rhs);
	long long (*ll)(long long lhs, long long rhs);
	std::wstring compute(const std::wstring& lhs, const std::wstring& rhs) const;
};
extern const BinaryOperator op_Add;
extern const BinaryOperator op_Sub;
extern const BinaryOperator op_Mul;
extern const BinaryOperator op_Div;
