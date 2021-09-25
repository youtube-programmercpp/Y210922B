#include "ValueWindow.h"
#include "BinaryOperator.h"
class Calc {
	std::wstring lhs;
	ValueWindow value;
	void (Calc::*state)(HWND hDlg, WPARAM wParam);
	const BinaryOperator* op;
	void perform_calculation();
	void operator_state(HWND hDlg, WPARAM wParam);
	void fractional_part_state(HWND hDlg, WPARAM wParam);
	void following_digits_state(HWND hDlg, WPARAM wParam);
	void first_digit_state(HWND hDlg, WPARAM wParam);
public:
	Calc(ValueWindow&& value) noexcept;
	void Handle_WM_COMMAND(HWND hDlg, WPARAM wParam);
};
