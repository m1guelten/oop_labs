#pragma once
#include "Editor.h"

class LineEditor : public ShapeEditor
{
public:
	void OnLBdown(HWND);
	void OnMouseMove(HWND);
};