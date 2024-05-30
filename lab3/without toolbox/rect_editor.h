#pragma once
#include "Editor.h"

class RectEditor : public ShapeEditor
{
public:
	void OnLBdown(HWND);
	void OnMouseMove(HWND);
	void OnInitMenuPopup(HWND, WPARAM);
};