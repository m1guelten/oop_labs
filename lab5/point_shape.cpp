#include "point_shape.h"
#define BLACK RGB(0, 0, 0)
#define RED 0x0000ff

void PointShape::Show(HDC hdc, bool isSelected)
{
	COLORREF color = isSelected ? RED : BLACK;

	HPEN hPen = CreatePen(PS_SOLID, 1, color);
	HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			SetPixel(hdc, xs1 + i, ys1 + j, color);
		}
	}
	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
}

void PointShape::DrawRubberBand(HWND hWnd) { }

Shape* PointShape::copyShape() { return new PointShape; }