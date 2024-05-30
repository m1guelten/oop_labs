#pragma once
#include "line_shape.h"
#include "rect_shape.h"

class CubeShape : public LineShape, public RectShape
{
public:
	virtual void Show(HDC,bool);
	void DrawRubberBand(HWND);
	Shape* copyShape();
};