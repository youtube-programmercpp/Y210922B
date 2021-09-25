// Calc.cpp : アプリケーションのエントリ ポイントを定義します。
#include "Calc.h"
#include "resource.h"

void Calc::perform_calculation()
{
	if (op) {
		value = op->compute(lhs, value);
	}
}

void Calc::operator_state(HWND hDlg, WPARAM wParam)
{
	switch (LOWORD(wParam)) {
	case IDCANCEL:
		EndDialog(hDlg, IDCANCEL);
		break;
	case IDC_BUTTON_Num_0: value = std::wstring(1, L'0'); state = &Calc::first_digit_state     ; break;
	case IDC_BUTTON_Num_1: value = std::wstring(1, L'1'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_2: value = std::wstring(1, L'2'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_3: value = std::wstring(1, L'3'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_4: value = std::wstring(1, L'4'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_5: value = std::wstring(1, L'5'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_6: value = std::wstring(1, L'6'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_7: value = std::wstring(1, L'7'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_8: value = std::wstring(1, L'8'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_9: value = std::wstring(1, L'9'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_OpAdd: op = &op_Add; break;
	case IDC_BUTTON_OpSub: op = &op_Sub; break;
	case IDC_BUTTON_OpMul: op = &op_Mul; break;
	case IDC_BUTTON_OpDiv: op = &op_Div; break;
	case IDC_BUTTON_Dot: value = L"0."; state = &Calc::fractional_part_state; break;
	}
}

void Calc::fractional_part_state(HWND hDlg, WPARAM wParam)
{
	switch (LOWORD(wParam)) {
	case IDCANCEL:
		EndDialog(hDlg, IDCANCEL);
		break;
	case IDC_BUTTON_Num_0: value += L'0'; break;
	case IDC_BUTTON_Num_1: value += L'1'; break;
	case IDC_BUTTON_Num_2: value += L'2'; break;
	case IDC_BUTTON_Num_3: value += L'3'; break;
	case IDC_BUTTON_Num_4: value += L'4'; break;
	case IDC_BUTTON_Num_5: value += L'5'; break;
	case IDC_BUTTON_Num_6: value += L'6'; break;
	case IDC_BUTTON_Num_7: value += L'7'; break;
	case IDC_BUTTON_Num_8: value += L'8'; break;
	case IDC_BUTTON_Num_9: value += L'9'; break;
	case IDC_BUTTON_OpAdd: perform_calculation(); lhs = value; op = &op_Add; state = &Calc::operator_state; break;
	case IDC_BUTTON_OpSub: perform_calculation(); lhs = value; op = &op_Sub; state = &Calc::operator_state; break;
	case IDC_BUTTON_OpMul: perform_calculation(); lhs = value; op = &op_Mul; state = &Calc::operator_state; break;
	case IDC_BUTTON_OpDiv: perform_calculation(); lhs = value; op = &op_Div; state = &Calc::operator_state; break;
	case IDC_BUTTON_Dot: break;
	}
}

void Calc::following_digits_state(HWND hDlg, WPARAM wParam)
{
	switch (LOWORD(wParam)) {
	case IDCANCEL:
		EndDialog(hDlg, IDCANCEL);
		break;
	case IDC_BUTTON_Num_0: value += L'0'; break;
	case IDC_BUTTON_Num_1: value += L'1'; break;
	case IDC_BUTTON_Num_2: value += L'2'; break;
	case IDC_BUTTON_Num_3: value += L'3'; break;
	case IDC_BUTTON_Num_4: value += L'4'; break;
	case IDC_BUTTON_Num_5: value += L'5'; break;
	case IDC_BUTTON_Num_6: value += L'6'; break;
	case IDC_BUTTON_Num_7: value += L'7'; break;
	case IDC_BUTTON_Num_8: value += L'8'; break;
	case IDC_BUTTON_Num_9: value += L'9'; break;
	case IDC_BUTTON_OpAdd: perform_calculation(); lhs = value; op = &op_Add; state = &Calc::operator_state; break;
	case IDC_BUTTON_OpSub: perform_calculation(); lhs = value; op = &op_Sub; state = &Calc::operator_state; break;
	case IDC_BUTTON_OpMul: perform_calculation(); lhs = value; op = &op_Mul; state = &Calc::operator_state; break;
	case IDC_BUTTON_OpDiv: perform_calculation(); lhs = value; op = &op_Div; state = &Calc::operator_state; break;
	case IDC_BUTTON_Dot: value += L'.'; state = &Calc::fractional_part_state; break;
	}
}
void Calc::first_digit_state(HWND hDlg, WPARAM wParam)
{
	switch (LOWORD(wParam)) {
	case IDCANCEL:
		EndDialog(hDlg, IDCANCEL);
		break;
	case IDC_BUTTON_Num_0: break;
	case IDC_BUTTON_Num_1: value = std::wstring(1, L'1'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_2: value = std::wstring(1, L'2'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_3: value = std::wstring(1, L'3'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_4: value = std::wstring(1, L'4'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_5: value = std::wstring(1, L'5'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_6: value = std::wstring(1, L'6'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_7: value = std::wstring(1, L'7'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_8: value = std::wstring(1, L'8'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_Num_9: value = std::wstring(1, L'9'); state = &Calc::following_digits_state; break;
	case IDC_BUTTON_OpAdd: perform_calculation(); lhs = value; op = &op_Add; state = &Calc::operator_state; break;
	case IDC_BUTTON_OpSub: perform_calculation(); lhs = value; op = &op_Sub; state = &Calc::operator_state; break;
	case IDC_BUTTON_OpMul: perform_calculation(); lhs = value; op = &op_Mul; state = &Calc::operator_state; break;
	case IDC_BUTTON_OpDiv: perform_calculation(); lhs = value; op = &op_Div; state = &Calc::operator_state; break;
	case IDC_BUTTON_Dot: value += L'.'; state = &Calc::fractional_part_state; break;
	}
}
Calc::Calc(ValueWindow&& value) noexcept
	: value(std::move(value))
	, state(&Calc::first_digit_state)
	, op   ()
{
}
//FSM
//finite  有限
//state   状態
//machine 機械
void Calc::Handle_WM_COMMAND(HWND hDlg, WPARAM wParam)
{
	(this->*state)(hDlg, wParam);
}



