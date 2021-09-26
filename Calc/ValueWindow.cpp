#include "ValueWindow.h"
#include "ValueType.h"

ValueWindow::ValueWindow(ValueWindow&& r) noexcept
	: hWnd (r.hWnd )
	, hFont(r.hFont)
{
	r.hWnd  = nullptr;
	r.hFont = nullptr;
}
auto ValueWindow::operator=(ValueWindow&& r) noexcept->ValueWindow&
{
	std::swap(hWnd , r.hWnd );
	std::swap(hFont, r.hFont);
	return *this;
}
ValueWindow::ValueWindow(HWND hWnd)
	: hWnd(hWnd)
	, hFont()
{
	RECT rc;
	if (GetClientRect(hWnd, &rc)) {
		LOGFONTW lf;
		if (GetObjectW(GetStockObject(DEFAULT_GUI_FONT), sizeof lf, &lf)) {
			lf.lfHeight = -rc.bottom;
			if ((hFont = CreateFontIndirectW(&lf)) != nullptr) {
				SendMessageW(hWnd, WM_SETFONT, WPARAM(hFont), true);
			}
		}
	}
}
ValueWindow::~ValueWindow()
{
	DeleteObject(hFont);
}
ValueWindow::operator std::wstring() const
{
	if (const auto n = GetWindowTextLengthW(hWnd)) {
		std::wstring s(n, L'\0');
		s.resize(GetWindowTextW(hWnd, &s.front(), n + 1));
		return s;
	}
	else
		return {};
}

auto ValueWindow::operator+=(wchar_t ch)->ValueWindow&
{
	SetWindowTextW(hWnd, (static_cast<std::wstring>(*this) + ch).c_str());
	return *this;
}
auto ValueWindow::operator=(const std::wstring& s)->ValueWindow&
{
	SetWindowTextW(hWnd, s.c_str());
	return *this;
}

void ValueWindow::ChangeType(ValueType t) const
{
	switch (t) {
	using namespace std;
	case ValueType::t_DOUBLE: break;
	case ValueType::t_QWORD : SetWindowTextW(hWnd, to_wstring(stoull(*this)).c_str()); break;
	case ValueType::t_DWORD : SetWindowTextW(hWnd, to_wstring(stoull(*this) & ULONG_MAX).c_str()); break;
	case ValueType::t_WORD  : SetWindowTextW(hWnd, to_wstring(stoul (*this) & USHRT_MAX).c_str()); break;
	case ValueType::t_BYTE  : SetWindowTextW(hWnd, to_wstring(stoul (*this) & UCHAR_MAX).c_str()); break;
	}
}
