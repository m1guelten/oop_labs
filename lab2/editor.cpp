#include "framework.h"
#include "editor.h"

Shape * pcshape[MY_SHAPE_ARRAY_SIZE];

Editor::~Editor() {};
ShapeEditor::ShapeEditor() {};
ShapeEditor::~ShapeEditor() {};

void ShapeEditor::IncPos(void) { pos++; }

void ShapeEditor::CheckNum(void)				//перевіряємо аби наш pos не перебільшував розміри масиву
{ 
	if (pos == MY_SHAPE_ARRAY_SIZE) pos--;
}

void ShapeEditor::UpdatePos(void)				//оновлюємо pos для кожного об'єкта 
{ 
	for (int i = 0; i <= MY_SHAPE_ARRAY_SIZE; i++) 
	{
		if (!pcshape[i]) 
		{
			pos = i;
			return;
		}
	}
}

void ShapeEditor::OnLBup(HWND hWnd) 
{
	isPainting = false;
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);
	pcshape[pos]->SetEnd(pt.x, pt.y);
	IncPos();
	InvalidateRect(hWnd, NULL, TRUE);
};

void ShapeEditor::OnPaint(HWND hWnd) 
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < pos; i++)
		if (pcshape[i])
			pcshape[i]->Show(hdc);
	EndPaint(hWnd, &ps);
}

void ShapeEditor::ClearWindow(HWND hWnd)	//очистити вікно -> очистити масив 
{ 
	for (int i = 0; i < pos; i++) pcshape[i] = NULL;
	InvalidateRect(hWnd, NULL, TRUE);
}