#pragma once
#include "editor.h"

class PointEditor : public ShapeEditor
{
public:
	void OnLBdown(HWND);
	void OnMouseMove(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
};