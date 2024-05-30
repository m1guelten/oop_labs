#pragma once
#include "shape.h"

class PointShape : virtual public Shape
{
public:
	void Show(HDC,bool);
	void DrawRubberBand(HWND);
	Shape* copyShape();
};
