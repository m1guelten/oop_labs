#pragma once
#include "shape.h"

class LineShape :virtual public Shape {
public:
	virtual void Show(HDC);
	void DrawRubberBand(HWND);
	Shape* copyShape();
};