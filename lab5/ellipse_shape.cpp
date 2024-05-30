#include "ellipse_shape.h"

void EllipseShape::Show(HDC hdc, bool isSelected)
{
	COLORREF color = isSelected ? RED : ORANGE;
	HBRUSH hBrush, hBrushOld;
	hBrush = (HBRUSH)CreateSolidBrush(color);		//����������� ������ Pink color
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);	//������ -> � hdc
	
	Ellipse(hdc, xs1, ys1, xs2, ys2);
	
	SelectObject(hdc, hBrushOld);					//������������ ������-����������
	DeleteObject(hBrush);							//��������� ���������
}

void EllipseShape::DrawRubberBand(HWND hWnd)
{
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	
	Ellipse(hdc, xs1, ys1, xs2, ys2);
	
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}

Shape* EllipseShape::copyShape() { return new EllipseShape; }