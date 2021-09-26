#include "ValueWindow.h"
#include "BinaryOperator.h"
#include "TypeButton.h"
class Calc {
	std::wstring lhs;
	ValueWindow  value;
	TypeButton   type ;
	void (Calc::*state)(HWND hDlg, WORD nID);
	const BinaryOperator* op;
	void perform_calculation();
	void operator_state        (HWND hDlg, WORD nID);
	void fractional_part_state (HWND hDlg, WORD nID);
	void following_digits_state(HWND hDlg, WORD nID);
	void first_digit_state     (HWND hDlg, WORD nID);
public:
	Calc
	( ValueWindow&& value
	, TypeButton && type 
	) noexcept;
	void EnableDisableButtonsByType(HWND hDlg);
	void Handle_WM_COMMAND(HWND hDlg, WPARAM wParam);
};
