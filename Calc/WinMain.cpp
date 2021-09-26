#include "Calc.h"
#include "resource.h"

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
	, /*_In_opt_ DLGPROC   lpDialogFunc  */[]
		( HWND   hDlg   
		, UINT   message
		, WPARAM wParam 
		, LPARAM lParam 
		)->INT_PTR
		{
			switch (message) {
			case WM_INITDIALOG:
				try {
					const HWND hValueWindow = GetDlgItem(hDlg, IDC_EDIT1);
					SetWindowTextW(hValueWindow, L"0");
					auto p = new Calc
					( ValueWindow(hValueWindow)
					, TypeButton(GetDlgItem(hDlg, IDC_BUTTON_Type))
					);
					SetLastError(0);
					if (SetWindowLongPtrW(hDlg, DWLP_USER, LONG_PTR(p)) == 0 && GetLastError()) {
						delete p;
						EndDialog(hDlg, IDCANCEL);
					}
					else
						p->EnableDisableButtonsByType(hDlg);
				}
				catch (const std::exception& e) {
					OutputDebugStringA(e.what());
					OutputDebugStringA("\n");
					EndDialog(hDlg, IDCANCEL);
				}
				return true;
			case WM_COMMAND:
				try {
					if (auto p = reinterpret_cast<Calc*>(GetWindowLongPtr(hDlg, DWLP_USER)))
						p->Handle_WM_COMMAND(hDlg, wParam);
				}
				catch (const std::exception& e) {
					OutputDebugStringA(e.what());
					OutputDebugStringA("\n");
				}
				return true;
			case WM_NCDESTROY:
				delete reinterpret_cast<Calc*>(GetWindowLongPtr(hDlg, DWLP_USER));
				return true;
			default:
				return false;
			}
		}
	, /*_In_     LPARAM    dwInitParam   */0
	);
	return 0;//0は正常終了、0 以外はエラー
}
