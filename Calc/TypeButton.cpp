#include "TypeButton.h"

static const LPCWSTR rgpszTypes[]
{ L"DOUBLE"
, L"QWORD"
, L"DWORD"
, L"WORD"
, L"BYTE"
};


TypeButton::TypeButton(HWND hWnd) noexcept
	: hWnd(hWnd)
{
}

void TypeButton::ChangeType() noexcept
{
	const auto i = (GetWindowLongPtrW(hWnd, GWLP_USERDATA) + 1) % _countof(rgpszTypes);
	SetWindowLongPtrW(hWnd, GWLP_USERDATA, i);
	SetWindowTextW(hWnd, rgpszTypes[i]);
}

TypeButton::operator ValueType() const noexcept
{
	return static_cast<ValueType>(GetWindowLongPtrW(hWnd, GWLP_USERDATA));
}
