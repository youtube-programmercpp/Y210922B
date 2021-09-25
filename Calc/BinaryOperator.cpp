#include "BinaryOperator.h"
#include <Windows.h>
#include <sstream>
const BinaryOperator op_Add =
{ [](double    lhs, double    rhs)->double    { return lhs + rhs; }
, [](long long lhs, long long rhs)->long long { return lhs + rhs; }
};
const BinaryOperator op_Sub =
{ [](double    lhs, double    rhs)->double    { return lhs - rhs; }
, [](long long lhs, long long rhs)->long long { return lhs - rhs; }
};
const BinaryOperator op_Mul =
{ [](double    lhs, double    rhs)->double    { return lhs * rhs; }
, [](long long lhs, long long rhs)->long long { return lhs * rhs; }
};
const BinaryOperator op_Div =
{ [](double    lhs, double    rhs)->double    { return lhs / rhs; }
, [](long long lhs, long long rhs)->long long { return lhs / rhs; }
};
#include <iomanip>
std::wstring BinaryOperator::compute(const std::wstring & lhs, const std::wstring & rhs) const
{
	const auto result_ll = (*ll)
		( std::stoll(lhs)
		, std::stoll(rhs)
		);
	const auto result_d  = (*d )
		( std::stod (lhs)
		, std::stod (rhs)
		);
	if (result_ll == result_d)
		return std::to_wstring(result_ll);
	else
		return (std::wostringstream() << std::setprecision(std::numeric_limits<double>::digits10) << result_d).str();
}
