#include "framework.h"
#include "my_editor.h"

//Shape* MyEditor::pcshape[shape_size];

int MyEditor::nCurrentIndex = 0;
Shape** MyEditor::pcshape = new Shape * [shape_size] {};

MyEditor::~MyEditor()
{
	delete[]pcshape;
}

void MyEditor::Start(Shape* shape)
{
	currShape = shape;
}

void MyEditor::OnLBdown(HWND hWnd)
{
	if (!currShape) return;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[nCurrentIndex] = currShape->copyShape();
	xstart = xend = pt.x;
	ystart = yend = pt.y;
	pcshape[nCurrentIndex]->Set(xstart, ystart, xend, yend);
}

void MyEditor::OnLBup(HWND hWnd)
{
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x;
	yend = pt.y;
	pcshape[nCurrentIndex]->Set(xstart, ystart, xend, yend);
	nCurrentIndex = (++nCurrentIndex) % shape_size;
	InvalidateRect(hWnd, NULL, TRUE);
	xstart = 0;
}

void MyEditor::OnMouseMove(HWND hWnd)
{
	if (!xstart) return;
	pcshape[nCurrentIndex]->DrawRubberBand(hWnd);
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	xend = pt.x;
	yend = pt.y;
	pcshape[nCurrentIndex]->Set(xstart, ystart, xend, yend);
	pcshape[nCurrentIndex]->DrawRubberBand(hWnd);
}

void MyEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < shape_size; i++)
		if (pcshape[i]) pcshape[i]->Show(hdc);
	EndPaint(hWnd, &ps);
}