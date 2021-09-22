// Calc.cpp : アプリケーションのエントリ ポイントを定義します。
#include <Windows.h>
#include "resource.h"

#include <string>

std::wstring s;//外部変数…このようなやり方は駄目

INT_PTR CALLBACK DialogProc
( HWND   hDlg   
, UINT   message
, WPARAM wParam 
, LPARAM lParam 
)
{
	switch (message) {
	case WM_INITDIALOG:
		return true;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDCANCEL:
			EndDialog(hDlg, IDCANCEL);
			return true;
		case IDC_BUTTON_Num_0: s.append(1, L'0'); SetDlgItemTextW(hDlg, IDC_EDIT1, s.c_str()); return true;
		case IDC_BUTTON_Num_1: s.append(1, L'1'); SetDlgItemTextW(hDlg, IDC_EDIT1, s.c_str()); return true;
		case IDC_BUTTON_Num_2: s.append(1, L'2'); SetDlgItemTextW(hDlg, IDC_EDIT1, s.c_str()); return true;
		case IDC_BUTTON_Num_3: s.append(1, L'3'); SetDlgItemTextW(hDlg, IDC_EDIT1, s.c_str()); return true;
		case IDC_BUTTON_Num_4: s.append(1, L'4'); SetDlgItemTextW(hDlg, IDC_EDIT1, s.c_str()); return true;
		case IDC_BUTTON_Num_5: s.append(1, L'5'); SetDlgItemTextW(hDlg, IDC_EDIT1, s.c_str()); return true;
		case IDC_BUTTON_Num_6: s.append(1, L'6'); SetDlgItemTextW(hDlg, IDC_EDIT1, s.c_str()); return true;
		case IDC_BUTTON_Num_7: s.append(1, L'7'); SetDlgItemTextW(hDlg, IDC_EDIT1, s.c_str()); return true;
		case IDC_BUTTON_Num_8: s.append(1, L'8'); SetDlgItemTextW(hDlg, IDC_EDIT1, s.c_str()); return true;
		case IDC_BUTTON_Num_9: s.append(1, L'9'); SetDlgItemTextW(hDlg, IDC_EDIT1, s.c_str()); return true;
		default:
			return false;
		}
	default:
		return false;
	}
}


int APIENTRY wWinMain
( _In_     HINSTANCE hInstance    //インスタンスハンドル（モジュールハンドル）
, _In_opt_ HINSTANCE hPrevInstance//必ず nullptr になる
, _In_     LPWSTR    lpCmdLine    
, _In_     int       nCmdShow     
)
{
	DialogBoxParamW
	( /*_In_opt_ HINSTANCE hInstance     */hInstance     
	, /*_In_     LPCWSTR   lpTemplateName*/MAKEINTRESOURCEW(IDD_DIALOG_Calc)
	, /*_In_opt_ HWND      hWndParent    */nullptr
	, /*_In_opt_ DLGPROC   lpDialogFunc  */DialogProc
	, /*_In_     LPARAM    dwInitParam   */0
	);
	return 0;//0は正常終了、0 以外はエラー
}
