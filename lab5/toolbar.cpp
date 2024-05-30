#include "framework.h"
#include "resource.h"
#include "toolbar.h"
#include <commctrl.h>

ToolBar::ToolBar(void) {}

void ToolBar::OnCreate(HWND hWnd, HINSTANCE hInst)
{
    TBBUTTON tbb[15];
    ZeroMemory(tbb, sizeof(tbb));

    tbb[0].iBitmap = 0;
    tbb[0].fsState = TBSTATE_ENABLED;
    tbb[0].fsStyle = TBSTYLE_SEP;
    tbb[0].idCommand = 0;

    tbb[1].iBitmap = 0;
    tbb[1].fsState = TBSTATE_ENABLED;
    tbb[1].fsStyle = TBSTYLE_BUTTON;
    tbb[1].idCommand = ID_TOOL_POINT;

    tbb[2].iBitmap = 0;
    tbb[2].fsState = TBSTATE_ENABLED;
    tbb[2].fsStyle = TBSTYLE_SEP;
    tbb[2].idCommand = 0;

    tbb[3].iBitmap = 1;
    tbb[3].fsState = TBSTATE_ENABLED;
    tbb[3].fsStyle = TBSTYLE_BUTTON;
    tbb[3].idCommand = ID_TOOL_LINE;

    tbb[4].iBitmap = 0;
    tbb[4].fsState = TBSTATE_ENABLED;
    tbb[4].fsStyle = TBSTYLE_SEP;
    tbb[4].idCommand = 0;

    tbb[5].iBitmap = 2;
    tbb[5].fsState = TBSTATE_ENABLED;
    tbb[5].fsStyle = TBSTYLE_BUTTON;
    tbb[5].idCommand = ID_TOOL_RECT;

    tbb[6].iBitmap = 0;
    tbb[6].fsState = TBSTATE_ENABLED;
    tbb[6].fsStyle = TBSTYLE_SEP;
    tbb[6].idCommand = 0;

    tbb[7].iBitmap = 3;
    tbb[7].fsState = TBSTATE_ENABLED;
    tbb[7].fsStyle = TBSTYLE_BUTTON;
    tbb[7].idCommand = ID_TOOL_ELLIPSE;

    tbb[8].iBitmap = 0;
    tbb[8].fsState = TBSTATE_ENABLED;
    tbb[8].fsStyle = TBSTYLE_SEP;
    tbb[8].idCommand = 0;

    tbb[9].iBitmap = 4;
    tbb[9].fsState = TBSTATE_ENABLED;
    tbb[9].fsStyle = TBSTYLE_BUTTON;
    tbb[9].idCommand = ID_TOOL_LINE_OO;

    tbb[10].iBitmap = 0;
    tbb[10].fsState = TBSTATE_ENABLED;
    tbb[10].fsStyle = TBSTYLE_SEP;
    tbb[10].idCommand = 0;

    tbb[11].iBitmap = 5;
    tbb[11].fsState = TBSTATE_ENABLED;
    tbb[11].fsStyle = TBSTYLE_BUTTON;
    tbb[11].idCommand = ID_TOOL_CUB;

    tbb[12].iBitmap = 0;
    tbb[12].fsState = TBSTATE_ENABLED;
    tbb[12].fsStyle = TBSTYLE_SEP;
    tbb[12].idCommand = 0;

    tbb[13].iBitmap = 0;
    tbb[13].fsState = TBSTATE_ENABLED;
    tbb[13].fsStyle = TBSTYLE_SEP;
    tbb[13].idCommand = 0;

    tbb[14].iBitmap = 6;
    tbb[14].fsState = TBSTATE_ENABLED;
    tbb[14].fsStyle = TBSTYLE_BUTTON;
    tbb[14].idCommand = ID_TOOL_TABL;

    hwndToolBar = CreateToolbarEx(hWnd,
        WS_CHILD | WS_VISIBLE | WS_BORDER |
        WS_CLIPSIBLINGS | CCS_TOP | TBSTYLE_TOOLTIPS,
        IDC_MY_TOOLBAR, 7, hInst,
        IDB_BITMAP1, tbb, 15,
        24, 24, 24, 24, sizeof(TBBUTTON));
};


void ToolBar::OnSize(HWND hWnd)
{
    RECT rc, rw;
    if (hwndToolBar) {
        GetClientRect(hWnd, &rc);
        GetWindowRect(hwndToolBar, &rw);
        MoveWindow(hwndToolBar, 0, 0, rc.right - rc.left, rw.bottom - rw.top, FALSE);
    }
};

void ToolBar::OnTool(HWND hWnd, LPARAM lParam)
{
    if (oldlParam)
    {
        SendMessage(hwndToolBar, TB_PRESSBUTTON, oldlParam, 0); //release old button
    }
    SendMessage(hwndToolBar, TB_PRESSBUTTON, lParam, 1);        // press new button
    oldlParam = lParam;
}

void ToolBar::OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    LPNMHDR pnmh = (LPNMHDR)lParam;
    if (pnmh->code == TTN_NEEDTEXT)
    {
        LPTOOLTIPTEXT lpttt = (LPTOOLTIPTEXT)lParam;
        switch (lpttt->hdr.idFrom)
        {
        case ID_TOOL_POINT:
            lstrcpy(lpttt->szText, L"Малювати точку");
            break;
        case ID_TOOL_LINE:
            lstrcpy(lpttt->szText, L"Малювати лінію");
            break;
        case ID_TOOL_RECT:
            lstrcpy(lpttt->szText, L"Малювати прямокутник");
            break;
        case ID_TOOL_ELLIPSE:
            lstrcpy(lpttt->szText, L"Малювати елліпс");
            break;
        case ID_TOOL_LINE_OO:
            lstrcpy(lpttt->szText, L"Малювати линію з шарами");
            break;
        case ID_TOOL_CUB:
            lstrcpy(lpttt->szText, L"Малювати паралелепіпеди");
            break;
        case ID_TOOL_TABL:
            lstrcpy(lpttt->szText, L"Таблиця об'єктів");
            break;
        default:
            break;
        }
    }
};

