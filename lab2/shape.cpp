#include "framework.h"
#include "shape.h"

#define BLACK RGB(0, 0, 0)


HBRUSH hBrush, hBrushOld;
Shape::~Shape() {}

/*void Shape::Set(long x1, long y1, long x2, long y2)
{
	xs1 = x1;
	ys1 = y1;
	xs2 = x2;
	ys2 = y2;
}
*/

void Shape::SetStart(long x, long y) 
{
	x1 = x;
	y1 = y;
}

void Shape::SetEnd(long x, long y) 
{
	x2 = x;
	y2 = y;
}

long Shape::getX1(void) { return x1; };
long Shape::getY1(void) { return y1; };
long Shape::getX2(void) { return x2; };
long Shape::getY2(void) { return y2; };

void PointShape::Show(HDC hdc) 
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			SetPixel(hdc, x1 + i, y1 + j, BLACK);
		}
	}
}

void LineShape::Show(HDC hdc) 
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

void RectShape::Show(HDC hdc)
{
//	hBrush = (HBRUSH)CreateSolidBrush(ORANGE);		//створюється пензль Orange color
//	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);	//пензль -> у hdc
	Rectangle(hdc, x1, y1, x2, y2);
//	SelectObject(hdc, hBrushOld);					//відновлюється пензль-попередник
//	DeleteObject(hBrush);							//створений знищується
}

void EllipseShape::Show(HDC hdc)
{
//	hBrush = (HBRUSH)CreateSolidBrush(PINK);		//створюється пензль Pink color
//	hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);	//пензль -> у hdc
	Arc(hdc, 2 * x1 - x2, 2 * y1 - y2, x2, y2,0,0,0,0);
//	Ellipse(hdc, 2*x1-x2, 2*y1-y2, x2, y2);
//	SelectObject(hdc, hBrushOld);					//відновлюється пензль-попередник
//	DeleteObject(hBrush);							//створений знищується
}
