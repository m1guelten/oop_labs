#pragma once
#include "shape.h"
#define BLACK RGB(0, 0, 0)
#define RED 0x0000ff

class RectShape : virtual public Shape {
public:
	void Show(HDC,bool);
	void DrawRubberBand(HWND);
	Shape* copyShape();
};
