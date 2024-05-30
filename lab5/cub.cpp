#include "cub.h"
#define BIAS 30

void CubeShape::Show(HDC hdc,bool isSelected)
{
	COLORREF color = isSelected ? 0x0000ff : 0;

	HPEN hPen = CreatePen(PS_SOLID, 1, color);
	HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);

	long x1, x2, y1, y2;
	RectShape::Show(hdc, isSelected);

	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	LineShape::Set(2 * xs1 - xs2, 2 * ys1 - ys2, 2 * xs1 - xs2 + BIAS, 2 * ys1 - ys2 - BIAS);
	LineShape::Show(hdc, isSelected);
	MoveToEx(hdc, x2, 2 * y1 - y2, NULL);
	LineTo(hdc, x2 + BIAS, 2 * y1 - y2 - BIAS);

	MoveToEx(hdc, x2, y2, NULL);
	LineTo(hdc, x2 + BIAS, y2 - BIAS);

	MoveToEx(hdc, 2 * x1 - x2, y2, NULL);
	LineTo(hdc, 2 * x1 - x2 + BIAS, y2 - BIAS);

	LineTo(hdc, 2 * x1 - x2 + BIAS, 2 * y1 - y2 - BIAS);
	LineTo(hdc, x2 + BIAS, 2 * y1 - y2 - BIAS);
	LineTo(hdc, x2 + BIAS, y2 - BIAS);
	LineTo(hdc, 2 * x1 - x2 + BIAS, y2 - BIAS);
	LineTo(hdc, 2 * x1 - x2 + BIAS, 2 * y1 - y2 - BIAS);

	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);

}

void CubeShape::DrawRubberBand(HWND hWnd)
{
	HDC hdc;
	hdc = GetDC(hWnd);
	long x1, x2, y1, y2, x0,y0;

	x0 = 2 * xs1 - xs2;
	y0 = 2 * ys1 - ys2;
	RectShape::DrawRubberBand(hWnd);
	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	LineShape::Set(x0, y0, x0 + BIAS, y0 - BIAS);
	LineShape::DrawRubberBand(hWnd);
	
	LineShape::Set(x2, y0, x2 + BIAS, y0 - BIAS);
	LineShape::DrawRubberBand(hWnd);

	LineShape::Set(x2, y2, x2 + BIAS, y2 - BIAS);
	LineShape::DrawRubberBand(hWnd);

	LineShape::Set(x0, y2, x0 + BIAS, y2 - BIAS);
	LineShape::DrawRubberBand(hWnd);

	LineShape::Set(x0 + BIAS, y0-BIAS, x0 + BIAS, y2 - BIAS);
	LineShape::DrawRubberBand(hWnd);

	LineShape::Set(x0 + BIAS, y0 - BIAS, x2 + BIAS, y0 - BIAS);
	LineShape::DrawRubberBand(hWnd);

	LineShape::Set(x0 + BIAS, y2 - BIAS, x2 + BIAS, y2 - BIAS);
	LineShape::DrawRubberBand(hWnd);

	LineShape::Set(x2 + BIAS, y0 - BIAS, x2 + BIAS, y2 - BIAS);
	LineShape::DrawRubberBand(hWnd);
	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
}

Shape* CubeShape::copyShape() { return new CubeShape; }