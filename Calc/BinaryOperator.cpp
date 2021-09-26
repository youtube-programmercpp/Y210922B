#include "BinaryOperator.h"
#include <Windows.h>
#include <sstream>

template<class T>T opAdd(T lhs, T rhs) { return lhs + rhs; }
template<class T>T opSub(T lhs, T rhs) { return lhs - rhs; }
template<class T>T opMul(T lhs, T rhs) { return lhs * rhs; }
template<class T>T opDiv(T lhs, T rhs) { return lhs / rhs; }


const BinaryOperator op_Add =
{ opAdd<double            >
, opAdd<unsigned long long>
, opAdd<unsigned long     >
, opAdd<unsigned short    >
, opAdd<unsigned char     >
};
const BinaryOperator op_Sub =
{ opSub<double            >
, opSub<unsigned long long>
, opSub<unsigned long     >
, opSub<unsigned short    >
, opSub<unsigned char     >
};
const BinaryOperator op_Mul =
{ opMul<double            >
, opMul<unsigned long long>
, opMul<unsigned long     >
, opMul<unsigned short    >
, opMul<unsigned char     >
};
const BinaryOperator op_Div =
{ opDiv<double            >
, opDiv<unsigned long long>
, opDiv<unsigned long     >
, opDiv<unsigned short    >
, opDiv<unsigned char     >
};
#include <iomanip>
std::wstring BinaryOperator::compute(ValueType t, const std::wstring & lhs, const std::wstring & rhs) const
{
	switch (t) {
	using namespace std;
	case ValueType::t_DOUBLE: return (wostringstream() << setprecision(numeric_limits<double>::digits10) << (*p_DOUBLE)(stod(lhs), stod(rhs))).str();
	case ValueType::t_QWORD : return (wostringstream() << (*p_QWORD)(                  stoull(lhs) ,                   stoull(rhs))) .str();
	case ValueType::t_DWORD : return (wostringstream() << (*p_DWORD)(                  stoul (lhs) ,                   stoul (rhs))) .str();
	case ValueType::t_WORD  : return (wostringstream() << (*p_WORD )(static_cast<WORD>(stoul (lhs)), static_cast<WORD>(stoul (rhs)))).str();
	case ValueType::t_BYTE  : return (wostringstream() << (*p_BYTE )(static_cast<BYTE>(stoul (lhs)), static_cast<BYTE>(stoul (rhs)))).str();
	}
	return {};
}
