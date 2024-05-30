#include "line_OO.h"
#define DIAM 15

void LineWithEllipseShape::Show(HDC hdc, bool isSelected)
{
	long x1, x2, y1, y2;
	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;
	
	LineShape::Set(x1 , y1 , x2 , y2 );
	LineShape::Show(hdc, isSelected);

	EllipseShape::Set(x1 - DIAM, y1 - DIAM, x1 + DIAM, y1 + DIAM);
	EllipseShape::Show(hdc, isSelected);
	EllipseShape::Set(x2 - DIAM, y2 - DIAM, x2 + DIAM, y2 + DIAM);
	EllipseShape::Show(hdc, isSelected);
	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
}

void LineWithEllipseShape::DrawRubberBand(HWND hWnd)
{
	HDC hdc;
	hdc = GetDC(hWnd);
	long x1, x2, y1, y2;
	x1 = xs1; y1 = ys1; x2 = xs2; y2 = ys2;

	LineShape::Set(x1 , y1 , x2 , y2 );
	LineShape::DrawRubberBand(hWnd);

	EllipseShape::Set(x1 - DIAM, y1 - DIAM, x1 + DIAM, y1 + DIAM);
	EllipseShape::DrawRubberBand(hWnd);
	EllipseShape::Set(x2 - DIAM, y2 - DIAM, x2 + DIAM, y2 + DIAM);
	EllipseShape::DrawRubberBand(hWnd);
	xs1 = x1; ys1 = y1; xs2 = x2; ys2 = y2;
}

Shape* LineWithEllipseShape::copyShape() { return new LineWithEllipseShape; }