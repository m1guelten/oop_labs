#include "ellipse_shape.h"
#define ORANGE RGB(255, 128, 0)

void EllipseShape::Show(HDC hdc)
{
	HBRUSH hBrush, hBrushOld;
	hBrush = (HBRUSH)CreateSolidBrush(ORANGE);		//створюється пензль Pink color
	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);	//пензль -> у hdc
	
	Ellipse(hdc, xs1, ys1, xs2, ys2);
	
	SelectObject(hdc, hBrushOld);					//відновлюється пензль-попередник
	DeleteObject(hBrush);							//створений знищується

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