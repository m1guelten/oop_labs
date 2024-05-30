#pragma once
#include "line_shape.h"
#include "ellipse_shape.h"

class LineWithEllipseShape : public LineShape, public EllipseShape
{
public:
	virtual void Show(HDC,bool);
	void DrawRubberBand(HWND);
	Shape* copyShape();
};