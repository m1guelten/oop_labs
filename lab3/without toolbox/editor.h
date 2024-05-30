#pragma once

#include "resource.h"
#include "shape.h"

#define MY_SHAPE_ARRAY_SIZE 123

extern Shape* pcshape[];

class Editor
{
public:
	virtual ~Editor();
	virtual void OnLBdown(HWND) = 0;
	virtual void OnLBup(HWND) = 0;
	virtual void OnMouseMove(HWND) = 0;
	virtual void OnPaint(HWND) = 0;
};

class ShapeEditor : public Editor
{
protected:
	int pos = 0;
	bool isPainting = false;
public:
	ShapeEditor(); ~ShapeEditor();
	virtual void OnLBdown(HWND) = 0;
	virtual void OnMouseMove(HWND) = 0;
	void OnLBup(HWND);
	void OnPaint(HWND);
	virtual void OnInitMenuPopup(HWND, WPARAM) = 0;
	void IncPos(void);
	void UpdatePos(void);
	void ClearWindow(HWND);
	void CheckNum(void);
};