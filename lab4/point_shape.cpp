#include "point_shape.h"
#define BLACK RGB(0, 0, 0)

void PointShape::Show(HDC hdc)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			SetPixel(hdc, xs1 + i, ys1 + j, BLACK);
		}
	}
}

void PointShape::DrawRubberBand(HWND hWnd) { }

Shape* PointShape::copyShape() { return new PointShape; }