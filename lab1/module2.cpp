#include "framework.h"
#include "module2.rh"

static WCHAR* ptext;
int pos;

static INT_PTR CALLBACK Dlg2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        SetScrollRange(GetDlgItem(hDlg, IDC_SCROLLBAR1), SB_CTL, 0, 100, FALSE);
        //GetDlgItem(hDlg, IDC_STATIC1);
        return (INT_PTR)TRUE;
    case WM_HSCROLL:
        pos = GetScrollPos(GetDlgItem(hDlg, IDC_SCROLLBAR1), SB_CTL);
        switch (LOWORD(wParam))
        {
        case SB_LINELEFT:
            pos--;
         //   wsprintfW(ptext, L"%d", pos);
        //    TextOut(GetDlgItem(hDlg, IDC_STATIC1), 10, 10, ptext, wcslen(ptext));
            break;
        case SB_LINERIGHT:
            pos++;
            break;
        case SB_THUMBPOSITION:
            GetDlgItem(hDlg, IDC_SCROLLBAR1);
            break;
        case SB_THUMBTRACK:
            pos = HIWORD(wParam);
            break;
        default: break;
        }
        SetScrollPos(GetDlgItem(hDlg, IDC_SCROLLBAR1), SB_CTL, pos, TRUE);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK2)
        {
            wsprintfW(ptext, L"%d", pos);
            EndDialog(hDlg, 1);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDCANCEL2)
        {
            EndDialog(hDlg, 0);
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

int Func_MOD2(HWND hWnd, HINSTANCE hInst, WCHAR* p)
{
    ptext = p;
    return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, Dlg2);
}