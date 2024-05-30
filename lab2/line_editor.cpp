#include "framework.h"
#include "line_editor.h"
#include "function.h"



void LineEditor::OnLBdown(HWND hWnd) 
{
isPainting = true;
POINT pt;
GetCursorPos(&pt);
ScreenToClient(hWnd, &pt);
UpdatePos();
CheckNum();
pcshape[pos] = new LineShape;
pcshape[pos]->SetStart(pt.x, pt.y);
//Set(pt.x, pt.y, NULL, NULL);
//SetStart(pt.x, pt.y);
};

void LineEditor::OnMouseMove(HWND hWnd) 
{
	if (isPainting) {
		POINT pt;
		HPEN hPenOld, hPen;
		HDC hdc = GetDC(hWnd);													//�������� �������� ���� ��� ���������
		SetROP2(hdc, R2_NOTXORPEN);
		hPen = CreatePen(PS_SOLID, 1, BLUE);
		hPenOld = (HPEN)SelectObject(hdc, hPen);

		//��������� �� "��������" ���� ������������ ������������ �������
		

		MoveToEx(hdc, pcshape[pos]->getX1(), pcshape[pos]->getY1(), NULL);
		LineTo(hdc, pcshape[pos]->getX2(), pcshape[pos]->getY2());
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pcshape[pos]->SetEnd(pt.x, pt.y);

		//��������� �� "��������" ���� ��� ��������� ������������ �������
		MoveToEx(hdc, pcshape[pos]->getX1(), pcshape[pos]->getY1(), NULL);
		LineTo(hdc, pcshape[pos]->getX2(), pcshape[pos]->getY2());
		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		ReleaseDC(hWnd, hdc); //��������� �������� ����
	}
};

void LineEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) 
{
	FuncInitMenuPopup(hWnd, wParam, ID_LINE);
};