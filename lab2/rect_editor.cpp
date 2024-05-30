#include "framework.h"
#include "rect_editor.h"
#include "function.h"



void RectEditor::OnLBdown(HWND hWnd) 
{
	isPainting = true;
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	UpdatePos();
	CheckNum();
	pcshape[pos] = new RectShape;
	pcshape[pos]->SetStart(pt.x, pt.y);
	pcshape[pos]->SetEnd(pt.x, pt.y);
};

void RectEditor::OnMouseMove(HWND hWnd) 
{
	if (isPainting) {
		POINT pt;
		HPEN hPenOld, hPen;
		HDC hdc = GetDC(hWnd);							//�������� �������� ���� ��� ���������
		SetROP2(hdc, R2_NOTXORPEN);
		hPen = CreatePen(PS_SOLID, 1, BLUE);
		hPenOld = (HPEN)SelectObject(hdc, hPen);
														//��������� �� "��������" ���� ������������ ������������ �������
		Rectangle(hdc, pcshape[pos]->getX1(), pcshape[pos]->getY1(), pcshape[pos]->getX2(), pcshape[pos] -> getY2());
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pcshape[pos]->SetEnd(pt.x, pt.y);
														//��������� �� "��������" ���� ��� ��������� ������������ �������
		Rectangle(hdc, pcshape[pos]->getX1(), pcshape[pos]->getY1(), pcshape[pos]->getX2(), pcshape[pos] -> getY2());
		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		ReleaseDC(hWnd, hdc);							//��������� �������� ����
	}
};

void RectEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) 
{
	FuncInitMenuPopup(hWnd, wParam, ID_RECT);
};