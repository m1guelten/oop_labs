#include "framework.h"
#include "point_editor.h"



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

void PointEditor::OnMouseMove(HWND hWnd) {
	SetWindowText(hWnd, L"Режим вводу точки");
};

