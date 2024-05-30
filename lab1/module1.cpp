#include "framework.h"
#include "module1.rh"

static WCHAR* ptext;

static INT_PTR CALLBACK Dlg1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
    {
        UNREFERENCED_PARAMETER(lParam);
        switch (message)
        {
        case WM_INITDIALOG:
            return (INT_PTR)TRUE;

        case WM_COMMAND:
            if (LOWORD(wParam) == IDOK)
            {
                GetDlgItemText(hDlg, IDC_EDIT1, ptext,256);
                EndDialog(hDlg, 1);
                return (INT_PTR)TRUE;
            }
            if (LOWORD(wParam) == IDCANCEL)
            {
                EndDialog(hDlg, 0);
                return (INT_PTR)TRUE;
            }
            break;
        }
        return (INT_PTR)FALSE;
    }

    int Func_MOD1(HWND hWnd, HINSTANCE hInst, WCHAR* p)
    {
        ptext = p;
        return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Dlg1);
         }