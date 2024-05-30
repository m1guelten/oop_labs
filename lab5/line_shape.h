#pragma once
#include "shape.h"
#include <string.h>
//using namespace std;

class LineShape :virtual public Shape {
public:
	virtual void Show(HDC,bool);
	void DrawRubberBand(HWND);
	Shape* copyShape();
//	wstring getObjName();
};