#include "ValueWindow.h"

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
