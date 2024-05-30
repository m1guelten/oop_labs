#pragma once
#pragma comment(lib, "comctl32.lib")

#define IDC_MY_TOOLBAR 1

#define ID_TOOL_POINT 1
#define ID_TOOL_LINE 2
#define ID_TOOL_RECT 3 
#define ID_TOOL_ELLIPSE 4
#define ID_TOOL_LINE_OO 5 
#define ID_TOOL_CUB 6

class ToolBar {
protected:
	HWND hwndToolBar = NULL;
	LPARAM oldlParam = NULL;
public:
	ToolBar(void);
	void OnCreate(HWND, HINSTANCE);
	void OnSize(HWND);
	void OnTool(HWND, LPARAM);
	void OnNotify(HWND, WPARAM, LPARAM);
};

