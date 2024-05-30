#pragma once
#include "shape.h"
#include "toolbar.h"

#define shape_size 122

class MyEditor
{
private:
	static Shape** pcshape;
	static int nCurrentIndex;
	Shape* currShape;
	POINT pt;
	std::string wsName;
	int ystart, xend, yend;
	int xstart = 0;
public:
	virtual ~MyEditor();
	void Start(Shape*);
	void OnLBdown(HWND);
	void OnLBup(HWND,std::string);
	void OnMouseMove(HWND);
	void OnPaint(HWND,int);
	std::string getObjName();
	void setObjName(std::string);
	void RemoveItem(int);
};
