#pragma once
#include "shape.h"

class RectShape : virtual public Shape {
public:
	void Show(HDC);
	void DrawRubberBand(HWND);
	Shape* copyShape();
};
