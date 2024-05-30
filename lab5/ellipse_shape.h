#pragma once
#include "shape.h"
#define BLACK RGB(0, 0, 0)
#define ORANGE RGB(255, 128, 0)
#define RED 0x0000ff


class EllipseShape : virtual public Shape 
{
public:
	virtual void Show(HDC,bool);
	void DrawRubberBand(HWND);
	Shape* copyShape();
};