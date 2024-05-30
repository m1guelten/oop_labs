#include "rect_shape.h"

void RectShape::Show(HDC hdc, bool isSelected)
{
	COLORREF color = isSelected ? RED : BLACK;

	HPEN hPen = CreatePen(PS_SOLID, 1, color);
	HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, 2 * xs1 - xs2, 2 * ys1 - ys2, NULL);
	LineTo(hdc, xs2, 2 * ys1 - ys2);
	LineTo(hdc, xs2, ys2);
	LineTo(hdc, 2 * xs1 - xs2, ys2);
	LineTo(hdc, 2 * xs1 - xs2, 2 * ys1 - ys2);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}

void RectShape::DrawRubberBand(HWND hWnd)
{
	HPEN hPenOld, hPen;
	HDC hdc;
	hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);
	hPen = CreatePen(PS_DOT, 1, 0);
	hPenOld = (HPEN)SelectObject(hdc, hPen);
	
	Rectangle(hdc, 2 * xs1 - xs2, 2 * ys1 - ys2, xs2, ys2);
	
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}

Shape* RectShape::copyShape() { return new RectShape; }