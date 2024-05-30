#include "framework.h"
#include "ellipse_editor.h"
#include "function.h"


void EllipseEditor::OnLBdown(HWND hWnd) 
{
	isPainting = true;
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	UpdatePos();
	CheckNum();
	pcshape[pos] = new EllipseShape;
	pcshape[pos]->SetStart(pt.x, pt.y);
};

void EllipseEditor::OnMouseMove(HWND hWnd) 
{
	if (isPainting) 
	{
		POINT pt;
		HPEN hPenOld, hPen;
		HDC hdc = GetDC(hWnd);									//�������� �������� ���� ��� ���������
		SetROP2(hdc, R2_NOTXORPEN);
		hPen = CreatePen(PS_SOLID, 1, BLUE);
		hPenOld = (HPEN)SelectObject(hdc, hPen);
		
		//��������� �� "��������" ���� ������������ ������������ �������
		Ellipse(hdc, (2*(pcshape[pos]->getX1())- pcshape[pos]->getX2()), (2*(pcshape[pos]->getY1())- pcshape[pos]->getY2()), pcshape[pos]->getX2(), pcshape[pos]->getY2());
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		pcshape[pos]->SetEnd(pt.x, pt.y);
																//��������� �� "��������" ���� ��� ��������� ������������ �������
		Ellipse(hdc, (2 * (pcshape[pos]->getX1()) - pcshape[pos]->getX2()), (2 * (pcshape[pos]->getY1()) - pcshape[pos]->getY2()), pcshape[pos]->getX2(), pcshape[pos]->getY2());
		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		ReleaseDC(hWnd, hdc);									//��������� �������� ����
	}
};

void EllipseEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam) 
{
	FuncInitMenuPopup(hWnd, wParam, ID_ELLIPSE);
};

