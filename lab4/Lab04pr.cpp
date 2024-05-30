// Lab04pr.cpp : Defines the entry point for the application.
//


#include "framework.h"
#include "Lab04pr.h"
#include "my_editor.h"
#include "resource.h"
#include "toolbar.h"
#include "point_shape.h"
#include "line_shape.h"
#include "rect_shape.h"
#include "ellipse_shape.h"
#include "line_OO.h"
#include "cub.h"

#define MAX_LOADSTRING 100
// Global Variables:
HINSTANCE hInst; // current instance
WCHAR szTitle[MAX_LOADSTRING]; // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING]; // the main window class name
// Forward declarations of functions included in this code module:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    // TODO: Place code here.
    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB04PR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);
    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB04PR));
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
// FUNCTION: MyRegisterClass()
//
// PURPOSE: Registers the window class.
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
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_LAB04PR));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LAB04PR);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}
//
// FUNCTION: InitInstance(HINSTANCE, int)
//
// PURPOSE: Saves instance handle and creates main window
//
// COMMENTS:
//
// In this function, we save the instance handle in a global variable and
// create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Store instance handle in our global variable
    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW |
        WS_CLIPCHILDREN,
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
// FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
// PURPOSE: Processes messages for the main window.
//
// WM_COMMAND - process the application menu
// WM_PAINT - Paint the main window
// WM_DESTROY - post a quit message and return
//
//

MyEditor* ped = NULL;
MyEditor Misha;
ToolBar myToolBar;


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int wmId, wmEvent;
    switch (message)
    {
    case WM_CREATE:
        myToolBar.OnCreate(hWnd, hInst);
        myToolBar.OnTool(hWnd, ID_TOOL_POINT); //selecting point from start
        break;

    case WM_SIZE:
        myToolBar.OnSize(hWnd);
        break;

    case WM_NOTIFY:
        myToolBar.OnNotify(hWnd, wParam, lParam);
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
        Misha.OnPaint(hWnd); //для WM_PAINT це не зовсім коректно
        break;
    case WM_COMMAND:
    {
        wmId = LOWORD(wParam);
        wmEvent = HIWORD(wParam);
        switch (wmId)
        {
        case ID_TOOL_POINT:
        case ID_POINT:
            SetWindowText(hWnd, L"Режим вводу точок");
            myToolBar.OnTool(hWnd, ID_TOOL_POINT);
            Misha.Start(new PointShape);
            break;

        case ID_TOOL_LINE:
        case ID_LINE:
            SetWindowText(hWnd, L"Режим вводу ліній");
            myToolBar.OnTool(hWnd, ID_TOOL_LINE);
            Misha.Start(new LineShape);
            break;

        case ID_TOOL_RECT:
        case ID_RECT:
            SetWindowText(hWnd, L"Режим вводу прямокутників");
            myToolBar.OnTool(hWnd, ID_TOOL_RECT);
            Misha.Start(new RectShape);
            break;

        case ID_TOOL_ELLIPSE:
        case ID_ELLIPSE:
            SetWindowText(hWnd, L"Режим вводу еліпсів");
            myToolBar.OnTool(hWnd, ID_TOOL_ELLIPSE);
            Misha.Start(new EllipseShape);
            break;

        case ID_TOOL_LINE_OO:
        case ID_LINE_OO:
            SetWindowText(hWnd, L"Режим вводу ліній з кружечками");
            myToolBar.OnTool(hWnd, ID_TOOL_LINE_OO);
            Misha.Start(new LineWithEllipseShape);
            break;

        case ID_TOOL_CUB:
        case ID_CUB:
            SetWindowText(hWnd, L"Режим вводу об'ємних прямокутників");
            myToolBar.OnTool(hWnd, ID_TOOL_CUB);
            Misha.Start(new CubeShape);
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