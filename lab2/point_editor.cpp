#include "framework.h"
#include "point_editor.h"
#include "function.h"


void PointEditor::OnLBdown(HWND hWnd) 
{
	isPainting = true;
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	UpdatePos();
	CheckNum();
	pcshape[pos] = new PointShape;
	pcshape[pos]->SetStart(pt.x, pt.y);
};

void PointEditor::OnMouseMove(HWND hWnd) {};

void PointEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) 
{
	FuncInitMenuPopup(hWnd, wParam, ID_POINT);
};
