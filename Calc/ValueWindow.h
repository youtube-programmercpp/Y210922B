#include <Windows.h>
#include <string>
class ValueWindow {
	HWND  hWnd ;
	HFONT hFont;
public:
	ValueWindow(ValueWindow&& r) noexcept;
	auto operator=(ValueWindow&& r) noexcept->ValueWindow&;
	ValueWindow(HWND hWnd);
	~ValueWindow();
	operator std::wstring() const;
	auto operator+=(wchar_t ch)->ValueWindow& ;
	auto operator=(const std::wstring& s)->ValueWindow& ;
};
