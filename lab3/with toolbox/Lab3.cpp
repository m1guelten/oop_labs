// Lab2.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Lab3.h"
#include "shape_editor.h"


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void OnCreate1(HWND hWnd);
void OnSize(HWND hWnd);
void OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam);

ShapeObjectsEditor Misha;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    InitCommonControls();

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB3));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB3));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LAB3);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Store instance handle in our global variable

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        OnCreate1(hWnd);
        break;
    case WM_SIZE:
        OnSize(hWnd);
        break;
    case WM_NOTIFY:
        OnNotify(hWnd, wParam, lParam);
        break;

    case WM_LBUTTONDOWN:
        Misha.OnLBdown(hWnd);
        break;
    case WM_LBUTTONUP:
        Misha.OnLBup(hWnd);
        break;
    case WM_MOUSEMOVE:
        Misha.OnMouseMove(hWnd);
        break;
    case WM_PAINT:
        Misha.OnPaint(hWnd);
        break;
   
   

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        int wmEvent = HIWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case ID_TOOL_POINT:
        case ID_POINT:
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_POINT, 1);
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_LINE, 0);
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_RECT, 0);
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_ELLIPSE, 0);

            Misha.StartPointEditor();
            break;

        case ID_TOOL_LINE:
        case ID_LINE:
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_POINT, 0);
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_LINE, 1);
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_RECT, 0);
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_ELLIPSE, 0);

            Misha.StartLineEditor();
            break;

        case ID_TOOL_RECT:
        case ID_RECT:
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_POINT, 0);
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_LINE, 0);
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_RECT, 1);
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_ELLIPSE, 0);

            Misha.StartRectEditor();
            break;

        case ID_TOOL_ELLIPSE:
        case ID_ELLIPSE:
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_POINT, 0);
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_LINE, 0);
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_RECT, 0);
            SendMessage(hwndToolBar, TB_PRESSBUTTON, ID_TOOL_ELLIPSE, 1);

            Misha.StartEllipseEditor();
            break;

        case ID_CLEAR:
            Misha.ClearWindow(hWnd);
            break;
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


void OnCreate1(HWND hWnd)
{
    TBBUTTON tbb[8];
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

    hwndToolBar = CreateToolbarEx(hWnd, WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CLIPSIBLINGS | CCS_TOP | TBSTYLE_TOOLTIPS,
        IDC_MY_TOOLBAR, 4, hInst, IDB_BITMAP1, tbb, 8, 24, 24, 24, 24, sizeof(TBBUTTON));
};



void OnSize(HWND hWnd)
{
    RECT rc, rw;
    if (hwndToolBar) {
        GetClientRect(hWnd, &rc);
        GetWindowRect(hwndToolBar, &rw);
        MoveWindow(hwndToolBar, 0, 0, rc.right - rc.left, rw.bottom - rw.top, FALSE);
    }
};
void OnNotify(HWND hWnd, WPARAM wParam, LPARAM lParam)
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
        default:
            break;
        }
    }
};


